#pragma once
#include "Map.h"
#include "../Datas/Map_DatasGameplay.h"

class GameplayMap :
    public Map
{

#pragma region VARIABLES

// Array of game objects
GameplayDatasMap m_DatasGameplayMap;
#pragma endregion

#pragma region FUNCTIONS
public : 
    GameplayMap(float Speed);
    GameplayMap(float Speed, GameplayDatasMap Datas);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Destroy() override;
};

