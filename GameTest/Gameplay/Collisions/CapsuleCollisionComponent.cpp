#include "stdafx.h"
#include "CapsuleCollisionComponent.h"
#include "../App/app.h"
#include <cmath>

CapsuleCollisionComponent::CapsuleCollisionComponent(float radius, float length) : 
m_Circle1(radius), m_Circle2(radius), m_Rectangle((radius * 2.0f), (length)) 
{
  m_ShapeType = ShapeType::Capsule;
  m_RadiusCapsule = radius;
  m_LengthCapsule = length;
}

void CapsuleCollisionComponent::SetCapsule(float radius, float length) {
    m_Circle1.SetCircle(radius);
    m_Circle2.SetCircle(radius);
    m_Rectangle.SetRectangle(radius * 2.0f, length);
}


std::vector<App::Vector2> CapsuleCollisionComponent::GetAxes() const
{
    std::vector<App::Vector2> axes;

    std::vector<App::Vector2> circleAxes1 = m_Circle1.GetAxes();
    std::vector<App::Vector2> circleAxes2 = m_Circle2.GetAxes();
    std::vector<App::Vector2> rectangleAxes = m_Rectangle.GetAxes();

    axes.insert(axes.end(), circleAxes1.begin(), circleAxes1.end());
    axes.insert(axes.end(), circleAxes2.begin(), circleAxes2.end());
    axes.insert(axes.end(), rectangleAxes.begin(), rectangleAxes.end());

    return axes;
}


Projection CapsuleCollisionComponent::Project(const std::vector<App::Vector2>& axes) const
{
    Projection projection1 = m_Circle1.Project(axes);
    Projection projection2 = m_Circle2.Project(axes);
    Projection projection3 = m_Rectangle.Project(axes);

    Projection projection;
    projection.min = fmin(projection1.min, fmin(projection2.min, projection3.min));
    projection.max = fmax(projection1.max, fmax(projection2.max, projection3.max));

    return projection;
}
#pragma region DrawDebug

// Fonction principale pour dessiner la forme de collision en fonction du type de forme
void CapsuleCollisionComponent::DrawDebugCollision() const 
{
    m_Circle1.DrawDebugCollision();
    m_Circle2.DrawDebugCollision();
    m_Rectangle.DrawDebugCollision();
}

void CapsuleCollisionComponent::SetPosition(const float x, const float z)
{
    m_Circle1.SetPosition(x,z-m_LengthCapsule/2);
    m_Circle2.SetPosition(x,z+m_LengthCapsule / 2);
    m_Rectangle.SetPosition(x,z);
}
