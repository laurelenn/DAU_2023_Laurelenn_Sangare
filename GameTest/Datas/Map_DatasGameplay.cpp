#include "stdafx.h"

#include "Map_DatasGameplay.h"

#pragma region LD ARRAYS




const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_FirstMap =
{
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 2000.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 2500.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_1 =
{
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, 200.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 400.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level1, .0f, 900.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, .0f, 1500.0f),
    GameplayDatasMap(PowerUpDamage, Floor_Level1, 10.0f, 900.0f),
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_2 =
{
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 400.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level0, 50.0f, 500.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level1, 40.0f, 750.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level1, 0.0f, 1100.0f),
    GameplayDatasMap(PowerUpRate, Floor_Level0, 20.0f, 1000.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 1100.0f),
    GameplayDatasMap(PowerUpSpecialUFO, Floor_Level1, 30.0f, 500.0f),

};

const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_3 =
{
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 200.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level1, .0f, 1100.0f),
    GameplayDatasMap(PowerUpDamage, Floor_Level1, 10.0f, 900.0f),
    GameplayDatasMap(PowerUpRate, Floor_Level0, 5.0f, 500.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 550.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 1550.0f),
};

const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_4 =
{
    GameplayDatasMap(PowerUpRate, Floor_Level0, 20.0f, 200.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level0, 50.0f, 500.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, 50.0f, 700.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 1400.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level1, 30.0f, 1200.0f),
    GameplayDatasMap(PowerUpLife, Floor_Level1, 20.0f, 1000.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 900.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_5 =
{
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 400.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 100.0f),
    GameplayDatasMap(PowerUpSpecialUFO, Floor_Level0, 0.0f, 800.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 1200.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 1800.0f),
    GameplayDatasMap(PowerUpLife, Floor_Level1, 50.0f, 1000.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 900.0f)

};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_6 =
{
    GameplayDatasMap(PowerUpShield, Floor_Level0, 20.0f, 100.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level0, 50.0f, 200.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level1, 50.0f, 400.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 550.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 600.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 900.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, .0f, 1050.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level1, 30.0f, 1000.0f),
    GameplayDatasMap(Monster_Bee, Floor_Level0, 20.0f, 1500.0f),
    GameplayDatasMap(PowerUpLife, Floor_Level1, 20.0f, 1800.0f),


};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_7 =
{
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 200.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level1, 10.0f, 800.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 1200.0f),
    GameplayDatasMap(PowerUpRate, Floor_Level0, 20.0f, 1000.0f),
    GameplayDatasMap(PowerUpLife, Floor_Level1, 20.0f, 1000.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, 20.0f, 900.0f)

};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_8 =
{
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, 0.0f, 400.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 500.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level1, 10.0f, 800.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, 20.0f, 900.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, 0.0f, 1200.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 1400.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, 0.0f, 1500.0f),

};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_9 =
{
    GameplayDatasMap(Monster_Bee, Floor_Level0, 20.0f, 100.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 400.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 800.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 1200.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 1800.0f),
    GameplayDatasMap(PowerUpShield, Floor_Level0, 20.0f, 1000.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 900.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_10 =
{
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 500.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 800.0f),
    GameplayDatasMap(PowerUpShield, Floor_Level1, 20.0f, 1000.0f),
    GameplayDatasMap(PowerUpRate, Floor_Level0, .0f, 1000.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 1400.0f),
    GameplayDatasMap(Monster_Ghost, Floor_Level0, 20.0f, 300.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 200.0f),
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 16500.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_11 =
{
    GameplayDatasMap(Obstacle_Pikes, Floor_Level0, 0.0f, 600.0f),
    GameplayDatasMap(Monster_Snake, Floor_Level0, 0.0f, 500.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 1400.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, 0.0f, 1800.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level0, 20.0f, 900.0f),
    GameplayDatasMap(Monster_BeeLazy, Floor_Level1, 20.0f, 1400.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_12 =
{
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 300.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 900.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 1000.0f),
    GameplayDatasMap(PowerUpDamage, Floor_Level0, .0f, 1100.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 1300.0f)
};



const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_Easy = 
{ 
    Map_DatasGameplay::m_LD_Easy_1,
    Map_DatasGameplay::m_LD_Easy_2, 
    Map_DatasGameplay::m_LD_Easy_3, 
    Map_DatasGameplay::m_LD_Easy_4, 
    Map_DatasGameplay::m_LD_Easy_5, 
    Map_DatasGameplay::m_LD_Easy_6, 
    Map_DatasGameplay::m_LD_Easy_7, 
    Map_DatasGameplay::m_LD_Easy_8, 
    Map_DatasGameplay::m_LD_Easy_9, 
    Map_DatasGameplay::m_LD_Easy_10, 
    Map_DatasGameplay::m_LD_Easy_11, 
    Map_DatasGameplay::m_LD_Easy_12
};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_FirstMaps =
{ 
    Map_DatasGameplay::m_LD_FirstMap
};


#pragma endregion