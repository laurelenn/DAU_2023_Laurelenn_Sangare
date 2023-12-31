#include "stdafx.h"

#include "Player.h"
#include "../Gameplay/GameManager.h"



Player::Player(float InitialLife, float Scale)
{
	m_Width = 35.f * PLAYER_SCALE;
	m_Height = 35.f *PLAYER_SCALE;
	m_CapsuleCollision = new CapsuleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_LifeManager = new LifeManager(InitialLife, InitialLife);
	m_Scale = Scale;
	m_TypeObject = GameObjectType::Pawn;
}


void Player::InitializeGameObjectDatas()
{

	m_SpriteColumns = 7;
	m_SpriteLines = 3;
	m_SpriteFilename = ".\\.\\Ressources\\Player\\p1_spritesheet.png";

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

void Player::Update(float deltaTime)
{
    GameObject::Update(deltaTime);

    if (App::IsKeyPressed(APP_KEYBOARD_JUMP_KEY) && !m_bIsJumping)
    {
        Jump();
    }

    if (m_bIsJumping)
    {
		UpdateJump(deltaTime);
	}
}

void Player::UpdateJump(float Deltatime)
{
    if (m_bIsJumping)
    {
        float jumpDistance = (m_CurrentSpeedJump / 10.f) * Deltatime;

        if (m_Location.z >= m_HeightJumpCurrentLevel && !m_bIsJumpingDown)
        {
            m_bIsJumpingDown = true;
        }

        // Gestion de la phase de descente et accélération
        if (m_bIsJumpingDown)
        {
            // Vérifier le délai d'inertie
            if (m_CurrentTimerJumpInertia < m_DelayJumpInertia)
            {
                m_CurrentTimerJumpInertia += Deltatime/1000.f; // Incrémentation du minuteur
                m_CurrentSpeedJump = CLAMP(m_CurrentSpeedJump *= 0.8f, 0.3f, m_InitialSpeedJump);
            }
            else // Si le délai est écoulé, accélération pendant la descente
            {
                m_CurrentSpeedJump = CLAMP(m_CurrentSpeedJump *= 1.05f, 0.5f, m_InitialSpeedJump);
            }
        }

        jumpDistance = m_bIsJumpingDown ? -jumpDistance : jumpDistance; // Change direction if max height reached

        m_Location.z = CLAMP(m_Location.z += jumpDistance, m_CurrentFloorLevel, m_HeightJumpCurrentLevel);

        if (m_Location.z <= m_CurrentFloorLevel)
        {
            m_CurrentTimerJumpInertia = 0.0f;
            EndJump();
        }
    }
}



void Player::Jump()
{
	m_CurrentSpeedJump = m_InitialSpeedJump;
	m_bIsJumping =  true;
	m_HeightJumpCurrentLevel = m_CurrentFloorLevel + m_HeightJump;
	m_HeightConstantSpeed = m_HeightJumpCurrentLevel*0.95f;
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
	if (m_LifeManager->m_bIsDead && m_GameManager)
	{
		m_GameManager->GameOver();
	}
}
