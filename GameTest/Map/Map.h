#pragma once

#include "../App/app.h"
#include "../App/AppSettings.h"

class GameManager;

class Map
{

#pragma region VARIABLES
public : 
	App::Vector2 m_MinMaxPosZ = App::Vector2(HEIGHT_FLOOR_0, HEIGHT_FLOOR_1);

	GameManager* m_GameManager = nullptr;
	float m_SpeedMap;
	App::Vector2 m_Position;
	float m_Scale = 1.f;

	float m_Width = APP_VIRTUAL_WIDTH/1.25f;
	float m_Height = APP_VIRTUAL_HEIGHT;

#pragma endregion


#pragma region FUNCTIONS
public : 

Map(){m_SpeedMap = 10.f;};
Map(float Speed) : m_SpeedMap(Speed){}
~Map() {};

void SetGameManager(GameManager* gameManager) { m_GameManager = gameManager; }

virtual void Init() = 0;
virtual void Update(float deltaTime) = 0;
virtual void Render() = 0;
virtual void Destroy() = 0;
virtual void SetPosition(float newX, float newZ);

#pragma endregion


};

