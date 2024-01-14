#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "../App/AppSettings.h"

#pragma region SETUP

enum GameObjectLDType
{
    None,
    Monster_BlockerGreen,
    Monster_SlimeBlue,
    Monster_Ghost,
    Monster_BlockerRed,
    Monster_Snake,
    Monster_Bee,
    Obstacle_Pikes,
    PowerUpSpecialUFO,
    PowerUpLife,
    PowerUpShield,
    PowerUpRate,
    PowerUpDamage
};

struct GameplayDatasMap
{
    GameObjectLDType m_TypeGameObject = None;
    FloorLevels m_FloorSpawn = Floor_Level0;
    float m_DeltaPosZ = 0.f;
    float m_SpawnPositionX = 0.f;

    GameplayDatasMap() = default;

    GameplayDatasMap(GameObjectLDType type, FloorLevels floor, float deltaZ, float spawnX)
        : m_TypeGameObject(type), m_FloorSpawn(floor), m_DeltaPosZ(deltaZ), m_SpawnPositionX(spawnX)
    {}
};

#pragma endregion

class Map_DatasGameplay
{

public : 
#pragma region VARIABLES

    #pragma region LD ARRAYS
    static const std::vector<GameplayDatasMap> m_LD_FirstMap;
    static const std::vector<GameplayDatasMap> m_LD_Easy_1;
    static const std::vector<GameplayDatasMap> m_LD_Easy_2;
    static const std::vector<GameplayDatasMap> m_LD_Easy_3;
    static const std::vector<GameplayDatasMap> m_LD_Easy_4;
    static const std::vector<GameplayDatasMap> m_LD_Easy_5;

    #pragma endregion

    static const std::vector<std::vector<GameplayDatasMap>> m_ArrayLD_Easy;
    static const std::vector<std::vector<GameplayDatasMap>> m_ArrayLD_FirstMaps;


#pragma endregion

#pragma region FUNCTIONS
 #pragma endregion
};