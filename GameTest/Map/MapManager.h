#pragma once
#include "LDMap.h"
#include "BackgroundMap.h"
#include "MapGenerator.h"
#include "GameplayMap.h"
#include "LDMap.h"
class MapManager
{

#pragma region VARIABLES
float m_Width;
float m_Height;

MapGenerator *m_MapGenerator = nullptr;

LDMap *m_CurrentLDMap = nullptr;
LDMap *m_NextLDMap = nullptr;
BackgroundMap *m_CurrentBgMap = nullptr;
BackgroundMap *m_NextBgMap = nullptr;
GameplayMap *m_CurrentGameplayMap = nullptr;
GameplayMap *m_NextGameplayMap = nullptr;

#pragma endregion


#pragma region FUNCTIONS
public : 
    MapManager(float height, float width) : m_Height(height), m_Width(width) {}

    void Init();
    void Update(float Deltatime);
    void Render();
    void Destroy();
#pragma endregion

};

