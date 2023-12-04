#include "stdafx.h"

#include "Player.h"
#include "../../GameTest/App/main.h"

Player::Player(float InitialLife, float Height, float Width, float Scale)
{
	m_CapsuleCollision = new CapsuleCollisionComponent(Width, Height);
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

void Player::Update(float Deltatime)
{
	GameObject::Update(Deltatime);

	if (App::IsKeyPressed(APP_KEYBOARD_JUMP_KEY) && !m_bIsJumping)
	{
		Jump();
	}

	if (m_bIsJumping)
	{
		float jumpDistance = m_SpeedJump/10.f * Deltatime;

		if (m_Location.z >= m_HeightJumpCurrentLevel && !m_bIsJumpingDown)
		{
			m_bIsJumpingDown = true;
		}
		jumpDistance = m_bIsJumpingDown ? -jumpDistance : jumpDistance; // Change direction if max height reached

		m_Location.z = CLAMP(m_Location.z += jumpDistance, m_CurrentFloorLevel, m_HeightJumpCurrentLevel);
		
		if (m_Location.z <= m_CurrentFloorLevel)
		{
			EndJump();
		}
	}
}

void Player::Jump()
{
	m_bIsJumping =  true;
	m_HeightJumpCurrentLevel = m_CurrentFloorLevel + m_HeightJump;
	m_Sprite->SetAnimation(AnimPlayer::ANIM_JUMP);
}

void Player::EndJump()
{
	m_bIsJumping = false;
	m_bIsJumpingDown = false;
	m_Location.z = m_CurrentFloorLevel; // Doble check to restart at good location
	m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);

}
