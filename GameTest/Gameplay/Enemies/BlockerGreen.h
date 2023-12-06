#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/LifeManager.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"
#include "../Gameplay/GameObject.h"

enum AnimBlockerGreen 
{
    Idle
};

class BlockerGreen :
    public Enemy
{
#pragma region VARIABLES

RectangleCollisionComponent *m_RectangleCollision;
float m_SpeedAnim;

#pragma endregion

#pragma region FUNCTIONS
public : 
    BlockerGreen();

    void InitializeGameObjectDatas() override;

    void Death() override;

#pragma endregion

};

