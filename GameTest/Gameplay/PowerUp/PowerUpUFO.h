#pragma once
#include "..\GameObject.h"

class PowerUpUFO :
    public GameObject
{

#pragma region VARIABLES
    RectangleCollisionComponent* m_RectangleCollision;
    std::vector<GameObject*> m_HitObjects;

#pragma endregion


#pragma region FUNCTIONS
public:
    PowerUpUFO();

    void InitializeGameObjectDatas() override;

    void Update(float Deltatime) override;

    void CheckCollisionEnemies(GameplayMap* map);
#pragma endregion

};

