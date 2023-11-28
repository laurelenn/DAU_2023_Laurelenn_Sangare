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

#pragma endregion

#pragma region FUNCTIONS
public : 
    LDMap(float Speed);

    void Init();
    void Update(float deltaTime);
    void Render();
    void Destroy();
#pragma endregion
};

