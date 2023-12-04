#include "stdafx.h"

#include "Player.h"
#include "../../GameTest/App/main.h"



Player::Player(float InitialLife, float Height, float Width, float Scale)
{
	m_CapsuleCollision = new CapsuleCollisionComponent(Width, Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_LifeManager = new LifeManager(InitialLife, InitialLife);
	m_Scale = Scale;
	m_TypeObject = GameObjectType::Pawn;
}

void Player::InitializeGameObjectDatas()
{
	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_RUN, m_SpeedAnimationRun/50.f, {2,8,9,8});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_JUMP, m_SpeedAnimationRun/50.f, {13});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_HIT, m_SpeedAnimationRun/50.f, {6});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_ONFLOOR, m_SpeedAnimationRun/50.f, {12});
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
		float jumpDistance = (m_CurrentSpeedJump/10.f) * Deltatime;

		if (m_Location.z >= m_HeightJumpCurrentLevel && !m_bIsJumpingDown)
		{
			m_bIsJumpingDown = true;
		}

		if (!m_bIsJumpingDown) // UP
		{
			if (m_Location.z < m_HeightConstantSpeed)
			{
				m_CurrentSpeedJump = CLAMP(m_CurrentSpeedJump *= 0.7f, 1.f, m_InitialSpeedJump);
			}
		}
		else // DOWN
		{
			m_CurrentSpeedJump = CLAMP(m_CurrentSpeedJump *= 0.5f, 1.f, m_InitialSpeedJump);
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
	m_CurrentSpeedJump = m_InitialSpeedJump;
	m_bIsJumping =  true;
	m_HeightJumpCurrentLevel = m_CurrentFloorLevel + m_HeightJump;
	m_HeightConstantSpeed = m_HeightJumpCurrentLevel/1.5f;
	m_Sprite->SetAnimation(AnimPlayer::ANIM_JUMP);
}

void Player::EndJump()
{
	m_bIsJumping = false;
	m_bIsJumpingDown = false;
	m_Location.z = m_CurrentFloorLevel; // Doble check to restart at good location
	m_CurrentSpeedJump = m_InitialSpeedJump;

	m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);
}

void Player::Death()
{
	if (m_LifeManager->m_bIsDead /* && m_GameManager*/)
	{
		//m_GameManager->GameOver();
	}
}
