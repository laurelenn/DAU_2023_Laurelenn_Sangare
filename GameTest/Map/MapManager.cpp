#include "stdafx.h"

#include "MapManager.h"

void MapManager::Init()
{
	MapGenerator* m_MapGenerator = new MapGenerator();

	LDMap* m_CurrentLDMap = m_MapGenerator->GenerateLDMap(true, nullptr);
	LDMap* m_NextLDMap = m_MapGenerator->GenerateLDMap(false, m_CurrentLDMap);
	BackgroundMap* m_CurrentBgMap = m_MapGenerator->GenerateBgMap(true, nullptr);
	BackgroundMap* m_NextBgMap = m_MapGenerator->GenerateBgMap(false, m_CurrentBgMap);
	GameplayMap* m_CurrentGameplayMap = m_MapGenerator->GenerateGameplayMap(true);
	GameplayMap* m_NextGameplayMap = m_MapGenerator->GenerateGameplayMap(false);
}

void MapManager::Update(float Deltatime)
{

}

void MapManager::Render()
{
}

void MapManager::Destroy()
{
}
