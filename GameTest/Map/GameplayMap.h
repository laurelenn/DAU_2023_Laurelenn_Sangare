#pragma once
#include "Map.h"
struct GameplayDatasMap
{
    // To do : Create Gameplay here
};

class GameplayMap :
    public Map
{

#pragma region VARIABLES
#pragma endregion

#pragma region FUNCTIONS
public : 
    GameplayMap(float Speed);

    void Init();
    void Update(float deltaTime);
    void Render();
    void Destroy();
};

