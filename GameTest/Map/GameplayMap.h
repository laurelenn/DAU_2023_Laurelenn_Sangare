#pragma once
#include "Map.h"
#include "../Datas/Map_DatasGameplay.h"
#include "../Gameplay/GameObject.h"

struct GameplayDatasMap;

class GameplayMap :
    public Map
{

#pragma region VARIABLES

// Array of game objects
    std::vector<GameplayDatasMap> m_DatasGameplayMap;
    std::vector<GameObject*> m_GameObjectGameplayMap = {};
#pragma endregion

#pragma region FUNCTIONS
public : 
    GameplayMap(float Speed, std::vector<GameplayDatasMap> Datas);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Destroy() override;
    GameObject* SpawnNewObjectFromData(GameplayDatasMap data);
    void GameObjectReachEnd(GameObject* gameObject);
};

