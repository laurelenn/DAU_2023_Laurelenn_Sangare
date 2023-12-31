#include "stdafx.h"
#include <random>

#include "MapGenerator.h"

LDMap* MapGenerator::GenerateLDMap(bool isFirstMap, LDMap* previousMap, float speed)
{
    // return SelectLDMap(isFirstMap); // To do
    auto newMap = new LDMap(speed);
    if (newMap && m_GameManager)
    {
        newMap->SetGameManager(m_GameManager); 
    }

    return newMap;
}

BackgroundMap* MapGenerator::GenerateBgMap(bool isFirstMap, BackgroundMap* previousMap, float speed)
{
    // return SelectBgMap(isFirstMap); // To do
    auto newMap = new BackgroundMap(speed);
    if (newMap && m_GameManager)
    {
        newMap->SetGameManager(m_GameManager);
    }

    return newMap;
}

GameplayMap* MapGenerator::GenerateGameplayMap(bool isFirstMap, float speed)
{
   auto newMap = new GameplayMap(speed, SelectGameplayMap(isFirstMap));
   if (newMap && m_GameManager)
   {
        newMap->SetGameManager(m_GameManager);
   }
    return newMap;
}

LDDatasMap MapGenerator::SelectLDMap(bool isFirstMap)
{
    return LDDatasMap(); // To do
}

BackgroundDatasMap MapGenerator::SelectBgMap(bool isFirstMap)
{
    return BackgroundDatasMap(); // To do
}

std::vector<GameplayDatasMap> MapGenerator::SelectGameplayMap(bool isFirstMap)
{

    std::vector<GameplayDatasMap> selectedLD;
    std::random_device rd;
    std::mt19937 gen(rd());

    if (isFirstMap)
    {
        std::uniform_int_distribution<> distrib(0, Map_DatasGameplay::m_ArrayLD_FirstMaps.size() - 1);
        const int randomIndex = distrib(gen);
        selectedLD = Map_DatasGameplay::m_ArrayLD_FirstMaps[randomIndex];

    }
    else
    {
        std::uniform_int_distribution<> distrib(0, Map_DatasGameplay::m_ArrayLD_Easy.size() - 1);
        const int randomIndex = distrib(gen);
        selectedLD = Map_DatasGameplay::m_ArrayLD_Easy[randomIndex];

    }

    return selectedLD;
}


