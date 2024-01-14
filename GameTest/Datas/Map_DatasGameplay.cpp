#include "stdafx.h"

#include "Map_DatasGameplay.h"

#pragma region LD ARRAYS




const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_FirstMap =
{
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, APP_VIRTUAL_WIDTH*APP_VIRTUAL_SCALE)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_1 =
{
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, .0f, 200.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 400.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, 900.0f),
    GameplayDatasMap(PowerUpDamage, Floor_Level1, 10.0f, 900.0f),
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_2 =
{
    GameplayDatasMap(Monster_Bee, Floor_Level0, 40.0f, 400.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level1, 10.0f, 1100.0f),
    GameplayDatasMap(PowerUpShield, Floor_Level1, 10.0f, 900.0f),
    GameplayDatasMap(PowerUpSpecialUFO, Floor_Level1, 30.0f, 500.0f),

};

const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_3 =
{
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 400.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level1, .0f, 1100.0f),
    GameplayDatasMap(PowerUpDamage, Floor_Level1, 10.0f, 900.0f),
    GameplayDatasMap(PowerUpRate, Floor_Level0, 5.0f, 500.0f),

};

const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_4 =
{
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, 1000.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, 1100.0f),
    GameplayDatasMap(PowerUpLife, Floor_Level0, 20.0f, 700.0f)

};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_Easy = 
{ 
    Map_DatasGameplay::m_LD_Easy_1,
    Map_DatasGameplay::m_LD_Easy_2, 
    Map_DatasGameplay::m_LD_Easy_3, 
    Map_DatasGameplay::m_LD_Easy_4 
};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_FirstMaps =
{ 
    Map_DatasGameplay::m_LD_FirstMap
};


#pragma endregion