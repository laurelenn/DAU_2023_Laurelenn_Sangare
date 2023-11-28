#pragma once
#include "Map.h"

struct LDDatasMap
{
    // To do : Create LD here position & enum or class
};

class LDMap :
    public Map
{

#pragma region VARIABLES

// Array of tiles
LDDatasMap m_DatasLdMap;

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

