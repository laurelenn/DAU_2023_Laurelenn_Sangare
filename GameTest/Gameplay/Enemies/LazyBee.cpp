#include "stdafx.h"
#include "LazyBee.h"
#include <algorithm>
#include <random>

LazyBee::LazyBee()
{
	m_Scale = 1.f;
	m_Width = 25.f * m_Scale;
	m_Height = 40.f * m_Scale;
	m_CircleCollision = new CircleCollisionComponent(m_Width);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CircleCollision);
	m_TypeObject = GameObjectType::EnemyElement;
	m_DamageCollisionPlayer = 5.f;
	m_SpeedX = -200.f;
	m_SpeedZ = 0.f;
	m_MalusScoreOnHit = 5;
}

void LazyBee::InitializeGameObjectDatas()
{
	Enemy::InitializeGameObjectDatas();
	m_LifeManager = new LifeManager(30.f);
	m_SpriteColumns = 4;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\Bee2.png";
	m_SpeedAnimIdle = 3.f;

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, m_SpeedAnimIdle / 20.f, { 1,2 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);
}
