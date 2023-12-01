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

class GameManager
{

#pragma region VARIABLES
	float m_SpeedMap = -500.f;
	float m_HeightMap = APP_VIRTUAL_HEIGHT;
	float m_WidthMap = APP_VIRTUAL_WIDTH / 1.25f;

	Player* m_Player = nullptr;
	MapManager* m_MapManager = nullptr;
	// InputManager* m_InputManager = nullptr;
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

