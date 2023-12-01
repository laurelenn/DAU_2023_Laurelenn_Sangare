#include "stdafx.h"

#include "Player.h"
#include "../../GameTest/App/main.h"

Player::Player(int InitialLife, float Height, float Width, float Scale)
{
	m_CapsuleCollision = new CapsuleCollisionComponent(Width, Height);
	m_CapsuleCollision->m_bDrawdebug = true;
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_LifeManager = new LifeManager(InitialLife, InitialLife);
	m_Scale = Scale;
}

void Player::InitializeGameObjectDatas()
{
	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_RUN, m_SpeedAnimationRun/50.f, {2,8,9,8});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_JUMP, m_SpeedAnimationRun/50.f, {13});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_HIT, m_SpeedAnimationRun/50.f, {6});
	// To do : Create Other Animations

	/*
		ANIM_CROUNCH,
		ANIM_ATTACK,
		ANIM_DEATH
	*/

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);
}
