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

#pragma endregion


#pragma region FUNCTIONS
public : 
Player(int InitialLife, float Height, float Width);

void InitializeGameObjectDatas() override;
#pragma endregion

};

