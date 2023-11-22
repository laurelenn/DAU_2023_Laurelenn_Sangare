#include "stdafx.h"
#include "CircleCollisionComponent.h"
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


Projection CircleCollisionComponent::Project(const std::vector<App::Vector2>& axes) const
{
    Projection projection;
    float positionOnAxis = m_Position.x * axes[0].x + m_Position.z * axes[0].z;
    projection.min = positionOnAxis - m_Radius;
    projection.max = positionOnAxis + m_Radius;
    return projection;

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