#pragma once

//------------------------------------------------------------------------
#include "../App/app.h"
#include "../App/AppSettings.h"
#include "../Player/Player.h"
#include "../Map/MapManager.h"
//#include "../InputManager.h"
//#include "../HUD/LifeHUD.h"
//#include "../HUD/ScoreHUD.h"
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

#define HEIGHT_FLOOR_0      (100.f);
#define HEIGHT_FLOOR_1      (200.f);
#define HEIGHT_FLOOR_CAVE   (100.f);



class GameManager
{

#pragma region VARIABLES

	// Map
	MapManager* m_MapManager = nullptr;
	float m_SpeedMap = -400.f;
	float m_HeightMap = APP_VIRTUAL_HEIGHT;
	float m_WidthMap = APP_VIRTUAL_WIDTH / 1.25f;


	// Player
	Player* m_Player = nullptr;
	float m_ScalePlayer = 1.5f;
	// InputManager* m_InputManager = nullptr;

	// Game Data
	int m_Score;
	float m_GameTime;
	int m_DistanceReached;

// LifeHUD* m_LifeHUD; // To do 
// ScoreHUD* m_ScoreHUD; // To do
#pragma endregion


#pragma region FUNCTIONS
public : 
	GameManager();

	void Init();
	void Update(float DeltaTime);
	void Render();
	void Shutdown();
#pragma endregion

};

