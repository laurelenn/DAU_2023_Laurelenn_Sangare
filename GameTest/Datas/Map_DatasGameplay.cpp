#include "stdafx.h"

#include "Map_DatasGameplay.h"

#pragma region LD ARRAYS




const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_FirstMap =
{
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, .0f, APP_VIRTUAL_WIDTH*APP_VIRTUAL_SCALE)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_1 =
{
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 200.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 900.0f)
};


const std::vector<GameplayDatasMap> Map_DatasGameplay::m_LD_Easy_2 =
{
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 400.0f),
    GameplayDatasMap(Monster_SlimeBlue, Floor_Level0, .0f, 1000.0f),
    GameplayDatasMap(Monster_BlockerGreen, Floor_Level0, .0f, 1000.0f)
};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_Easy = 
{ 
    Map_DatasGameplay::m_LD_Easy_1,
    Map_DatasGameplay::m_LD_Easy_2 
};

const std::vector<std::vector<GameplayDatasMap>> Map_DatasGameplay::m_ArrayLD_FirstMaps =
{ 
    Map_DatasGameplay::m_LD_FirstMap
};


#pragma endregion