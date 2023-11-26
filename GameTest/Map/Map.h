#pragma once
class Map
{

#pragma region VARIABLES
public : 
float m_SpeedMap;
#pragma endregion


#pragma region FUNCTIONS
public : 

Map(float Speed) : m_SpeedMap(Speed){}
~Map() {};

virtual void Init() const = 0;
virtual void Update(float deltaTime) const = 0;
virtual void Render() const = 0;
virtual void Destroy() const = 0;

#pragma endregion


};

