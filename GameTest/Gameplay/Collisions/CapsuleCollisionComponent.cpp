#include "stdafx.h"
#include "RectangleCollisionComponent.h"
#include "CircleCollisionComponent.h"
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


bool CapsuleCollisionComponent::IsColliding(const RectangleCollisionComponent& other) const
{
    if (&other)
    {
        return other.IsColliding(*this);
    }
    return false;
}

bool CapsuleCollisionComponent::IsColliding(const CapsuleCollisionComponent& other) const
{
    if (&other)
    {
        if (m_Rectangle.IsColliding(other.m_Rectangle) 
            || m_Rectangle.IsColliding(other.m_Circle1) 
            || m_Rectangle.IsColliding(other.m_Circle2)) 
        {
            return true;
        }

        if (m_Circle1.IsColliding(other.m_Rectangle)
            || m_Circle1.IsColliding(other.m_Circle1)
            || m_Circle1.IsColliding(other.m_Circle2)) 
        {
            return true;
        }

        if (m_Circle2.IsColliding(other.m_Rectangle)
            || m_Circle2.IsColliding(other.m_Circle1)
            || m_Circle2.IsColliding(other.m_Circle2)) 
        {
            return true; 
        }
    }
    return false;
}

bool CapsuleCollisionComponent::IsColliding(const CircleCollisionComponent& other) const
{
    if (&other)
    {
        return other.IsColliding(*this);
    }
    return false;
}