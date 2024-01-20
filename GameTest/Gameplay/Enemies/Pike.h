#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"

class Pike :
    public Enemy
{
#pragma region VARIABLES

    RectangleCollisionComponent* m_RectangleCollision;

#pragma endregion

#pragma region FUNCTIONS
public:
    Pike();

    void InitializeGameObjectDatas();

    void Update(float deltaTime) override;

    void Death() override;

#pragma endregion

};

