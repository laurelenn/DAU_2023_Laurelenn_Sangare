#pragma once
#include <vector>
#include "CollisionComponent.h"
#include "CircleCollisionComponent.h"
#include "RectangleCollisionComponent.h"


class CapsuleCollisionComponent :
public CollisionComponent
{

#pragma region VARIABLES

float m_RadiusCapsule;
float m_LengthCapsule;

CircleCollisionComponent m_Circle1;
CircleCollisionComponent m_Circle2;
RectangleCollisionComponent m_Rectangle;

#pragma endregion


#pragma region FUNCTIONS

public :

    CapsuleCollisionComponent(float radius, float length);
    void SetCapsule(float radius, float height);
    std::vector<App::Vector2> GetAxes() const override;
    Projection Project(const std::vector<App::Vector2>& axes) const override;
    void DrawDebugCollision() const override;
    void CapsuleCollisionComponent::SetPosition(const float x, const float z) override;
#pragma endregion


};