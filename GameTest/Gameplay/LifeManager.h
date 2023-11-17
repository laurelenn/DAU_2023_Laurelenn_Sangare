#pragma once
#include <iostream> 


class LifeManager
{

public:

#pragma region DELEGATES
	//delegate1(void, ON_LIFE_CHANGE_DELEGATE, float, NewLife);

#pragma endregion


#pragma region VARIABLES
	float m_MaxLife = 100.f;
	float m_InitialLife = 100.f;
	float m_CurrentLife = 100.f;
	bool m_bIsInvincible = false;

#pragma endregion

#pragma region FUNCTIONS

	inline LifeManager() {};
	inline LifeManager(float MaxLife)
	{
		m_MaxLife = MaxLife;
		m_InitialLife = m_MaxLife;
		m_CurrentLife = m_MaxLife;
	};
	inline LifeManager(float MaxLife, float InitialLife)
	{
		m_MaxLife = MaxLife;
		m_InitialLife = m_MaxLife;
		m_CurrentLife = m_InitialLife;
	}

	float ApplyDamage(float Damages);
	float Heal(float Heal);


#pragma endregion


};

