#pragma once
#include "../Gameplay/GameObject.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"

enum PowerUpType
{
    UFO,
    BonusLife,
    Shield,
    FireRate,
    FireDamage
};

class PowerUp :
    public GameObject
{

#pragma region VARIABLES
        CircleCollisionComponent* m_SphereCollision = nullptr;
        PowerUpType m_PowerUpType = PowerUpType::Shield;
        bool m_bAlreadyHitPlayer = false;

#pragma endregion

#pragma region FUNCTIONS

public :  
    PowerUp(PowerUpType type);

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Death() override;
#pragma endregion
};

