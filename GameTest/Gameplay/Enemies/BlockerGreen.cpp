#include "stdafx.h"
#include "../Gameplay/Enemies/BlockerGreen.h"

BlockerGreen::BlockerGreen()
{
	m_RectangleCollision = new RectangleCollisionComponent(35.f, 35.f);
	m_Collision = std::unique_ptr<CollisionComponent>(m_RectangleCollision);
	m_LifeManager = new LifeManager(10.f, 10.f);
	m_Scale = APP_VIRTUAL_SCALE;
	m_TypeObject = GameObjectType::Obstacle;
	m_DamageCollisionPlayer = 200.f;
}

void BlockerGreen::InitializeGameObjectDatas()
{
	m_SpriteColumns = 1;
	m_SpriteLines = 1;
	m_SpriteFilename = ".\\.\\.\\Ressources\\Interactables\\Enemies\\blockerMad.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimBlockerGreen::Idle, m_SpeedAnim / 50.f, { 1 });

	// To do : Create Other Animations

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(AnimBlockerGreen::Idle);
}


void BlockerGreen::Death()
{
// To do 
}
