#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#pragma once
#include "../App/app.h"
#include <vector>

class GameObject;
class CircleCollisionComponent;
class RectangleCollisionComponent;
class CapsuleCollisionComponent;

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
    App::Vector2 m_Position;
    GameObject* m_Owner;

#pragma endregion


#pragma region FUNCTIONS

public :

    virtual ~CollisionComponent() {}

    void SetPosition(const App::Vector2& position);
    void SetOwner(GameObject* owner){m_Owner = owner;}
    virtual void SetPosition(const float x, const float z);

    virtual void DrawDebugCollision() const = 0;
    virtual std::vector<App::Vector2> GetAxes() const = 0;


    virtual bool IsColliding(const CircleCollisionComponent& other) const = 0;
    virtual bool IsColliding(const RectangleCollisionComponent& other) const = 0;
    virtual bool IsColliding(const CapsuleCollisionComponent& other) const = 0;

#pragma endregion


};

#endif // COLLISIONCOMPONENT_H
