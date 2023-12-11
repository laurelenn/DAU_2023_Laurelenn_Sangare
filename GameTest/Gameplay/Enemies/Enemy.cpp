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
	if (m_GameManager && m_GameManager->m_Player && m_GameManager->m_Player->m_bIsActivated)
	{
		if (m_Collision)
		{
			const bool CollideWithPlayer = m_Collision->IsColliding(*m_GameManager->m_Player->m_CapsuleCollision);
			if (CollideWithPlayer)
			{
				m_GameManager->m_Player->ApplyDamages(m_DamageCollisionPlayer);
			}
		}
	}
}

void Enemy::ApplyDamages(float damages)
{

}
