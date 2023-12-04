#pragma once

#include "LDMap.h"
#include "BackgroundMap.h"
#include "GameplayMap.h"


class GameManager;

class MapGenerator
{

#pragma region VARIABLES

	GameManager* m_GameManager = nullptr;

#pragma endregion

#pragma region FUNCTIONS

public : 

MapGenerator(){};

void SetGameManager(GameManager* gameManager) { m_GameManager = gameManager;}

LDMap* GenerateLDMap(bool isFirstMap, LDMap* previousMap, float speed);
BackgroundMap* GenerateBgMap(bool isFirstMap, BackgroundMap* previousMap, float speed);
GameplayMap* GenerateGameplayMap(bool isFirstMap, float speed);

LDDatasMap SelectLDMap(bool isFirstMap);
BackgroundDatasMap SelectBgMap(bool isFirstMap);
GameplayDatasMap SelectGameplayMap(bool isFirstMap);

#pragma endregion
};

