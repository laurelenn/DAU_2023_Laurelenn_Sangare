#pragma once
#include "../Gameplay/GameObject.h"
#include "../App/AppSettings.h"

enum GameObjectLDType
{
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
    GameObjectLDType m_TypeGameObject;
    FloorLevels m_FloorSpawn;
    // Make a tile system would be good
    float m_SpawnPositionX;
};