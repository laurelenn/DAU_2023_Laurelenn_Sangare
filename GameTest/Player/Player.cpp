#include "stdafx.h"

#include "Player.h"
#include "../Gameplay/GameManager.h"
#include "../Gameplay/Projectiles/ProjectileSpawner.h"
#include "../Gameplay/PowerUp/PowerUpUFO.h"


Player::Player(float InitialLife, float Scale)
{
	m_Width = 35.f * PLAYER_SCALE;
	m_Height = 35.f *PLAYER_SCALE;
	m_CapsuleCollision = new CapsuleCollisionComponent(m_Width, m_Height);
	m_Collision = std::unique_ptr<CollisionComponent>(m_CapsuleCollision);
	m_LifeManager = new LifeManager(InitialLife);
	m_Scale = Scale;
	m_TypeObject = GameObjectType::Pawn;
}


void Player::InitializeGameObjectDatas()
{
	GameObject::InitializeGameObjectDatas();

	m_SpriteColumns = 7;
	m_SpriteLines = 3;
	m_SpriteFilename = ".\\.\\Ressources\\Player\\p1_spritesheet.png";

	m_Sprite = App::CreateSprite(m_SpriteFilename, m_SpriteColumns, m_SpriteLines);
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_RUN, m_SpeedAnimationRun/50.f, {2,8,9,8});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_JUMP, m_SpeedAnimationRun/50.f, {13});
	m_Sprite->CreateAnimation(AnimPlayer::ANIM_HIT, 6.f/50.f, {6,16});

	m_Sprite->SetScale(m_Scale);
	m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);

	m_SpriteDeath->SetScale(m_Scale*3.f);
	m_DeltaZSpriteDeath = 25.f;
	m_SpriteDeath->SetAnimation(AnimImpact::ImpactExplosion);

	m_ProjectileSpawner = new ProjectileSpawner(this, App::Vector2{}, 2.f, 3, 0.5f, false, ProjectileType::PlayerProjectile, PLAYER_SCALE*2.f, 10, 500.f);
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

	if (m_ProjectileSpawner)
	{
		if (App::IsKeyPressed(APP_KEYBOARD_FIRE_KEY))
		{
			if (m_ProjectileSpawner->bCanLaunchSalvo)
			{
				m_ProjectileSpawner->bIsFiring = true;
			}
		}
		else
		{
			m_ProjectileSpawner->bIsFiring = false;
		}
		m_ProjectileSpawner->Update(deltaTime);
	}

	UpdatePowerUp(deltaTime);
}




void Player::Render()
{
	GameObject::Render();
	if (m_ProjectileSpawner)
	{
		m_ProjectileSpawner->Render();
	}
	if (m_PowerUpEffectShield.activated)
	{
		App::DrawCircle(30, m_CapsuleCollision->m_Rectangle.m_RectSize.z+20.f, m_Location, 0.28f, 0.8f, 0.87f);
	}

	if (m_PowerUpEffectUFO)
	{
		m_PowerUpEffectUFO->Render();
	}
}

#pragma region POWERUP
void Player::ActivatePowerUp(PowerUpType type)
{
	switch (type)
	{
		case PowerUpType::UFO:
			if (m_PowerUpEffectUFO == nullptr)
			{
				m_PowerUpEffectUFO = new PowerUpUFO();
				if (m_PowerUpEffectUFO)
				{
					m_PowerUpEffectUFO->SetGameManager(m_GameManager);
					m_PowerUpEffectUFO->m_Player = this;
					m_PowerUpEffectUFO->Init(App::Vector2(0.f - m_PowerUpEffectUFO->m_Width, HEIGHT_FLOOR_1));
				}
			}
		break;
		case PowerUpType::Shield:
			if (!m_PowerUpEffectShield.activated)
			{
				m_PowerUpEffectShield.activated = true;
				m_PowerUpEffectShield.currentDelay = 0.f;
				if (m_LifeManager)
				{
					m_LifeManager->MakeItInvincible();
				}
			}
			else
			{
				m_PowerUpEffectShield.currentDelay = 0.f;
			}
			break;
		case PowerUpType::FireRate:
			if (!m_PowerUpEffectRate.activated)
			{
				m_PowerUpEffectRate.activated = true;
				m_PowerUpEffectRate.currentDelay = 0.f;
				if (m_ProjectileSpawner)
				{
					m_ProjectileSpawner->m_NbProjBySalvo *= 2;
					m_ProjectileSpawner->m_DelayProjectiles /= 2;
				}
			}
			else
			{
				m_PowerUpEffectRate.currentDelay = 0.f;
			}
			break;
		case PowerUpType::FireDamage:
			if (!m_PowerUpEffectDamage.activated)
			{
				m_PowerUpEffectDamage.activated = true;
				m_PowerUpEffectDamage.currentDelay = 0.f;
				if (m_ProjectileSpawner)
				{
					m_ProjectileSpawner->m_DamageProjectile *= 2;
					m_ProjectileSpawner->m_ScaleProjectile *= 1.5f;
					m_ProjectileSpawner->m_FilenameProjectile = ".\\.\\Ressources\\Interactables\\Projectiles\\playerProjectileBig.png";
				}
			}
			else
			{
				m_PowerUpEffectDamage.currentDelay = 0.f;
			}
			break;
		default:
		case PowerUpType::BonusLife:
			if (m_LifeManager && !m_LifeManager->m_bIsDead)
			{
				m_LifeManager->Heal(30);
			}
			break;
	}

}

void Player::UpdatePowerUp(float Deltatime)
{
	if (m_PowerUpEffectShield.activated)
	{
		m_PowerUpEffectShield.currentDelay += Deltatime / 1000.f;
		if (m_PowerUpEffectShield.currentDelay >= m_PowerUpEffectShield.duration)
		{
			DeactivatePowerUp(m_PowerUpEffectShield.type);
		}
	}


	if (m_PowerUpEffectRate.activated)
	{
		m_PowerUpEffectRate.currentDelay += Deltatime / 1000.f;
		if (m_PowerUpEffectRate.currentDelay >= m_PowerUpEffectRate.duration)
		{
			DeactivatePowerUp(m_PowerUpEffectRate.type);
		}
	}

	if (m_PowerUpEffectDamage.activated)
	{
		m_PowerUpEffectDamage.currentDelay += Deltatime / 1000.f;
		if (m_PowerUpEffectDamage.currentDelay >= m_PowerUpEffectDamage.duration)
		{
			DeactivatePowerUp(m_PowerUpEffectDamage.type);
		}
	}

	if (m_PowerUpEffectUFO)
	{
		m_PowerUpEffectUFO->Update(Deltatime);
	}
}

void Player::DeactivatePowerUp(PowerUpType type)
{
	switch (type)
	{
	case PowerUpType::Shield:
		if (m_PowerUpEffectShield.activated)
		{
			m_PowerUpEffectShield.activated = false;
			m_PowerUpEffectShield.currentDelay = 0.f;
			if (m_LifeManager)
			{
				m_LifeManager->MakeItVulnerable();
			}
		}
		break;
	case PowerUpType::FireRate:
		if (m_PowerUpEffectRate.activated)
		{
			m_PowerUpEffectRate.activated = false;
			m_PowerUpEffectRate.currentDelay = 0.f;
			if (m_ProjectileSpawner)
			{
				m_ProjectileSpawner->m_NbProjBySalvo /= 2;
				m_ProjectileSpawner->m_DelayProjectiles *= 2;
			}
		}
		break;
	case PowerUpType::FireDamage:
		if (m_PowerUpEffectDamage.activated)
		{
			m_PowerUpEffectDamage.activated = false;
			m_PowerUpEffectDamage.currentDelay = 0.f;
			if (m_ProjectileSpawner)
			{
				m_ProjectileSpawner->m_DamageProjectile /= 2;
				m_ProjectileSpawner->m_ScaleProjectile /= 1.5f;
				m_ProjectileSpawner->m_FilenameProjectile = ".\\.\\Ressources\\Interactables\\Projectiles\\playerProjectileSimple.png";
			}
		}
		break;
	default:
	case PowerUpType::UFO:
	case PowerUpType::BonusLife:
		break;
	}
}

#pragma endregion

#pragma region JUMP
void Player::Jump()
{
	m_CurrentSpeedJump = m_InitialSpeedJump;
	m_bIsJumping =  true;
	m_HeightJumpCurrentLevel = m_CurrentFloorLevel + m_HeightJump;
	m_HeightConstantSpeed = m_HeightJumpCurrentLevel*0.95f;
	m_Sprite->SetAnimation(AnimPlayer::ANIM_JUMP);
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
				m_CurrentTimerJumpInertia += Deltatime / 1000.f; // Incrémentation du minuteur
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

void Player::EndJump()
{
	m_bIsJumping = false;
	m_bIsJumpingDown = false;
	m_Location.z = m_CurrentFloorLevel; // Doble check to restart at good location
	m_CurrentSpeedJump = m_InitialSpeedJump;

	if (m_Sprite)
	{
		m_Sprite->SetAnimation(AnimPlayer::ANIM_RUN);
	}
}
#pragma endregion


void Player::Death()
{
	GameObject::Death();
	if (m_LifeManager->m_bIsDead && m_GameManager)
	{
		m_GameManager->AskGameOver();
	}
}

void Player::Destroy()
{	
	if (m_ProjectileSpawner)
	{
		m_ProjectileSpawner->Death();
		delete m_ProjectileSpawner;
		m_ProjectileSpawner = nullptr;
	}
	GameObject::Destroy();
}
