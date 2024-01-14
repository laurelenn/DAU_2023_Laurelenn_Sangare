#include "stdafx.h"
#include "../Gameplay/Enemies/BlockerGreen.h"

BlockerGreen::BlockerGreen()
{
	m_Scale = 1.5f;
	m_Width = 45.f * m_Scale;
	m_Height = 45.f * m_Scale;
	m_RectangleCollision = new RectangleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_RectangleCollision);
	m_TypeObject = GameObjectType::EnemyElement;
	m_DamageCollisionPlayer = 5.f;
	m_SpeedX = 0.f;
	m_SpeedZ = 0.f;
	m_SpeedAnimIdle = 0.f;
	m_ScoreOnKill = 5;
	m_DeltaZSprite = -10.f * m_Scale;

}

void BlockerGreen::InitializeGameObjectDatas()
{
	m_LifeManager = new LifeManager(10.f);
	m_SpriteColumns = 3;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\blockerMad.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimBlockerGreen::IdleBlockerGreen, 1, { 2 });

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
	Enemy::Death();
}
