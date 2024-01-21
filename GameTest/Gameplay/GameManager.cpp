#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
{

}

// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void GameManager::Init()
{
#pragma region Player
	m_Player = new Player(100, PLAYER_SCALE); // Initialize player
	if (m_Player)
	{
		m_Player->SetGameManager(this);
		m_Player->Init(App::Vector2(APP_VIRTUAL_WIDTH - APP_VIRTUAL_WIDTH/1.25f, HEIGHT_FLOOR_0));
	}
	
#pragma endregion

#pragma region Map
	m_MapManager = new MapManager(m_HeightMap, m_WidthMap, m_SpeedMap, APP_VIRTUAL_SCALE);

	if (m_MapManager)
	{
		m_MapManager->SetGameManager(this);
		m_MapManager->Init();
	}
#pragma endregion

#pragma region Life

	m_LifeHUD = new LifeHUD(0.8f, 0.8f, m_Player->m_LifeManager->m_InitialLife, 50.0f, (APP_VIRTUAL_HEIGHT + 200.f) * APP_VIRTUAL_SCALE);
	if (m_LifeHUD)
	{
		m_LifeHUD->Init();
	
#pragma endregion

#pragma region Score
		m_GameTime = 0.0f;
		m_DistanceReached = 0;
		m_KillBonus = 0;
		m_Score = 0;
		m_MalusScore = 0;

		m_ScoreHUD = new ScoreHUD(0.8f, 0.8f, m_LifeHUD->GetPosGaugeX(), (APP_VIRTUAL_HEIGHT + 100.f) * APP_VIRTUAL_SCALE);
		if (m_ScoreHUD)
		{
			m_ScoreHUD->Init();
		}
	}
	#pragma endregion

	m_SpeedMulti = m_InitialSpeedMulti;
	ChangeGameState(EGameState::Started);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void GameManager::Update(float deltaTime)
{
	switch (m_GameState)
	{
		case  EGameState::PreStart:
			UpdatePreStart(deltaTime);
		break;

		default:
		case  EGameState::Started:
			UpdateStarted(deltaTime);
		break;

		case  EGameState::GameOver:
			UpdateGameOver(deltaTime);
		break;

		case  EGameState::WaitingForRestart:
			UpdateWaitingForRestart(deltaTime);
		break;
	}
}

void GameManager::UpdatePreStart(float DeltaTime)
{
}

void GameManager::UpdateStarted(float DeltaTime)
{

	if (m_Player && m_MapManager)
	{
		m_Player->Update(DeltaTime);
		m_MapManager->Update(DeltaTime);
	}

	if (m_ScoreHUD)
	{
		m_GameTime += DeltaTime;
		m_DistanceReached = -1.f * m_GameTime * 0.0001f * m_SpeedMap;
		m_Score = CLAMP(m_DistanceReached + m_KillBonus - m_MalusScore, 0, 9999999);
		m_ScoreHUD->Update(m_Score);
	}


	m_SpeedMulti = CLAMP(m_InitialSpeedMulti, m_InitialSpeedMulti + (m_AdditionalSpeedMulti * (int)(m_DistanceReached / m_StepSpeedMulti)), m_MaxMultiSpeed);

	if (m_LifeHUD && m_Player && m_Player->m_LifeManager)
	{
		m_LifeHUD->Update(m_Player->m_LifeManager->m_CurrentLife);
	}

	if (m_bAskForGameOver)
	{
		m_CurrentDurationGameOver+=DeltaTime/1000.f;
		if (m_CurrentDurationGameOver >= m_DurationBeforeGameOver)
		{
			GameOver();
		}
	}
}

void GameManager::UpdateGameOver(float DeltaTime)
{

}

void GameManager::UpdateWaitingForRestart(float DeltaTime)
{
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void GameManager::Render()
{
	// To do : Use Game States

	if (m_Player && m_MapManager)
	{
		m_MapManager->RenderBg();
		m_MapManager->RenderGD();
		m_Player->Render();
		m_MapManager->RenderLD();
	}

	if (m_ScoreHUD)
	{
		m_ScoreHUD->Render();
	}

	if (m_LifeHUD)
	{
		m_LifeHUD->Render();
	}

	if (m_GameState == EGameState::GameOver)
	{
		char textBuffer[64];
		sprintf(textBuffer, "GAME OVER");
		App::Print(APP_VIRTUAL_WIDTH /2, APP_VIRTUAL_HEIGHT /2, textBuffer, 1.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18);
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void GameManager::Shutdown()
{
	if (m_Player && m_MapManager)
	{
		m_Player->Destroy();
		m_MapManager->Destroy();
	}
}

void GameManager::ChangeGameState(EGameState state)
{
	switch (state) 
	{
		case (EGameState::PreStart) :
			if (m_GameState == EGameState::WaitingForRestart)
			{
				m_GameState = state;
			}
		break;

		case(EGameState::Started) : 
			if (m_GameState == EGameState::PreStart)
			{
				App::PlaySound(".\\.\\Ressources\\Sounds\\Music1.wav", true);
				m_GameState = state;
			}
		break;
		case(EGameState::GameOver):
			if (m_GameState == EGameState::Started)
			{
				App::StopSound(".\\.\\Ressources\\Sounds\\Music1.wav");
				App::PlaySound(".\\.\\Ressources\\Sounds\\GameOver.wav", false);
				m_GameState = state;
			}
			break;
		case(EGameState::WaitingForRestart):
			if (m_GameState == EGameState::GameOver)
			{
				m_GameState = state;
			}
			break;
	}
}

void GameManager::StartGame()
{
}

void GameManager::GameOver()
{
	ChangeGameState(EGameState::GameOver);
}

void GameManager::Restart(bool m_bFirstTime)
{
}
