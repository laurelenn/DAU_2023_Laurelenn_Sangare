#pragma once
#include "LDMap.h"
#include "BackgroundMap.h"
#include "MapGenerator.h"
#include "GameplayMap.h"
#include "LDMap.h"
#include "../App/AppSettings.h"
class MapManager
{

#pragma region VARIABLES
float m_Width;
float m_Height;
float m_SpeedMap;
float m_Scale = 0.5f;

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
    MapManager(float height, float width, float speed) : m_Height(height), m_Width(width), m_SpeedMap(speed) {}

    void Init();
    void Update(float Deltatime);
    void Render();
    void Destroy();
    bool CheckEndMap(Map* map);
#pragma endregion

};

