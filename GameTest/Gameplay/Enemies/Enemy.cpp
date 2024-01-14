#include "stdafx.h"
#include "Enemy.h"
#include "../GameManager.h"
#include <algorithm>
#include <random>

Enemy::Enemy() : GameObject()
{
	m_TypeObject = GameObjectType::EnemyElement;
}

void Enemy::InitializeGameObjectDatas()
{
}

void Enemy::Update(float Deltatime)
{
	GameObject::Update(Deltatime);
	if (this && m_GameManager && m_GameManager->m_Player && m_GameManager->m_Player->m_bIsActivated)
	{
		if (this && m_Collision)
		{
			const bool CollideWithPlayer = m_Collision->IsColliding(*m_GameManager->m_Player->m_CapsuleCollision);
			if (CollideWithPlayer && !m_bAlreadyHitPlayer)
			{
 				m_GameManager->m_Player->ApplyDamages(m_DamageCollisionPlayer); 
				m_bAlreadyHitPlayer = true;
				m_GameManager->m_MalusScore += m_MalusScoreOnHit;
			}
		}
	}
}

void Enemy::RandomSpeedDirection()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	// Génération aléatoire de 0 ou 1
	int randomDirection = dis(gen);

	m_SpeedZ = randomDirection == 0 ? -m_SpeedZ : m_SpeedZ;
}

void Enemy::ApplyDamages(float damages)
{
	if (this && m_LifeManager && !m_LifeManager->m_bIsDead)
	{
		m_LifeManager->ApplyDamage(damages);

		if (m_LifeManager->m_bIsDead)
		{
			if (m_GameManager)
			{
				m_GameManager->m_KillBonus+=m_ScoreOnKill;
			}
			Death();
		}
	}
}
