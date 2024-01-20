#include "stdafx.h"
#include "../Gameplay/Enemies/Bee.h"
#include <algorithm>
#include <random>

Bee::Bee()
{
	m_Scale = 1.f;
	m_Width = 25.f * m_Scale;
	m_Height = 40.f * m_Scale;
	m_CircleCollision = new CircleCollisionComponent(m_Width);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CircleCollision);
	m_TypeObject = GameObjectType::EnemyElement;
	m_DamageCollisionPlayer = 10.f;
	m_SpeedX = -250.f;
	m_SpeedZ = 250.f;
	m_MaxZ = HEIGHT_FLOOR_0*3.5f;
	m_MinZ = HEIGHT_FLOOR_0,
	m_MalusScoreOnHit = 10;
}

void Bee::InitializeGameObjectDatas()
{
	Enemy::InitializeGameObjectDatas();
	m_LifeManager = new LifeManager(30.f);
	m_SpriteColumns = 4;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\Bee.png";

	m_SpeedAnimIdle = 3.f;


	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, m_SpeedAnimIdle / 20.f, { 1,2 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);

	RandomSpeedDirection();
}

void Bee::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void Bee::Death()
{
	Enemy::Death();
}
