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
    const int segments = 30; // Nombre de segments pour dessiner le cercle
    for (int i = 0; i < segments; ++i) {
        float theta1 = static_cast<float>(i) / static_cast<float>(segments) * 2.0f * 3.1415926f;
        float theta2 = static_cast<float>(i + 1) / static_cast<float>(segments) * 2.0f * 3.1415926f;

        float x1 = m_Position.x + m_Radius * std::cos(theta1);
        float y1 = m_Position.z + m_Radius * std::sin(theta1);
        float x2 = m_Position.x + m_Radius * std::cos(theta2);
        float y2 = m_Position.z + m_Radius * std::sin(theta2);

        App::DrawLine(x1, y1, x2, y2, 1.0f, 1.0f, 0.0f); // Jaune
    }
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
}