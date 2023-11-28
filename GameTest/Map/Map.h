#pragma once

#include "../App/app.h"

class Map
{

#pragma region VARIABLES
public : 
float m_SpeedMap;
App::Vector2 m_Position;
#pragma endregion


#pragma region FUNCTIONS
public : 

Map(){m_SpeedMap = 10.f;};
Map(float Speed) : m_SpeedMap(Speed){}
~Map() {};

virtual void Init() const = 0;
virtual void Update(float deltaTime) const = 0;
virtual void Render() const = 0;
virtual void Destroy() const = 0;
void SetPosition(float newX, float newZ);

#pragma endregion


};

