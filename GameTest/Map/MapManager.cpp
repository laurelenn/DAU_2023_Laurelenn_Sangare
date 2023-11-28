#include "stdafx.h"

#include "../App/app.h"
#include "MapManager.h"

void MapManager::Init()
{
	MapGenerator* m_MapGenerator = new MapGenerator();

	// Generate Maps
	LDMap* m_CurrentLDMap = m_MapGenerator->GenerateLDMap(true, nullptr, m_SpeedMap);
	LDMap* m_NextLDMap = m_MapGenerator->GenerateLDMap(false, m_CurrentLDMap, m_SpeedMap);
	BackgroundMap* m_CurrentBgMap = m_MapGenerator->GenerateBgMap(true, nullptr, m_SpeedMap*2);
	BackgroundMap* m_NextBgMap = m_MapGenerator->GenerateBgMap(false, m_CurrentBgMap, m_SpeedMap*2);
	GameplayMap* m_CurrentGameplayMap = m_MapGenerator->GenerateGameplayMap(true, m_SpeedMap);
	GameplayMap* m_NextGameplayMap = m_MapGenerator->GenerateGameplayMap(false, m_SpeedMap);

	// Set position of maps

	//To do : Calculate good values
	float InitialXPos = m_Width / 2.f;
	float InitialZPos = m_Height / 2.f;

	float InitialXPosNext = InitialXPos + m_Width/2.f;
	float InitialZPosNext = InitialZPos;

#pragma region LD
	if (m_CurrentLDMap)
	{
		m_CurrentLDMap->Init();
		// m_CurrentLDMap->SetPosition(InitialXPos, InitialZPos); /: To do : Set position ??
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current LD map (MapManager::Init)");
	}

	if (m_NextLDMap)
	{
		//m_NextLDMap->SetPosition(InitialXPosNext, InitialZPosNext); // To do : Set position ??
		m_NextLDMap->Init();
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next LD map (MapManager::Init)");
	}
#pragma endregion

#pragma region Bg
	if (m_CurrentBgMap)
	{
	m_CurrentBgMap->Init();
		m_CurrentBgMap->SetPosition(InitialXPos, InitialZPos);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current Bg map (MapManager::Init)");
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->Init();
		m_NextBgMap->SetPosition(InitialXPosNext, InitialZPosNext);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next Bg map (MapManager::Init)");
	}
#pragma endregion

#pragma region Gameplay
	if (m_CurrentGameplayMap)
	{
		m_CurrentGameplayMap->Init();
		// m_CurrentGameplayMap->SetPosition(InitialXPos, InitialZPos);	// To do : Set position ??
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current Gameplay map (MapManager::Init)");
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->Init();
		// m_NextGameplayMap->SetPosition(InitialXPosNext, InitialZPosNext); // To do : Set position ??
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next Gameplay map (MapManager::Init)");
	}
#pragma endregion
}

void MapManager::Update(float Deltatime)
{
#pragma region LD
	if (CheckEndMap(m_CurrentLDMap))
	{
		delete m_CurrentLDMap;
		m_CurrentLDMap = m_NextLDMap;
		m_NextLDMap = m_MapGenerator->GenerateLDMap(false, m_CurrentLDMap, m_SpeedMap);
	}
	if (m_CurrentLDMap)
	{
		m_CurrentLDMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current LD map (MapManager::Update)");
	}

	if (m_NextLDMap)
	{
		m_NextLDMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next LD map (MapManager::Update)");
	}
#pragma endregion

#pragma region Background
	if (CheckEndMap(m_CurrentBgMap))
	{
		delete m_CurrentBgMap;
		m_CurrentBgMap = m_NextBgMap;
		m_NextBgMap = m_MapGenerator->GenerateBgMap(false, m_CurrentBgMap, m_SpeedMap);
	}
	if (m_CurrentBgMap)
	{
		m_CurrentBgMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current Bg map (MapManager::Update)");
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next Bg map (MapManager::Update)");
	}
	#pragma endregion

#pragma region Gameplay
	if (CheckEndMap(m_CurrentGameplayMap))
	{
		delete m_CurrentGameplayMap;
		m_CurrentGameplayMap = m_NextGameplayMap;
		m_NextGameplayMap = m_MapGenerator->GenerateGameplayMap(false, m_SpeedMap);
	}
	if (m_CurrentGameplayMap)
	{
		m_CurrentGameplayMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No current Gameplay map (MapManager::Update)");
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->Update(Deltatime);
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] No Next Gameplay map (MapManager::Update)");
	}
	#pragma endregion
}

void MapManager::Render()
{

#pragma region LD

	if (m_CurrentLDMap)
	{
		m_CurrentLDMap->Render();
	}

	if (m_NextLDMap)
	{
		m_NextLDMap->Render();
	}

#pragma endregion

#pragma region Bg
	if (m_CurrentBgMap)
	{
		m_CurrentBgMap->Render();
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->Render();
	}
#pragma endregion

#pragma region Gameplay
	if (m_CurrentGameplayMap)
	{
		m_CurrentGameplayMap->Render();
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->Render();
	}
#pragma endregion

}

void MapManager::Destroy()
{
delete m_MapGenerator;
delete m_CurrentLDMap;
delete m_CurrentBgMap;
delete m_CurrentGameplayMap;

delete m_NextLDMap;
delete m_NextBgMap;
delete m_NextGameplayMap;
}

bool MapManager::CheckEndMap(Map* map)
{
	// Check position.x of map, if == -size/2 (?) return true;
	if (map)
	{
		const bool Result = map->m_Position.x <= -m_Width/2;
			return Result;
	}
	else
	{
		App::Print(100.f, 100.f, "[MapManager] Invalid map pointer (MapManager::CheckEndMap)");
	}
	return false;
}
