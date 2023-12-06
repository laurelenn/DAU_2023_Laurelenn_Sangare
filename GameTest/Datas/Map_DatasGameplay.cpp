#include "stdafx.h"

#include "Map_DatasGameplay.h"

#pragma region LD ARRAYS


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_1 =
{
    GameplayDatasMap(Monster1, Floor_Level0, 5.0f, 300.0f),
    GameplayDatasMap(Monster1, Floor_Level0, 5.0f, 500.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_2 =
{
    GameplayDatasMap(Monster1, Floor_Level1, 5.0f, 300.0f),
    GameplayDatasMap(Monster1, Floor_Level1, 20.0f, 500.0f)
};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_Easy = 
{ 
    Map_DatasGameplay::m_LD_Easy_1,
    Map_DatasGameplay::m_LD_Easy_2 
};


#pragma endregion