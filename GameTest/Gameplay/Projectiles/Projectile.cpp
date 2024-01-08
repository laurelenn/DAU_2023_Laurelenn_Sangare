#include "stdafx.h"
#include "../Projectiles/Projectile.h"
#include "../GameManager.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"
#include "../Gameplay/Collisions/CapsuleCollisionComponent.h"
#include "../Gameplay/Collisions/RectangleCollisionComponent.h"

Projectile::Projectile(ProjectileType type, float Damage, float Scale, float Speed)
{
	m_ProjectileType = type;
	m_Damages = Damage;
	m_Scale = Scale;
	m_SphereCollision = new CircleCollisionComponent(m_Width);
	m_Collision = std::unique_ptr<CollisionComponent>(m_SphereCollision);
	m_TypeObject = GameObjectType::ProjectileElement;
	m_SpeedX = Speed;
	m_SpeedZ = 0.f;

	switch (m_ProjectileType)
	{
	case ProjectileType::PlayerProjectile: // TODO
		m_Width = 100.f * m_Scale;
		m_Height = 100.f * m_Scale;		
		break;

	case ProjectileType::EnemyProjectile:
		m_Width = 100.f * m_Scale;
		m_Height = 100.f * m_Scale;		
		break;

	default:
		break;
	}
}

void Projectile::InitializeGameObjectDatas()
{
	m_SpriteColumns = 1;
	m_SpriteLines = 1;

	switch (m_ProjectileType)
	{
		case ProjectileType::PlayerProjectile:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Projectiles\\ProjectileUFO.png";
			break;
		case ProjectileType::EnemyProjectile:
			m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Projectiles\\ProjectileShield.png";
			break;
		
		default:
		break;
	}

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, 1, {0});

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);
}

void Projectile::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	switch (m_ProjectileType)
	{
	case ProjectileType::PlayerProjectile:
	
		if (m_GameManager && m_GameManager->m_MapManager)
		{
			if (m_GameManager->m_MapManager->m_OldGameplayMap)
			{
				for (GameObject* object : m_GameManager->m_MapManager->m_OldGameplayMap->m_GameObjectGameplayMap)
				{
					if (object->m_TypeObject == Enemy && object->m_bIsActivated)
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
										//CircleCollisionComponent* castedCircle = ;
										CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<CircleCollisionComponent*>(object->m_Collision.get()));
										break;

									case ShapeType::Rectangle:
										//RectangleCollisionComponent* casterRect = ;
										CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<RectangleCollisionComponent*>(object->m_Collision.get()));
										break;

									case ShapeType::Capsule:
										//CapsuleCollisionComponent* castedCapsule = ;
										CollideWithEnemy = m_Collision->IsColliding(*dynamic_cast<CapsuleCollisionComponent*>(object->m_Collision.get()));
										break;
								}
								
								if (CollideWithEnemy && object->m_LifeManager)
								{
									m_HitObjects.push_back(object);
									object->m_LifeManager->ApplyDamage(m_Damages);
									Destroy();
								}
							}
						}
					}
				}
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
	Destroy();
}
