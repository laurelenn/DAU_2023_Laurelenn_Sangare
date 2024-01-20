#include "stdafx.h"
#include "../Gameplay/Enemies/Ghost.h"
#include <algorithm>
#include <random>

Ghost::Ghost()
{
	m_Scale = 1.f;
	m_Width = 25.f * m_Scale;
	m_Height = 40.f * m_Scale;
	m_CapsuleCollision = new CapsuleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_TypeObject = GameObjectType::EnemyElement;
	m_DamageCollisionPlayer = 15.f;
	m_SpeedX = 0.f;
	m_SpeedZ = 100.f;
	m_MaxZ = HEIGHT_FLOOR_1;
	m_MinZ = HEIGHT_FLOOR_0+m_DeltaZSprite,
	m_MalusScoreOnHit = 20;
}

void Ghost::InitializeGameObjectDatas()
{
	Enemy::InitializeGameObjectDatas();
	m_LifeManager = new LifeManager(30.f);
	m_SpriteColumns = 4;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\Ghost.png";

	// Random for animation
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(2.f, 5.f);
	float randomSpeedAnim = dis(gen);
	m_SpeedAnimIdle = randomSpeedAnim;

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, m_SpeedAnimIdle/20.f, { 1,2 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);

	// Random delta pos
	std::random_device rd2;
	std::mt19937 gen2(rd2());
	std::uniform_real_distribution<> dis2(-10.f, 20.f);
	float randomSpeedDelta = dis2(gen2);
	m_SpeedZ += randomSpeedDelta;

	RandomSpeedDirection();
}

void Ghost::Update(float deltaTime)
{ 
	Enemy::Update(deltaTime);
}

void Ghost::Death()
{
	Enemy::Death();
}
