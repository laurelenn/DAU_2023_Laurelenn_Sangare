#pragma once

#include "LDMap.h"
#include "BackgroundMap.h"
#include "GameplayMap.h"

class MapGenerator
{

#pragma region VARIABLES
// To do : Make list of LD Map

// To do : Make list of Background Map

#pragma endregion

#pragma region FUNCTIONS
public : 
MapGenerator(){};
LDMap* GenerateLDMap(bool isFirstMap, LDMap* previousMap);
BackgroundMap* GenerateBgMap(bool isFirstMap, BackgroundMap* previousMap);
GameplayMap* GenerateGameplayMap(bool isFirstMap);
#pragma endregion
};

