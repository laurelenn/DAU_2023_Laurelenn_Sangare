#include "stdafx.h"
#include "RectangleCollisionComponent.h"
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


Projection RectangleCollisionComponent::Project(const std::vector<App::Vector2>& axes) const
{
    Projection projection;
    float halfWidth = m_RectSize.x * 0.5f;
    float halfHeight = m_RectSize.z * 0.5f;
    App::Vector2 points[4] = {
        {m_Position.x - halfWidth, m_Position.z - halfHeight},
        {m_Position.x + halfWidth, m_Position.z - halfHeight},
        {m_Position.x - halfWidth, m_Position.z + halfHeight},
        {m_Position.x + halfWidth, m_Position.z + halfHeight}
    };

    projection.min = projection.max = points[0].x * axes[0].x + points[0].z * axes[0].z;
    for (size_t i = 1; i < 4; ++i) {
        float dotProduct = points[i].x * axes[0].x + points[i].z * axes[0].z;
        if (dotProduct < projection.min) {
            projection.min = dotProduct;
        }
        else if (dotProduct > projection.max) {
            projection.max = dotProduct;
        }
    }

    return projection;

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