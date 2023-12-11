#include "stdafx.h"
#include "CollisionComponent.h"
#include "../App/app.h"
#include <cmath>


void CollisionComponent::SetPosition(const App::Vector2& position)
{
    m_Position = position;
}

void CollisionComponent::SetPosition(const float x, const float z) 
{
    m_Position.x = x;
    m_Position.z = z;
}
