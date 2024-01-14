#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"

class Bee :
    public Enemy
{
#pragma region VARIABLES

    CircleCollisionComponent* m_CircleCollision;

#pragma endregion

#pragma region FUNCTIONS
public:
    Bee();

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Death() override;

#pragma endregion

};

