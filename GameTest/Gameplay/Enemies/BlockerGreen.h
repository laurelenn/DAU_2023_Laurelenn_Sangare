#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"

enum AnimBlockerGreen 
{
    IdleBlockerGreen
};

class BlockerGreen :
    public Enemy
{
#pragma region VARIABLES

RectangleCollisionComponent *m_RectangleCollision;

#pragma endregion

#pragma region FUNCTIONS
public : 
    BlockerGreen();

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Death() override;

#pragma endregion

};

