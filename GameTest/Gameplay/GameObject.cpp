#include "stdafx.h"
#include <iostream>
#include <type_traits>
#include "../App/app.h"
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
		m_CurrentDeathTimer+=Deltatime;
		if (m_SpriteDeath)
		{
			m_Sprite->Update(Deltatime);
		}

		if (m_CurrentDeathTimer >= m_DeathDuration)
		{
			m_bIsWaitingEndDeath = false;
			Destroy();
		}
	}
}

void GameObject::Render()
{
	if (m_Sprite)
	{
		m_Sprite->Draw();
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
}

void GameObject::SetPosition(float x, float z)
{
	if (m_Sprite)
	{
		m_Sprite->SetPosition(x, z+ m_DeltaZSprite);
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
   	if (damages >= 0)
	{
		m_LifeManager->ApplyDamage(damages);
		if (m_LifeManager->m_bIsDead)
		{
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

	if (m_bIsDeathEndOfMap)
	{
		m_bIsWaitingEndDeath = true;
	}
	else
	{
		Destroy();
	}
}
