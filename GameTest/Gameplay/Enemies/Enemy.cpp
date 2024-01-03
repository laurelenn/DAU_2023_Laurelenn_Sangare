#include "stdafx.h"
#include "Enemy.h"
#include "../GameManager.h"

Enemy::Enemy() : GameObject()
{
	m_TypeObject = GameObjectType::Enemy;
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
			}
		}
	}
}

void Enemy::ApplyDamages(float damages)
{
	if (m_LifeManager)
	{
		ApplyDamages(damages);
	}
}
