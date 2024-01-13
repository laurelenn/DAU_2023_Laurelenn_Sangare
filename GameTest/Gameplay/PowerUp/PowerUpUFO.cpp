#include "stdafx.h"
#include "PowerUpUFO.h"
#include "../GameManager.h"
#include "../Enemies/Enemy.h"

PowerUpUFO::PowerUpUFO()
{
	m_Scale = 1.5f * APP_VIRTUAL_SCALE;
	m_TypeObject = GameObjectType::ProjectileElement;
	m_SpeedX = 400.f;
	m_SpeedZ = 0.f;
	m_Height = 291.f * m_Scale;
	m_Width = 124.f * m_Scale;
	m_Location.x = 0.f - m_Width;
	m_Location.z = HEIGHT_FLOOR_1;

	m_RectangleCollision = new RectangleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<RectangleCollisionComponent>(m_RectangleCollision);
}

void PowerUpUFO::InitializeGameObjectDatas()
{

	m_SpriteFilename = ".\\.\\.\\Ressources\\Player\\UFO_Ship.png";
	m_SpriteColumns = 1;
	m_SpriteLines = 1;
	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, 1, {0});
	if (m_Sprite)
	{
		m_Sprite->SetScale(m_Scale);
		m_Sprite->SetAnimation(0);
	}
}

void PowerUpUFO::Update(float Deltatime)
{
	GameObject::Update(Deltatime);
	if (this && m_GameManager && m_GameManager->m_MapManager)
	{
		if (m_GameManager && m_GameManager->m_MapManager->m_OldGameplayMap)
		{
			CheckCollisionEnemies(m_GameManager->m_MapManager->m_OldGameplayMap);
		}

		if (m_GameManager && m_GameManager->m_MapManager->m_CurrentGameplayMap)
		{
			CheckCollisionEnemies(m_GameManager->m_MapManager->m_CurrentGameplayMap);
		}

		if (m_GameManager && m_GameManager->m_MapManager->m_NextGameplayMap)
		{
			CheckCollisionEnemies(m_GameManager->m_MapManager->m_NextGameplayMap);
		}
	}
}

void PowerUpUFO::CheckCollisionEnemies(GameplayMap* map)
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
							dynamic_cast<Enemy*>(object)->ApplyDamages(999);
						}
					}
				}
			}
		}
	}
}
