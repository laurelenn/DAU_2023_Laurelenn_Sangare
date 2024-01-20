#pragma once
#include "../Gameplay/LifeManager.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"
#include "../Gameplay/GameObject.h"
#include "../Gameplay/PowerUp/PowerUp.h"
#include "../Gameplay/Projectiles/ProjectileSpawner.h"

struct PowerUpEffect {
    PowerUpType type = PowerUpType::BonusLife;
    float duration = 5.f;
    float currentDelay = 0.f;
    bool activated = false;

    PowerUpEffect( PowerUpType pType = PowerUpType::BonusLife, float pDuration = 5.f) : type(pType), duration(pDuration) 
    {
        currentDelay = 0.f;
        activated = false;
    }

};

enum AnimPlayer
{
    ANIM_RUN,
    ANIM_JUMP,
    ANIM_ONFLOOR,
    ANIM_CROUNCH,
    ANIM_HIT,
    ANIM_ATTACK,
    ANIM_DEATH
};

class PowerUpUFO;

class Player :
    public GameObject
{

#pragma region VARIABLES
public : 
    CapsuleCollisionComponent* m_CapsuleCollision;
    ProjectileSpawner* m_ProjectileSpawner;

private : 
float m_SpeedAnimationRun = 3.5f;
float m_HeightJump = HEIGHT_FLOOR_0*1.5f;
float m_InitialSpeedJump = 3.5f;
float m_DelayJumpInertia = 0.2f;

// Runtime
float m_CurrentFloorLevel = HEIGHT_FLOOR_0;
float m_HeightJumpCurrentLevel = HEIGHT_FLOOR_1;
float m_HeightConstantSpeed = HEIGHT_FLOOR_1;
bool m_bIsJumping = false;
bool m_bIsJumpingDown = false;
float m_CurrentSpeedJump;
float m_CurrentTimerJumpInertia;

// PowerUps
PowerUpEffect m_PowerUpEffectDamage = PowerUpEffect(PowerUpType::FireDamage, 5.f);
PowerUpEffect m_PowerUpEffectRate = PowerUpEffect(PowerUpType::FireRate, 5.f);
PowerUpEffect m_PowerUpEffectShield = PowerUpEffect(PowerUpType::Shield, 5.f);
public : 
PowerUpUFO* m_PowerUpEffectUFO = nullptr;
#pragma endregion


#pragma region FUNCTIONS
public : 
Player(float InitialLife, float Scale);

void InitializeGameObjectDatas();

void ActivatePowerUp(PowerUpType type);
void DeactivatePowerUp(PowerUpType type);

void Update(float Deltatime) override;
void UpdateJump(float Deltatime);
void UpdatePowerUp(float Deltatime);

void Render() override;

void Jump();
void EndJump();

void Death() override;
void Destroy();
#pragma endregion

};

