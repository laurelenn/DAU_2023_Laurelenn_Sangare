#include "stdafx.h"
#include "LifeManager.h"
#include <iostream> 
#include <algorithm>

float LifeManager::ApplyDamage(float Damages)
{
	if (Damages >= 0 && m_bIsInvincible)
	{
		return m_CurrentLife;
	}
	else // if Heald (Damages < 0) or not Invincible
	{
		//m_CurrentLife -= std::clamp(m_CurrentLife - Damages, 0.f, m_MaxLife);
		m_CurrentLife -= Damages;
	}
	return m_CurrentLife;
}

float LifeManager::Heal(float Heal)
{
	return ApplyDamage(-Heal);
}