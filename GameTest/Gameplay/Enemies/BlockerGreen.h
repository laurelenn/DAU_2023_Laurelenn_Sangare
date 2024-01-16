#pragma once
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"
#include "../Gameplay/Projectiles/ProjectileSpawner.h"

enum AnimBlockerGreen 
{
    IdleBlockerGreen
};

class BlockerGreen :
    public Enemy
{
#pragma region VARIABLES
protected : 

RectangleCollisionComponent *m_RectangleCollision;
ProjectileSpawner* m_ProjectileSpawner;
#pragma endregion

#pragma region FUNCTIONS
public : 
    BlockerGreen();

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Render() override;

    void Death() override;

#pragma endregion

};

