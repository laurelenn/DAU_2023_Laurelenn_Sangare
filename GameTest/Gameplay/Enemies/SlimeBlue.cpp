#include "stdafx.h"
#include "../Gameplay/Enemies/SlimeBlue.h"

SlimeBlue::SlimeBlue()
{
	m_LifeManager = new LifeManager(10.f, 10.f);
	m_Scale = 1.5f;
	m_SphereCollision = new CircleCollisionComponent(27.f * m_Scale);
	m_Collision = std::unique_ptr<CollisionComponent>(m_SphereCollision);
	m_TypeObject = GameObjectType::Enemy;
	m_DamageCollisionPlayer = 200.f;
	m_SpeedX = -150.f;
	m_SpeedZ = 0.f;
	m_SpeedAnimIdle = 7.f;
}

void SlimeBlue::InitializeGameObjectDatas()
{
	m_SpriteColumns = 5;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\slime_blue.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimSlimeBlue::IdleSlimeBlue, m_SpeedAnimIdle / 50.f, {0,1,4,1});

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(AnimSlimeBlue::IdleSlimeBlue);
}


void SlimeBlue::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void SlimeBlue::Death()
{
	// To do 
}
