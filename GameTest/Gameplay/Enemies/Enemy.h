#pragma once
#include "../GameObject.h"
#include "../LifeManager.h"
class Enemy :
    public GameObject
{

#pragma region VARIABLES
public :

float m_DamageCollisionPlayer;

#pragma endregion


#pragma region FUNCTIONS
    Enemy();

    void InitializeGameObjectDatas() override; // To do : Should be virtual

    void Update(float Deltatime) override;

    void ApplyDamages(float damages);
#pragma endregion

};

