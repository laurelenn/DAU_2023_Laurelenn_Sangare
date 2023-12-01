#pragma once
#include <vector>
#include "CollisionComponent.h"


class CircleCollisionComponent :
public CollisionComponent
{

#pragma region VARIABLES

// Circle
float m_Radius;

#pragma endregion


#pragma region FUNCTIONS

public :

    CircleCollisionComponent(float radius);
    void SetCircle(float radius);
    std::vector<App::Vector2> GetAxes() const override;
    Projection Project(const std::vector<App::Vector2>& axes) const override;
   void DrawDebugCollision() const override;
   void SetPosition(const float x, const float z) override;

  
#pragma endregion


};