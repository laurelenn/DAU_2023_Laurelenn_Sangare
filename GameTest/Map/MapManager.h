#pragma once
#include "MapGenerator.h"
#include "../App/AppSettings.h"

class GameManager;

class MapManager
{

#pragma region VARIABLES

GameManager *m_GameManager = nullptr;

float m_Width;
float m_Height;
float m_SpeedMap;
float m_Scale = 0.5f;
float m_DiffSpeedLayers = 1.15f;

MapGenerator *m_MapGenerator = nullptr;

public : 
LDMap *m_OldLDMap = nullptr;
LDMap *m_CurrentLDMap = nullptr;
LDMap *m_NextLDMap = nullptr;

BackgroundMap *m_OldBgMap = nullptr;
BackgroundMap *m_CurrentBgMap = nullptr;
BackgroundMap *m_NextBgMap = nullptr;

GameplayMap *m_OldGameplayMap = nullptr;
GameplayMap *m_CurrentGameplayMap = nullptr;
GameplayMap *m_NextGameplayMap = nullptr;

#pragma endregion


#pragma region FUNCTIONS
public : 
    MapManager(float height, float width, float speed, float scale) : m_Height(height), m_Width(width), m_SpeedMap(speed), m_Scale(scale) {}

    void SetGameManager(GameManager* gameManager) { m_GameManager = gameManager; }

    void Init();
    void Update(float Deltatime);
    void RenderBg();
    void RenderGD();
    void RenderLD();
    void Destroy();
    bool CheckEndMap(Map* map);
    void GameOver();
#pragma endregion

};

