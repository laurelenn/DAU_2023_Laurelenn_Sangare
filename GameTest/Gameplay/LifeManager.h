#pragma once
#include <iostream> 


class LifeManager
{

public:

#pragma region DELEGATES
	//delegate1(void, ON_LIFE_CHANGE_DELEGATE, float, NewLife);

#pragma endregion


#pragma region VARIABLES
	float m_MaxLife;
	float m_InitialLife;
	float m_CurrentLife;
	bool m_bIsInvincible = false;
	bool m_bIsDead = false;
	bool m_bIsActivated = true;

#pragma endregion

#pragma region FUNCTIONS

	LifeManager(float MaxLife) : m_MaxLife(MaxLife), m_InitialLife(MaxLife), m_CurrentLife(MaxLife){};
	
	LifeManager(float MaxLife, float InitialLife) : m_MaxLife(MaxLife), m_InitialLife(InitialLife), m_CurrentLife(InitialLife){};

	float ApplyDamage(float Damages);
	float Heal(float Heal);

	void MakeItInvincible();
	void MakeItVulnerable();


#pragma endregion


};

