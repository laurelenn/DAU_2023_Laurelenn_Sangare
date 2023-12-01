#include "stdafx.h"

#include <iostream>

#include "../App/app.h"
#include "MapManager.h"

void MapManager::Init()
{
	MapGenerator* m_MapGenerator = new MapGenerator();

	// Generate Maps
	m_CurrentLDMap = m_MapGenerator->GenerateLDMap(true, nullptr, m_SpeedMap);
	m_NextLDMap = m_MapGenerator->GenerateLDMap(false, m_CurrentLDMap, m_SpeedMap);

	m_CurrentBgMap = m_MapGenerator->GenerateBgMap(true, nullptr, m_SpeedMap*2);
	m_NextBgMap = m_MapGenerator->GenerateBgMap(false, m_CurrentBgMap, m_SpeedMap*2);

	m_CurrentGameplayMap = m_MapGenerator->GenerateGameplayMap(true, m_SpeedMap);
	m_NextGameplayMap = m_MapGenerator->GenerateGameplayMap(false, m_SpeedMap);

	// Set position of maps

	//To do : Calculate good values
	float InitialXPos = (m_Width/2.f)*m_Scale;
	float InitialZPos = (m_Height/2.f)*m_Scale;

	float InitialXPosNext = InitialXPos + (m_Width) * m_Scale;
	float InitialZPosNext = InitialZPos;

#pragma region LD
	if (m_CurrentLDMap)
	{
		m_CurrentLDMap->m_Scale = m_Scale;
		m_CurrentLDMap->Init();
		// m_CurrentLDMap->SetPosition(InitialXPos, InitialZPos); /: To do : Set position ??
	}
	else
	{
		std::cout << "[MapManager] No current LD map (MapManager::Init)" << std::endl;
	}

	if (m_NextLDMap)
	{
		m_NextLDMap->m_Scale = m_Scale;
		//m_NextLDMap->SetPosition(InitialXPosNext, InitialZPosNext); // To do : Set position ??
		m_NextLDMap->Init();
	}
	else
	{
		std::cout << "[MapManager] No Next LD map (MapManager::Init)" << std::endl;
	}
#pragma endregion

#pragma region Bg
	if (m_CurrentBgMap)
	{
		m_CurrentBgMap->m_Scale = m_Scale;
		m_CurrentBgMap->Init();
		m_CurrentBgMap->SetPosition(InitialXPos, InitialZPos);
	}
	else
	{
		std::cout << "[MapManager] No current Bg map (MapManager::Init)" << std::endl;
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->m_Scale = m_Scale;
		m_NextBgMap->Init();
		m_NextBgMap->SetPosition(InitialXPosNext, InitialZPosNext);
	}
	else
	{
		std::cout << "[MapManager] No Next Bg map (MapManager::Init)" << std::endl;
	}
#pragma endregion

#pragma region Gameplay
	if (m_CurrentGameplayMap)
	{
		m_CurrentGameplayMap->m_Scale = m_Scale;
		m_CurrentGameplayMap->Init();
		// m_CurrentGameplayMap->SetPosition(InitialXPos, InitialZPos);	// To do : Set position ??
	}
	else
	{
		std::cout << "[MapManager] No current Gameplay map (MapManager::Init)" << std::endl;
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->m_Scale = m_Scale;
		m_NextGameplayMap->Init();
		// m_NextGameplayMap->SetPosition(InitialXPosNext, InitialZPosNext); // To do : Set position ??
	}
	else
	{
		std::cout << "[MapManager] No Next Gameplay map (MapManager::Init)" << std::endl;
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
		std::cout << "[MapManager] No current LD map (MapManager::Update)" << std::endl;
	}

	if (m_NextLDMap)
	{
		m_NextLDMap->Update(Deltatime);
	}
	else
	{
		std::cout << "[MapManager] No Next LD map (MapManager::Update)" << std::endl;
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
		std::cout << "[MapManager] No current Bg map (MapManager::Update)" << std::endl;
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->Update(Deltatime);
	}
	else
	{
		std::cout << "[MapManager] No Next Bg map (MapManager::Update)" << std::endl;
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
		std::cout << "[MapManager] No current Gameplay map (MapManager::Update)" << std::endl;
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->Update(Deltatime);
	}
	else
	{
		std::cout << "[MapManager] No Next Gameplay map (MapManager::Update)" << std::endl;
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

	if (m_CurrentLDMap)
	{
		m_CurrentLDMap->Destroy();
		delete m_CurrentLDMap;
	}
	
	if (m_CurrentBgMap)
	{
		m_CurrentBgMap->Destroy();
		delete m_CurrentBgMap;
	}

	if (m_CurrentGameplayMap)
	{
		m_CurrentGameplayMap->Destroy();
		delete m_CurrentGameplayMap;
	}

	if (m_NextLDMap)
	{
		m_NextLDMap->Destroy();
		delete m_NextLDMap;
	}

	if (m_NextBgMap)
	{
		m_NextBgMap->Destroy();
		delete m_NextBgMap;
	}

	if (m_NextGameplayMap)
	{
		m_NextGameplayMap->Destroy();
		delete m_NextGameplayMap;
	}
}

bool MapManager::CheckEndMap(Map* map)
{
	// Check position.x of map, if == -size/2 (?) return true; // To do
	/*if (map)
	{
		const bool Result = map->m_Position.x <= -m_Width/2;
			return Result;
	}
	else
	{
		std::cout << "[MapManager] Invalid map pointer (MapManager::CheckEndMap)" << std::endl;
	}*/
	return false;
}
