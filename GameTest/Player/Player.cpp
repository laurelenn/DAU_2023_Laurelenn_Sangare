#include "stdafx.h"

#include "Player.h"
#include "../../GameTest/App/main.h"

Player::Player(int InitialLife, float Height, float Width)
{
	m_CapsuleCollision = new CapsuleCollisionComponent(Width, Height);
	m_CapsuleCollision->m_bDrawdebug = true;
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_LifeManager = new LifeManager(InitialLife, InitialLife);
}

void Player::InitializeGameObjectDatas()
{
	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_RUN, m_SpeedAnimationRun/50.f, {2,8,9,8});
	// To do : Create Other Animations

	/*
		ANIM_JUMP,
		ANIM_CROUNCH,
		ANIM_HIT,
		ANIM_ATTACK,
		ANIM_DEATH
	*/

	m_Sprite->SetScale(0.75f);
	m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);
}
