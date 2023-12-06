#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "../App/AppSettings.h"

#pragma region SETUP

enum GameObjectLDType
{
    None,
    Monster1,
    Monster2,
    Monster3,
    Obstacle1,
    Obstacle2,
    Obstacle3,
    TileHole,
    PowerUp1,
    PowerUp2,
    PowerUp3
};

struct GameplayDatasMap
{
    GameObjectLDType m_TypeGameObject = None;
    FloorLevels m_FloorSpawn = Floor_Level0;
    float m_DeltaPosZ = 0.f;
    float m_SpawnPositionX = 0.f;
    // To do : Associate with some LD types

    GameplayDatasMap() = default;

    GameplayDatasMap(GameObjectLDType type, FloorLevels floor, float deltaZ, float spawnX)
        : m_TypeGameObject(type), m_FloorSpawn(floor), m_DeltaPosZ(deltaZ), m_SpawnPositionX(spawnX)
    {}
};

#pragma endregion

class Map_DatasGameplay
{


#pragma region VARIABLES

    #pragma region LD ARRAYS
    std::vector<GameplayDatasMap> m_LD_Easy_1=
        {
            GameplayDatasMap(Monster1, Floor_Level0, 5.0f, 300.0f),
            GameplayDatasMap(Monster1, Floor_Level0, 5.0f, 500.0f)
        };
        
         std::vector<GameplayDatasMap> m_LD_Easy_2 =
        {
            GameplayDatasMap(Monster1, Floor_Level1, 5.0f, 300.0f),
            GameplayDatasMap(Monster1, Floor_Level1, 20.0f, 500.0f)
        };

    #pragma endregion

       std::vector<std::vector<GameplayDatasMap>> m_ArrayLD_Easy = { m_LD_Easy_1, m_LD_Easy_2 };


#pragma endregion

#pragma region FUNCTIONS
 #pragma endregion
};