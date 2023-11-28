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
	m_Player = new Player(100, 100.f, 50.f);
	m_Player->SetActivated(true); // To change
	m_Player->m_SpriteColumns = 7;
	m_Player->m_SpriteLines = 3;
	m_Player->m_SpriteFilename = ".\\Ressources\\Player\\p1_spritesheet.png";
	m_Player->Init(App::Vector2(100.f, 100.f));

#pragma endregion

#pragma region Map
	m_MapManager = new MapManager(m_HeightMap, m_WidthMap, m_SpeedMap);

#pragma endregion
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void GameManager::Update(float deltaTime)
{
	m_Player->Update(deltaTime);
	m_MapManager->Update(deltaTime);

}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void GameManager::Render()
{
	m_Player->Render();
	m_MapManager->Render();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void GameManager::Shutdown()
{
	m_Player->Destroy();
	m_MapManager->Destroy();
}