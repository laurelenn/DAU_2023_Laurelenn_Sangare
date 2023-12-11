#pragma once
#include <vector>
#include "CollisionComponent.h"

class CapsuleCollisionComponent;
class CircleCollisionComponent;

class RectangleCollisionComponent :
public CollisionComponent
{

#pragma region VARIABLES
public:

App::Vector2 m_RectSize;

#pragma endregion


#pragma region FUNCTIONS

    RectangleCollisionComponent(float width, float height);
    void SetRectangle(float width, float height);
    std::vector<App::Vector2> GetAxes() const override;
    void DrawDebugCollision() const override;
    void SetPosition(const float x, const float z) override;

    bool IsColliding(const RectangleCollisionComponent& other) const;
    bool IsColliding(const CapsuleCollisionComponent& other) const;
    bool IsColliding(const CircleCollisionComponent& other) const;
#pragma endregion


};