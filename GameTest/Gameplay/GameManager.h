#pragma once

//------------------------------------------------------------------------
#include "../Player/Player.h"
#include "../Map/MapManager.h"
//#include "../InputManager.h"
//#include "../HUD/LifeHUD.h"
//#include "../HUD/ScoreHUD.h"
//------------------------------------------------------------------------

class GameManager
{

#pragma region VARIABLES
	float m_SpeedMap = 50.f;
	int m_HeightMap = 100.f; // To do 
	int m_WidthMap = 100.f; // To do

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

