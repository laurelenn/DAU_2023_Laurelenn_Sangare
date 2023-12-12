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
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void GameManager::Update(float deltaTime)
{
	// if (!m_bGameOver)
	//{

	
		if (m_Player && m_MapManager)
		{
			m_Player->Update(deltaTime);
			m_MapManager->Update(deltaTime);
		}
	//}
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
		m_MapManager->Render();
		m_Player->Render();
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

void GameManager::GameOver()
{
	m_GameState = EGameState::GameOver;
}
