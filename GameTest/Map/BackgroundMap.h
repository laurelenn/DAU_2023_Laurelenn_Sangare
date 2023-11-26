#pragma once
#include "Map.h"
class BackgroundMap :
    public Map
{

#pragma region VARIABLES
#pragma endregion

#pragma region FUNCTIONS
public:
    BackgroundMap(float Speed);

    void Init();
    void Update(float deltaTime);
    void Render();
    void Destroy();
#pragma endregion

};

