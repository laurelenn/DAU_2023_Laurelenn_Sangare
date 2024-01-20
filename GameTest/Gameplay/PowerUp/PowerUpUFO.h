#pragma once
#include "..\GameObject.h"

class Player;

class PowerUpUFO :
    public GameObject
{

#pragma region VARIABLES
    RectangleCollisionComponent* m_RectangleCollision;
    std::vector<GameObject*> m_HitObjects;

    public : 
    Player* m_Player;

#pragma endregion


#pragma region FUNCTIONS
public:
    PowerUpUFO();

    void InitializeGameObjectDatas();

    void Update(float Deltatime) override;

    void CheckCollisionEnemies(GameplayMap* map);

    void Death() override;
#pragma endregion

};

