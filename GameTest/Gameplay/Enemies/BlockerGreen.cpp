#include "stdafx.h"
#include "../Gameplay/Enemies/BlockerGreen.h"

BlockerGreen::BlockerGreen()
{
	m_LifeManager = new LifeManager(10.f, 10.f);
	m_Scale = 1.5f;
	m_Width = 45.f * m_Scale;
	m_Height = 45.f * m_Scale;
	m_RectangleCollision = new RectangleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_RectangleCollision);
	m_TypeObject = GameObjectType::Obstacle;
	m_DamageCollisionPlayer = 200.f;
	m_SpeedX = 0.f;
	m_SpeedZ = 0.f;
	m_SpeedAnimIdle = 0.f;
}

void BlockerGreen::InitializeGameObjectDatas()
{
	m_SpriteColumns = 1;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\blockerMad.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimBlockerGreen::IdleBlockerGreen, m_SpeedAnimIdle / 50.f, { 0 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(AnimBlockerGreen::IdleBlockerGreen);
}

void BlockerGreen::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void BlockerGreen::Death()
{
// To do 
}
