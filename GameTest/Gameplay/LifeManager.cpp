#include "stdafx.h"
#include "LifeManager.h"
#include "../App/app.h"
#include <iostream> 
#include <algorithm>

float LifeManager::ApplyDamage(float Damages)
{
	if (m_CurrentLife <= 0 && !m_bIsDead)
	{
		m_bIsDead = true;
		return m_CurrentLife;
	}

	if (m_bIsActivated)
	{
		if (Damages >= 0 && m_bIsInvincible)
		{
			return m_CurrentLife;
		}
		else // if Heald (Damages < 0) or not Invincible
		{
			if (!m_bIsDead)
			{
				m_CurrentLife = CLAMP(m_CurrentLife - Damages, 0.f, m_MaxLife);
			}
		}

		if (m_CurrentLife <= 0 && !m_bIsDead)
		{
			m_bIsDead = true;
		}
	}
	return m_CurrentLife;
}

float LifeManager::Heal(float Heal)
{
	return ApplyDamage(-Heal);
}

void LifeManager::MakeItInvincible()
{
	m_bIsInvincible = true;
}

void LifeManager::MakeItVulnerable()
{
	m_bIsInvincible = false;
}