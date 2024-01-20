#pragma once

//------------------------------------------------------------------------
#include "../App/app.h"
#include "../App/AppSettings.h"
#include "../Player/Player.h"
#include "../Map/MapManager.h"
#include "../HUD/LifeHUD.h"
#include "../HUD/ScoreHUD.h"

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
enum EGameState 
{
	PreStart, 
	Started,
	GameOver,
	WaitingForRestart
};


class GameManager
{

#pragma region VARIABLES

public : 

	EGameState m_GameState = PreStart;

	// Map
	MapManager* m_MapManager = nullptr;
	float m_SpeedMap = -350.f;
	float m_HeightMap = APP_VIRTUAL_HEIGHT;
	float m_WidthMap = APP_VIRTUAL_WIDTH / 1.25f;

	// Player
	Player* m_Player = nullptr;

	// Game Data
	int m_Score = 0;
	float m_GameTime = 0.f;
	int m_DistanceReached = 0;
	int m_KillBonus = 0;
	int m_MalusScore = 0;

	LifeHUD* m_LifeHUD;
	ScoreHUD* m_ScoreHUD;

	float m_SpeedMulti = 1.f;
 private : 
	float m_InitialSpeedMulti = 1.f;
	float m_AdditionalSpeedMulti = 0.3f;
	float m_StepSpeedMulti =  1000.0;
	float m_MaxMultiSpeed = 2.6;

	//Runtime
	bool m_bAskForGameOver = false;
	float m_DurationBeforeGameOver = 1.f;
	float m_CurrentDurationGameOver = 0.f;

#pragma endregion


#pragma region FUNCTIONS
public : 
	GameManager();

	void Init();
	void Update(float DeltaTime);
	void UpdatePreStart(float DeltaTime);
	void UpdateStarted(float DeltaTime);
	void UpdateGameOver(float DeltaTime);
	void UpdateWaitingForRestart(float DeltaTime);
	void Render();
	void Shutdown();


	void StartGame();
	void AskGameOver() {m_bAskForGameOver = true; m_CurrentDurationGameOver = 0.f;};
	void GameOver();
	void Restart(bool m_bFirstTime);

#pragma endregion

};

