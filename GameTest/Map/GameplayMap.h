#pragma once
#include "Map.h"
struct GameplayDatasMap
{
    // To do : Create Gameplay here with class, enums, initial pos
};

class GameplayMap :
    public Map
{

#pragma region VARIABLES

// Array of game objects

#pragma endregion

#pragma region FUNCTIONS
public : 
    GameplayMap(float Speed);

    void Init();
    void Update(float deltaTime);
    void Render();
    void Destroy();
};

