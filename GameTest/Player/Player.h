#pragma once
#include "../Gameplay/LifeManager.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"
#include "../Gameplay/GameObject.h"
#include "../Gameplay/PowerUp/PowerUp.h"

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

class Player :
    public GameObject
{

#pragma region VARIABLES
public : 
    CapsuleCollisionComponent* m_CapsuleCollision;

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

#pragma endregion


#pragma region FUNCTIONS
public : 
Player(float InitialLife, float Scale);

void InitializeGameObjectDatas() override;

void ActivatePowerUp(PowerUpType type);

void Update(float Deltatime) override;
void UpdateJump(float Deltatime);

void Jump();
void EndJump();

void Death() override;
#pragma endregion

};

