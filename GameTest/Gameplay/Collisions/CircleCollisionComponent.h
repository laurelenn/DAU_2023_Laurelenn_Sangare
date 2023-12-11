#pragma once
#include <vector>
#include "CollisionComponent.h"

class CapsuleCollisionComponent;
class CircleCollisionComponent;

class CircleCollisionComponent :
public CollisionComponent
{

#pragma region VARIABLES

public : 
float m_Radius;

#pragma endregion


#pragma region FUNCTIONS

    CircleCollisionComponent(float radius);
    void SetCircle(float radius);
    std::vector<App::Vector2> GetAxes() const override;
   void DrawDebugCollision() const override;
   void SetPosition(const float x, const float z) override;

   bool IsColliding(const RectangleCollisionComponent& other) const;
   bool IsColliding(const CapsuleCollisionComponent& other) const;
   bool IsColliding(const CircleCollisionComponent& other) const;
#pragma endregion


};