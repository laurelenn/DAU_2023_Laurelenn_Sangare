#include "stdafx.h"
#include "../Projectiles/Projectile.h"
#include "../GameManager.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"
#include "../Gameplay/Enemies/Enemy.h"

Projectile::Projectile(ProjectileType Type, float Damage, float Scale, float Speed, const char* OverridedFilename)
{
	std::cout << m_SpeedX << std::endl;

	m_SpriteFilename = OverridedFilename;
	m_ProjectileType = Type;
	m_Damages = Damage;
	m_Scale = Scale * APP_VIRTUAL_SCALE;
	m_TypeObject = GameObjectType::ProjectileElement;
	m_SpeedX = Speed;
	m_SpeedZ = 0.f;

	switch (m_ProjectileType)
	{
	case ProjectileType::PlayerProjectile:
		m_Width = 20.f * m_Scale;
		m_Height = 20.f * m_Scale;
		m_bUseMultiplierGameManager = false;

		break;

	case ProjectileType::EnemyProjectile:
		m_Width = 15.f * m_Scale;
		m_Height = 15.f * m_Scale;
		m_bUseMultiplierGameManager = true;
		break;

	default:
		break;
	}
	m_SphereCollision = new CircleCollisionComponent(m_Width);
	m_Collision = std::unique_ptr<CollisionComponent>(m_SphereCollision);
}


void Projectile::InitializeGameObjectDatas()
{	
		switch (m_ProjectileType)
		{
		case ProjectileType::PlayerProjectile:
			if (m_SpriteFilename == "")
			{
				m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Projectiles\\playerProjectileSimple.png";
			}
			m_SpriteColumns = 1;
			m_SpriteLines = 4;
			m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
			m_Sprite->CreateAnimation(0, 0.1, { 0,1,2,3 });
			break;

		case ProjectileType::EnemyProjectile:
			if(m_SpriteFilename == "")
			{
				m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Projectiles\\enemyProjectile.png";
			}
			m_SpriteColumns = 1;
			m_SpriteLines = 5;
			m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
			m_Sprite->CreateAnimation(0, 0.1, {0,1,2,3});
			break;

		default:
			break;
		}

		if (m_Sprite)
		{
			m_Sprite->SetScale(m_Scale);
			m_Sprite->SetAnimation(0);
		}
}

void Projectile::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	switch (m_ProjectileType)
	{
	case ProjectileType::PlayerProjectile:
	
		if (this && m_GameManager && m_GameManager->m_MapManager)
		{
			if (m_GameManager && m_GameManager->m_MapManager->m_OldGameplayMap)
			{
				CheckMapCollision(m_GameManager->m_MapManager->m_OldGameplayMap);
			}

			if (m_GameManager && m_GameManager->m_MapManager->m_CurrentGameplayMap)
			{
				CheckMapCollision(m_GameManager->m_MapManager->m_CurrentGameplayMap);
			}

			if (m_GameManager && m_GameManager->m_MapManager->m_NextGameplayMap)
			{
				CheckMapCollision(m_GameManager->m_MapManager->m_NextGameplayMap);
			}
		}
		break;

	case ProjectileType::EnemyProjectile:
		if (this && m_GameManager && m_GameManager->m_Player && m_GameManager->m_Player->m_bIsActivated)
		{
			if (std::find(m_HitObjects.begin(), m_HitObjects.end(), m_GameManager->m_Player) == m_HitObjects.end()) 
			{ // Verif pas déjà touché

				if (this && m_Collision)
				{
					const bool CollideWithPlayer = m_Collision->IsColliding(*m_GameManager->m_Player->m_CapsuleCollision);
					if (CollideWithPlayer && m_GameManager->m_Player->m_LifeManager)
					{
						m_HitObjects.push_back(m_GameManager->m_Player);
						m_GameManager->m_Player->m_LifeManager->ApplyDamage(m_Damages);
						Destroy();
					}
				}
			}
		}
		break;

	default:
		break;
	}
}


void Projectile::Death()
{
 	GameObject::Death();
}


void Projectile::CheckMapCollision(GameplayMap* map)
{
	if (map)
	{
		for (GameObject* object : map->m_GameObjectGameplayMap)
		{
			if (object->m_TypeObject == EnemyElement && object->m_bIsActivated)
			{

				if (std::find(m_HitObjects.begin(), m_HitObjects.end(), object) == m_HitObjects.end())
				{
					if (this && m_Collision)
					{
						bool CollideWithEnemy = false;

						switch (object->m_Collision->m_ShapeType)
						{
						default:
						case ShapeType::Circle:
							CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<CircleCollisionComponent*>(object->m_Collision.get()));
							break;

						case ShapeType::Rectangle:
							CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<RectangleCollisionComponent*>(object->m_Collision.get()));
							break;

						case ShapeType::Capsule:
							CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<CapsuleCollisionComponent*>(object->m_Collision.get()));
							break;
						}

						if (CollideWithEnemy && object->m_LifeManager && !object->m_LifeManager->m_bIsDead)
						{
							m_HitObjects.push_back(object);
							dynamic_cast<Enemy*>(object)->ApplyDamages(m_Damages);
							Death();							
						}
					}
				}
			}
		}
	}
}
