#pragma once
#include "Map.h"
#include "../Datas/Map_DatasLD.h"

class LDMap :
    public Map
{

#pragma region VARIABLES

// Array of tiles
LDDatasMap m_DatasLdMap;
App::Vector2 m_MinMaxPosZ = App::Vector2(HEIGHT_FLOOR_0, HEIGHT_FLOOR_1);

#pragma endregion

#pragma region FUNCTIONS
public : 
    LDMap(float Speed);
    LDMap(float Speed, LDDatasMap Datas);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Destroy() override;
#pragma endregion
};

