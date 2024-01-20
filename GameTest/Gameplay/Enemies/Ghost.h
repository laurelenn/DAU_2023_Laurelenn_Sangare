#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"

class Ghost :
    public Enemy
{
#pragma region VARIABLES

    CapsuleCollisionComponent* m_CapsuleCollision;

#pragma endregion

#pragma region FUNCTIONS
public:
    Ghost();

    void InitializeGameObjectDatas();

    void Update(float deltaTime) override;

    void Death() override;

#pragma endregion

};

