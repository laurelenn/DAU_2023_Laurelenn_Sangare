#include "stdafx.h"

#include "MapManager.h"

void MapManager::Init()
{
	MapGenerator* m_MapGenerator = new MapGenerator();

	LDMap* m_CurrentLDMap = m_MapGenerator->GenerateLDMap(true, nullptr, m_SpeedMap);
	LDMap* m_NextLDMap = m_MapGenerator->GenerateLDMap(false, m_CurrentLDMap, m_SpeedMap);
	BackgroundMap* m_CurrentBgMap = m_MapGenerator->GenerateBgMap(true, nullptr, m_SpeedMap*2);
	BackgroundMap* m_NextBgMap = m_MapGenerator->GenerateBgMap(false, m_CurrentBgMap, m_SpeedMap*2);
	GameplayMap* m_CurrentGameplayMap = m_MapGenerator->GenerateGameplayMap(true, m_SpeedMap);
	GameplayMap* m_NextGameplayMap = m_MapGenerator->GenerateGameplayMap(false, m_SpeedMap);
}

void MapManager::Update(float Deltatime)
{
	m_CurrentLDMap->Update(Deltatime);
}

void MapManager::Render()
{
}

void MapManager::Destroy()
{
}
