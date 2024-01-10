#pragma once
#include "../GameObject.h"
#include "../LifeManager.h"
class Enemy :
    public GameObject
{

#pragma region VARIABLES
public :

float m_DamageCollisionPlayer;
float m_SpeedAnimIdle = 200.f;
int m_ScoreOnKill = 100;
bool m_bAlreadyHitPlayer = false;
bool m_bAlreadyHitByPlayer = false;

#pragma endregion


#pragma region FUNCTIONS
    Enemy();

    void InitializeGameObjectDatas() override; // To do : Should be virtual

    void Update(float Deltatime) override;
public : 
    void ApplyDamages(float damages);
#pragma endregion

};

