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



class GameManager
{

#pragma region VARIABLES

public : 
	// Map
	MapManager* m_MapManager = nullptr;
	float m_SpeedMap = -300.f;
	float m_HeightMap = APP_VIRTUAL_HEIGHT;
	float m_WidthMap = APP_VIRTUAL_WIDTH / 1.25f;


	// Player
	Player* m_Player = nullptr;
	bool m_bGameOver = false;

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

	void GameOver();
#pragma endregion

};

