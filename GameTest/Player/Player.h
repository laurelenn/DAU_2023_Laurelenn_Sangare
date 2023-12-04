#pragma once
#include "../Gameplay/GameObject.h"
#include "../Gameplay/LifeManager.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"

enum AnimPlayer
{
    ANIM_RUN,
    ANIM_JUMP,
    ANIM_CROUNCH,
    ANIM_HIT,
    ANIM_ATTACK,
    ANIM_DEATH
};

class Player :
    public GameObject
{

#pragma region VARIABLES

LifeManager *m_LifeManager;
CapsuleCollisionComponent *m_CapsuleCollision;
float m_SpeedAnimationRun = 3.5f;
float m_Scale = 1.f;
float m_HeightJump = HEIGHT_FLOOR_0; //  /2 ?
float m_SpeedJump = 1.f;

// Runtime
float m_CurrentFloorLevel = HEIGHT_FLOOR_0;
float m_HeightJumpCurrentLevel = HEIGHT_FLOOR_1;
bool m_bIsJumping = false;
bool m_bIsJumpingDown = false;

#pragma endregion


#pragma region FUNCTIONS
public : 
Player(float InitialLife, float Height, float Width, float Scale);

void InitializeGameObjectDatas() override;

void Update(float Deltatime) override;

void Jump();
void EndJump();
#pragma endregion

};

