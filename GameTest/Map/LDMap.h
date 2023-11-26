#pragma once
#include "Map.h"

struct LDDatasMap
{
    // To do : Create LD here
};

class LDMap :
    public Map
{

#pragma region VARIABLES
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

