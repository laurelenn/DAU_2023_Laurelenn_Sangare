#include "stdafx.h"
#include "RectangleCollisionComponent.h"
#include "CircleCollisionComponent.h"
#include "CapsuleCollisionComponent.h"
#include "../App/app.h"
#include <cmath>

RectangleCollisionComponent::RectangleCollisionComponent(float width, float height)
{
    m_ShapeType = ShapeType::Rectangle;
    m_RectSize.x = width;
    m_RectSize.z = height;
}

void RectangleCollisionComponent::SetRectangle(float width, float height) 
{
    m_RectSize.x = width;
    m_RectSize.z = height;
}

std::vector<App::Vector2> RectangleCollisionComponent::GetAxes() const
{
    return { {1.0f, 0.0f}, {0.0f, 1.0f} };
}

#pragma region DrawDebug

// Fonction principale pour dessiner la forme de collision en fonction du type de forme
void RectangleCollisionComponent::DrawDebugCollision() const 
{
    float halfWidth = m_RectSize.x * 0.5f;
    float halfHeight = m_RectSize.z * 0.5f;
    App::DrawLine(m_Position.x - halfWidth, m_Position.z - halfHeight, m_Position.x + halfWidth, m_Position.z - halfHeight, 1.0f, 1.0f, 0.0f); // Jaune
    App::DrawLine(m_Position.x + halfWidth, m_Position.z - halfHeight, m_Position.x + halfWidth, m_Position.z + halfHeight, 1.0f, 1.0f, 0.0f); // Jaune
    App::DrawLine(m_Position.x + halfWidth, m_Position.z + halfHeight, m_Position.x - halfWidth, m_Position.z + halfHeight, 1.0f, 1.0f, 0.0f); // Jaune
    App::DrawLine(m_Position.x - halfWidth, m_Position.z + halfHeight, m_Position.x - halfWidth, m_Position.z - halfHeight, 1.0f, 1.0f, 0.0f); // Jaune
}

void RectangleCollisionComponent::SetPosition(const float x, const float z)
{
    CollisionComponent::SetPosition(x, z);
}

bool RectangleCollisionComponent::IsColliding(const RectangleCollisionComponent& other) const
{
    if (&other)
    {
        float leftA = m_Position.x - m_RectSize.x * 0.5f;
        float rightA = m_Position.x + m_RectSize.x * 0.5f;
        float topA = m_Position.z - m_RectSize.z * 0.5f;
        float bottomA = m_Position.z + m_RectSize.z * 0.5f;

        float leftB = other.m_Position.x - other.m_RectSize.x * 0.5f;
        float rightB = other.m_Position.x + other.m_RectSize.x * 0.5f;
        float topB = other.m_Position.z - other.m_RectSize.z * 0.5f;
        float bottomB = other.m_Position.z + other.m_RectSize.z * 0.5f;

        // Vérification de la collision selon les limites des AABB
        return !(rightA < leftB || leftA > rightB || bottomA < topB || topA > bottomB);
    } 
    return false;
}

bool RectangleCollisionComponent::IsColliding(const CapsuleCollisionComponent& other) const
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

bool RectangleCollisionComponent::IsColliding(const CircleCollisionComponent& other) const
{
    if (&other)
    {
        float closestX = CLAMP(other.m_Position.x, m_Position.x - m_RectSize.x * 0.5f, m_Position.x + m_RectSize.x * 0.5f);
        float closestY = CLAMP(other.m_Position.z, m_Position.z - m_RectSize.z * 0.5f, m_Position.z + m_RectSize.z * 0.5f);

        float distanceX = other.m_Position.x - closestX;
        float distanceY = other.m_Position.z - closestY;

        float distanceSquared = distanceX * distanceX + distanceY * distanceY;

        return distanceSquared < (other.m_Radius * other.m_Radius);
    }
    return false;
}

