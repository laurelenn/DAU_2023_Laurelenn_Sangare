#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
{

}

// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void GameManager::Init()
{
	PreStart();
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
	if (App::IsKeyPressed(VK_LBUTTON))
	{
		ChangeGameState(Started);
	}

	if (m_SpritePreStart)
	{
		m_SpritePreStart->Update(DeltaTime);
	}
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
			ChangeGameState(EGameState::GameOver);
			m_CurrentDurationGameOver = 0.f;
		}
	}
}

void GameManager::UpdateGameOver(float DeltaTime)
{
	m_CurrentDurationWaitRestart += DeltaTime/1000.f;
	if (m_CurrentDurationWaitRestart >= m_DurationBeforeWaitRestart)
	{
		ChangeGameState(WaitingForRestart);
	}
	if (m_SpriteGameOver)
	{
		m_SpriteGameOver->Update(DeltaTime);
	}
}

void GameManager::UpdateWaitingForRestart(float DeltaTime)
{
	if (App::IsKeyPressed(VK_SPACE))
	{
		AskRestart();
	}

	if (m_SpriteWaitRestart)
	{
		m_SpriteWaitRestart->Update(DeltaTime);
	}
}

void GameManager::Render()
{
	switch (m_GameState)
	{
		case(EGameState::PreStart):
			if (m_MapManager)
			{
				m_MapManager->RenderBg();
			}
			if (m_SpritePreStart)
			{
				m_SpritePreStart->Draw();
			}

			//Credits 

			char textLaulau[64];
			char textUbi[64];

			sprintf(textLaulau, "Created by : (c) Laurelenn Sangare - 2023-2024");
			sprintf(textUbi, "Thanks to : Ronan Bel, DAU Team");

			App::Print(APP_VIRTUAL_WIDTH*0.05f, APP_VIRTUAL_HEIGHT /20.f, textLaulau, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_12);
			App::Print(APP_VIRTUAL_WIDTH * 0.85f, APP_VIRTUAL_HEIGHT/20.f, textUbi, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_12);
			break;

		case(EGameState::Started):
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
			break;

		case(EGameState::GameOver):
			if (m_MapManager)
			{
				m_MapManager->RenderBg();
			}
			if (m_SpriteGameOver)
			{
				m_SpriteGameOver->Draw();
			}
			break;

		case(EGameState::WaitingForRestart):
			if (m_MapManager)
			{
				m_MapManager->RenderBg();
				if (m_SpriteWaitRestart)
				{
					m_SpriteWaitRestart->Draw();
				}

				char textScore[64];
				char textDistance[64];
				char textBonus[64];
				char textMalus[64];

				sprintf(textScore, "%d", m_Score);
				sprintf(textDistance, "%dm", m_DistanceReached);
				sprintf(textBonus, "%d", m_KillBonus);
				sprintf(textMalus, "-%d", m_MalusScore);
				
				App::Print(APP_VIRTUAL_WIDTH /	2.05f, APP_VIRTUAL_HEIGHT / 2.28f, textScore, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
				App::Print(APP_VIRTUAL_WIDTH / 2.05f, APP_VIRTUAL_HEIGHT / 2.85f, textDistance, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
				App::Print(APP_VIRTUAL_WIDTH / 2.05f, APP_VIRTUAL_HEIGHT / 3.6f, textBonus, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
				App::Print(APP_VIRTUAL_WIDTH / 2.05f, APP_VIRTUAL_HEIGHT / 5.f, textMalus, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);


				//Credits 

				char textLaulau[64];
				char textUbi[64];

				sprintf(textLaulau, "Created by : (c) Laurelenn Sangare - 2023-2024");
				sprintf(textUbi, "Thanks to : Ronan Bel, DAU Team");

				App::Print(APP_VIRTUAL_WIDTH * 0.05f, APP_VIRTUAL_HEIGHT / 20.f, textLaulau, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_12);
				App::Print(APP_VIRTUAL_WIDTH * 0.85f, APP_VIRTUAL_HEIGHT / 20.f, textUbi, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_12);
			}
			break;
	}
}

void GameManager::Shutdown()
{
	if (m_Player)
	{
		m_Player->Destroy();
		delete m_Player;
		m_Player = nullptr;
	}

	if (m_LifeHUD)
	{
		m_LifeHUD->Destroy();
		delete m_LifeHUD;
		m_LifeHUD = nullptr;
	}

	if (m_ScoreHUD)
	{
		m_ScoreHUD->Destroy();
		delete m_ScoreHUD;
		m_ScoreHUD = nullptr;
	}

	if (m_MapManager)
	{
		m_MapManager->Destroy();
		delete m_MapManager;
		m_MapManager = nullptr;

	}

	if (m_SpritePreStart)
	{
		delete m_SpritePreStart;
		m_SpritePreStart = nullptr;
	}

	if (m_SpriteGameOver)
	{
		delete m_SpriteGameOver;
		m_SpriteGameOver = nullptr;
	}

	if (m_SpriteWaitRestart)
	{
		delete m_SpriteWaitRestart;
		m_SpriteWaitRestart = nullptr;
	}
}

void GameManager::ChangeGameState(EGameState state)
{
	switch (state) 
	{
		case (EGameState::PreStart) :
			if (m_GameState == EGameState::WaitingForRestart)
			{
				PreStart();
				m_GameState = state;
			}
		break;

		case(EGameState::Started) : 
			if (m_GameState == EGameState::PreStart)
			{
				StartGame();
				m_GameState = state;
			}
		break;

		case(EGameState::GameOver):
			if (m_GameState == EGameState::Started)
			{
				GameOver();
				m_GameState = state;
			}
			break;

		case(EGameState::WaitingForRestart):
			if (m_GameState == EGameState::GameOver)
			{
				WaitRestart();
				m_GameState = state;
			}
			break;
	}
}

void GameManager::PreStart()
{

#pragma region Sprites

	//PreStart
	m_SpritePreStart = App::CreateSprite(".\\.\\Ressources\\PreStart.png", 1, 1);
	m_SpritePreStart->CreateAnimation(0,  1.f, {0});
	m_SpritePreStart->SetScale(0.75f);
	m_SpritePreStart->SetAnimation(0);
	m_SpritePreStart->SetPosition(APP_VIRTUAL_WIDTH/2.f, APP_VIRTUAL_HEIGHT/2.f);



	// GameOver
	m_SpriteGameOver = App::CreateSprite(".\\.\\Ressources\\GameOver.png", 1, 1);
	m_SpriteGameOver->CreateAnimation(0, 1.f, { 0 });
	m_SpriteGameOver->SetScale(0.75f);
	m_SpriteGameOver->SetAnimation(0);
	m_SpriteGameOver->SetPosition(APP_VIRTUAL_WIDTH / 2.f, APP_VIRTUAL_HEIGHT / 2.f);

	// GameOver
	m_SpriteWaitRestart = App::CreateSprite(".\\.\\Ressources\\WaitRestart.png", 1, 1);
	m_SpriteWaitRestart->CreateAnimation(0, 1.f, { 0 });
	m_SpriteWaitRestart->SetScale(0.75f);
	m_SpriteWaitRestart->SetAnimation(0);
	m_SpriteWaitRestart->SetPosition(APP_VIRTUAL_WIDTH / 2.f, APP_VIRTUAL_HEIGHT / 2.f);
#pragma endregion
#pragma endregion


#pragma region Reinit
	// Reinit values
	m_SpeedMulti = m_InitialSpeedMulti;

	m_CurrentDurationWaitRestart = 0.f;
	m_CurrentDurationGameOver = 0.f;
	m_bAskForGameOver = false;

#pragma endregion

#pragma region Player
	m_Player = new Player(100, PLAYER_SCALE); // Initialize player
	if (m_Player)
	{
		m_Player->SetGameManager(this);
		m_Player->Init(App::Vector2(APP_VIRTUAL_WIDTH - APP_VIRTUAL_WIDTH / 1.25f, HEIGHT_FLOOR_0));
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


	
	if (!App::IsSoundPlaying(".\\.\\Ressources\\Sounds\\Music2.wav"))
	{
		App::PlaySound(".\\.\\Ressources\\Sounds\\Music2.wav", true);
	}
}

void GameManager::StartGame()
{
	App::StopSound(".\\.\\Ressources\\Sounds\\Music2.wav");
	App::PlaySound(".\\.\\Ressources\\Sounds\\Music1.wav", true);
}

void GameManager::AskGameOver()
{
	m_bAskForGameOver = true; 
	m_CurrentDurationGameOver = 0.f;
}

void GameManager::GameOver()
{
	App::StopSound(".\\.\\Ressources\\Sounds\\Music1.wav");
	App::PlaySound(".\\.\\Ressources\\Sounds\\GameOver.wav", false);
}

void GameManager::WaitRestart()
{
	App::PlaySound(".\\.\\Ressources\\Sounds\\Music2.wav", true);
}

void GameManager::AskRestart()
{
	Shutdown();
	ChangeGameState(EGameState::PreStart);
}
