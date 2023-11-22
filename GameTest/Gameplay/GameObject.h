#pragma once
#include "../App/SimpleSprite.h"
#include "../App/app.h"
#include "../Gameplay/Collisions/CollisionComponent.h"

#include <iostream>
#include <memory>

class GameObject
{

#pragma region VARIABLES
App::Vector2 m_Location;
float m_SpeedX;
float m_SpeedZ;
CSimpleSprite m_Sprite;
std::unique_ptr<CollisionComponent> m_Collision;

#pragma endregion

#pragma region FUNCTIONS

public :
virtual ~GameObject() {};

virtual void Init() = 0;
virtual void Update(float Deltatime) = 0; // To do : Not virtual --> Update position with speed
virtual void Render() = 0;
virtual void Destroy() = 0;


void SetPosition(float x, float z);

#pragma endregion

};

