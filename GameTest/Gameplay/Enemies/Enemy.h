#pragma once
#include "../GameObject.h"
#include "../LifeManager.h"
class Enemy :
    public GameObject
{
#pragma region VARIABLES

LifeManager m_Life;
#pragma endregion


#pragma region FUNCTIONS
    Enemy();

#pragma endregion

};

