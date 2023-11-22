#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#pragma once
#include <vector>

struct Vector2 {
    float x;
    float z;
};

struct Projection {
    float min;
    float max;
};



enum class ShapeType { Circle, Rectangle, Capsule };

class CollisionComponent
{

#pragma region VARIABLES
public : 

    bool m_bIsActivated = true;
    bool m_bDrawdebug = false;

    ShapeType m_ShapeType;
    Vector2 m_Position;

#pragma endregion


#pragma region FUNCTIONS

public :

    virtual ~CollisionComponent() {}

    bool IsColliding(const CollisionComponent& other) const;
    void SetPosition(const Vector2& position);

    virtual void DrawDebugCollision() const = 0;
    virtual std::vector<Vector2> GetAxes() const = 0;
    virtual Projection Project(const std::vector<Vector2>& axes) const = 0;

#pragma endregion


};

#endif // COLLISIONCOMPONENT_H
