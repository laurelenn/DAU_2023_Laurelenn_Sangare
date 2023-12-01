#pragma once

#include "../App/app.h"

class Map
{

#pragma region VARIABLES
public : 
float m_SpeedMap;
App::Vector2 m_Position;
float m_Scale = 1.f;
#pragma endregion


#pragma region FUNCTIONS
public : 

Map(){m_SpeedMap = 10.f;};
Map(float Speed) : m_SpeedMap(Speed){}
~Map() {};

virtual void Init() = 0;
virtual void Update(float deltaTime) = 0;
virtual void Render() = 0;
virtual void Destroy() = 0;
virtual void SetPosition(float newX, float newZ);

#pragma endregion


};

