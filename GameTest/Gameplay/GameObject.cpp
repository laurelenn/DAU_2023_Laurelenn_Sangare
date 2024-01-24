#include "stdafx.h"
#include <iostream>
#include <type_traits>
#include "../Gameplay/Collisions/CollisionComponent.h"
#include "../Map/GameplayMap.h"
#include "../Gameplay/GameManager.h"
#include "GameObject.h"

void GameObject::Init()
{
	Init(App::Vector2());
}

void GameObject::Init(App::Vector2 InitialLocation)
{
	InitializeGameObjectDatas();
	SetPosition(InitialLocation.x, InitialLocation.z);
	if (m_Collision)
	{
		m_Collision->SetOwner(this);
	}
}

void GameObject::InitializeGameObjectDatas()
{
	m_SpriteDeath = App::CreateSprite(m_SpriteFilenameDeath, m_SpriteColumnsDeath, m_SpriteLinesDeath);
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactBlop, 4.0f / 50.f, { 0,1,2,3,4, 4, 9 });
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactCircleExplode, 4.0f / 50.f, {5,6,7,8, 8,9 });
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactCircleStar, 4.0f / 50.f, {10,11,12,13,14, 14,9 });
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactCircle, 4.0f / 50.f, {15,16,17,18,19,19,9 });
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactExplosion, 5.0f / 50.f, {20,21,22,23,24,24,9 });
	m_SpriteDeath->CreateAnimation(AnimImpact::ImpactSimple, 4.0f / 50.f, {25,26,27,28,29,29,9 });

	m_SpriteDeath->SetScale(m_ScaleDeath);
	m_SpriteDeath->SetAnimation(AnimImpact::ImpactBlop);

	//m_DeathSound.Initialize(WindowFromDC(wglGetCurrentDC()));
	//m_DeathSound.LoadWaveFile(m_SoundFilenameDeath);
}

void GameObject::Update(float Deltatime) // ms
{
	if (m_bIsActivated && !m_bIsWaitingEndDeath)
	{
		float NewPosX = m_bUseMultiplierGameManager ? (((m_SpeedX * m_GameManager->m_SpeedMulti) / 1000.f) * Deltatime) : ((m_SpeedX / 1000.f) * Deltatime);
		float NewPosZ = ((m_SpeedZ / 1000.f) * Deltatime);

		if (m_SpeedZ != 0)
		{
			if (m_Location.z + NewPosZ <= m_MinZ || m_Location.z + NewPosZ >= m_MaxZ)
			{
				m_SpeedZ = -m_SpeedZ;
			}
			SetPosition(m_Location.x + NewPosX, CLAMP(m_Location.z + NewPosZ, m_MinZ, m_MaxZ));
		}
		else
		{
			SetPosition(m_Location.x + NewPosX, m_Location.z + NewPosZ);
		}

		if (m_Sprite)
		{
			m_Sprite->Update(Deltatime);
		}

		if (ReachEndMap())
		{
			m_bIsDeathEndOfMap = true;
			if (m_OwnerGameplayMap)
			{
				m_OwnerGameplayMap->GameObjectReachEnd(this);
			}
			Death();
		}
	}
	else if (m_bIsWaitingEndDeath)
	{
		m_CurrentDeathTimer+=Deltatime/1000.f;
		if (m_SpriteDeath)
		{
			m_SpriteDeath->Update(Deltatime);

			if (m_CurrentDeathTimer >= m_DeathDuration)
			{
				m_bIsWaitingEndDeath = false;
				Destroy();
			}
		}
		else
		{
			m_bIsWaitingEndDeath = false;
			Destroy();
		}

		
	}
}

void GameObject::Render()
{
	if (!m_bIsWaitingEndDeath)
	{
		if (m_Sprite)
		{
			m_Sprite->Draw();
		}
	}
	else
	{
		if (m_SpriteDeath)
		{
			m_SpriteDeath->Draw();
		}
	}

	if (m_Collision && m_Collision->m_bDrawdebug && m_Collision->m_bIsActivated)
	{
		m_Collision->DrawDebugCollision();
	}
}

void GameObject::Destroy()
{
	m_GameManager = nullptr;
	m_OwnerGameplayMap = nullptr;

	if (m_SpriteDeath)
	{
		delete m_SpriteDeath;
		m_SpriteDeath = nullptr;
	}

	if (m_Sprite)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}

	if (m_LifeManager)
	{
		delete m_LifeManager;
		m_LifeManager = nullptr;
	}
	m_Collision.reset();

	m_bIsActivated = false;

	//m_DeathSound.Shutdown();
}

void GameObject::SetPosition(float x, float z)
{
	if (m_Sprite)
	{
		m_Sprite->SetPosition(x, z+ m_DeltaZSprite);
	}

	if (m_SpriteDeath)
	{
		m_SpriteDeath->SetPosition(x, z + m_DeltaZSpriteDeath);
	}
	if (m_Collision)
	{
		m_Collision->SetPosition(x, z + m_DeltaZSprite);
	}
	m_Location.x = x;
	m_Location.z = z;


}

bool GameObject::ReachEndMap()
{
	if (m_SpeedX <= 0)
	{
		return m_Location.x <= 0 - m_Width;
	}
	else
	{
		return m_Location.x >= APP_INIT_WINDOW_WIDTH*APP_VIRTUAL_SCALE*1.5f + m_Width;
	}
}

void GameObject::ApplyDamages(float damages)
{ 
   	if (damages >= 0 && !m_LifeManager->m_bIsInvincible)
	{
		m_LifeManager->ApplyDamage(damages);
		if (m_Sprite)
		{
			m_Sprite->StartBlinking(m_BlinkDurationOnHit, m_SpeedBlink);
		}
		if (m_LifeManager->m_bIsDead)
		{
			if (m_bPlayDeathSound)
			{
				App::PlaySound(m_SoundFilenameDeath, false);
			}
			Death();
		}
	}
}

void GameObject::Death()
{
	if (m_Collision)
	{
		m_Collision->m_bIsActivated = false;
	}

	if (!m_bIsDeathEndOfMap)
	{
		m_bIsWaitingEndDeath = true;
	}
	else
	{
		Destroy();
	}
}
