#include "stdafx.h"
#include "RectangleCollisionComponent.h"
#include "CircleCollisionComponent.h"
#include "CapsuleCollisionComponent.h"
#include "../App/app.h"
#include <cmath>

CircleCollisionComponent::CircleCollisionComponent(float radius) : m_Radius(radius) {m_ShapeType = ShapeType::Circle;}

void CircleCollisionComponent::SetCircle(float radius) {
    m_Radius = radius;
}


std::vector<App::Vector2> CircleCollisionComponent::GetAxes() const
{
    return { {1.0f, 0.0f}, {0.0f, 1.0f} };
}


#pragma region DrawDebug

// Fonction principale pour dessiner la forme de collision en fonction du type de forme
void CircleCollisionComponent::DrawDebugCollision() const 
{
    App::DrawCircle(30, m_Radius, m_Position, 1.0f, 1.0f, 0.0f); 
}

void CircleCollisionComponent::SetPosition(const float x, const float z)
{
    CollisionComponent::SetPosition(x,z);
}


bool CircleCollisionComponent::IsColliding(const RectangleCollisionComponent& other) const
{
    if (&other)
    {
        return other.IsColliding(*this);
    }
    return false;
}

bool CircleCollisionComponent::IsColliding(const CapsuleCollisionComponent& other) const
{
    if (&other)
    {
        if (IsColliding(other.m_Rectangle)) {
            return true;
        }

        if (IsColliding(other.m_Circle1) || IsColliding(other.m_Circle2)) {
            return true;
        }
    }
    return false;
}

bool CircleCollisionComponent::IsColliding(const CircleCollisionComponent& other) const
{
    if (&other)
    {
        float distanceX = m_Position.x - other.m_Position.x;
        float distanceY = m_Position.z - other.m_Position.z;

        float distanceSquared = distanceX * distanceX + distanceY * distanceY;
        float sumRadius = m_Radius + other.m_Radius;

        return distanceSquared < (sumRadius * sumRadius);
    }
    return false;
}