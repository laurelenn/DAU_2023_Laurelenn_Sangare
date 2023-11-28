#include "stdafx.h"

#include "MapGenerator.h"

LDMap* MapGenerator::GenerateLDMap(bool isFirstMap, LDMap* previousMap, float speed)
{
    // return SelectLDMap(isFirstMap); // To do
    auto newMap = new LDMap(speed);
    return newMap;
}

BackgroundMap* MapGenerator::GenerateBgMap(bool isFirstMap, BackgroundMap* previousMap, float speed)
{
    // return SelectBgMap(isFirstMap); // To do
    auto newMap = new BackgroundMap(speed);
    return newMap;
}

GameplayMap* MapGenerator::GenerateGameplayMap(bool isFirstMap, float speed)
{
    // return SelectGameplayMap(isFirstMap); // To do
    auto newMap = new GameplayMap(speed);

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

GameplayDatasMap MapGenerator::SelectGameplayMap(bool isFirstMap)
{
    return GameplayDatasMap(); // To do
}


