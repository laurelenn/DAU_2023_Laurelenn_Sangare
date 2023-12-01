#pragma once
#include <vector>
#include "CollisionComponent.h"


class RectangleCollisionComponent :
public CollisionComponent
{

#pragma region VARIABLES

App::Vector2 m_RectSize;

#pragma endregion


#pragma region FUNCTIONS

public :

    RectangleCollisionComponent(float width, float height);
    void SetRectangle(float width, float height);
    std::vector<App::Vector2> GetAxes() const override;
    Projection Project(const std::vector<App::Vector2>& axes) const override;
    void DrawDebugCollision() const override;
    void SetPosition(const float x, const float z) override;
#pragma endregion


};