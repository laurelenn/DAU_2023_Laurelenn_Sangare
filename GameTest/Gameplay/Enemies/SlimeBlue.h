#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"

enum AnimSlimeBlue 
{
    IdleSlimeBlue
};

class SlimeBlue :
    public Enemy
{
#pragma region VARIABLES

CircleCollisionComponent * m_SphereCollision;

#pragma endregion

#pragma region FUNCTIONS
public : 
    SlimeBlue();

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Death() override;

#pragma endregion

};

