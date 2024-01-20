#include "stdafx.h"
#include "../PowerUp/PowerUp.h"
#include "../GameManager.h"

PowerUp::PowerUp(PowerUpType type) : m_PowerUpType(type)
{
	m_Scale = 0.3f;
	m_Width = 100.f*m_Scale;
	m_Height = 100.f*m_Scale;
	m_SphereCollision = new CircleCollisionComponent(m_Width);
	m_Collision = std::unique_ptr<CollisionComponent>(m_SphereCollision);
	m_TypeObject = GameObjectType::PowerUpBonus;
	m_SpeedX = 0.f;
	m_SpeedZ = 0.f;
}

void PowerUp::InitializeGameObjectDatas()
{
	
	GameObject::InitializeGameObjectDatas();
	m_SpriteColumns = 1;
	m_SpriteLines = 1;

	switch (m_PowerUpType)
	{
		case PowerUpType::UFO:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\PowerUps\\PowerUpUFO.png";
			break;
		case PowerUpType::Shield:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\PowerUps\\PowerUpShield.png";
			break;
		case PowerUpType::FireRate:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\PowerUps\\PowerUpRate.png";
			break;
		case PowerUpType::FireDamage:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\PowerUps\\PowerUpDamage.png";
			break;
		case PowerUpType::BonusLife:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\PowerUps\\PowerUpLife.png";
			break;
		default:
		break;
	}

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, 1, {0});

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);

	m_ScaleDeath = 1.5f;
	m_SpriteDeath->SetScale(m_ScaleDeath);
	m_SpriteDeath->SetAnimation(ImpactCircle);
}

void PowerUp::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	if (this && m_GameManager && m_GameManager->m_Player && m_GameManager->m_Player->m_bIsActivated)
	{
		if (this && m_Collision)
		{
			const bool CollideWithPlayer = m_Collision->IsColliding(*m_GameManager->m_Player->m_CapsuleCollision);
			if (CollideWithPlayer && !m_bAlreadyHitPlayer)
			{
				m_GameManager->m_Player->ActivatePowerUp(m_PowerUpType);
				m_bAlreadyHitPlayer = true;
				// To do : Play sound
				Death();
			}
		}
	}
}

void PowerUp::Death()
{
	GameObject::Death();
}
