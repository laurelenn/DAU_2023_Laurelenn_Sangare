#include "stdafx.h"
#include "../Gameplay/Enemies/Pike.h"

Pike::Pike()
{
	m_Scale = 1.5f;
	m_Width = 50.f * m_Scale;
	m_Height = 30.f * m_Scale;
	m_RectangleCollision = new RectangleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_RectangleCollision);
	m_TypeObject = GameObjectType::Obstacle;
	m_DamageCollisionPlayer = 5.f;
	m_SpeedX = 0.f;
	m_SpeedZ = 0.f;
	m_SpeedAnimIdle = 0.f;
	m_DeltaZSprite = -20.f * m_Scale;
	m_MalusScoreOnHit = 50;
}

void Pike::InitializeGameObjectDatas()
{
	m_LifeManager = new LifeManager(10.f);
	m_LifeManager->MakeItInvincible();
	m_SpriteColumns = 1;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\Spikes.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(0, 1, { 1 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(0);
}

void Pike::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void Pike::Death()
{
	Enemy::Death();
}
