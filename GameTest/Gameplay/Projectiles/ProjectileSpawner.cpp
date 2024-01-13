#include "stdafx.h"
#include "ProjectileSpawner.h"

void ProjectileSpawner::InitializeGameObjectDatas()
{
	CurrentTimerSalvo = m_DelaySalvo;
	if (m_Collision)
	{
		m_Collision->m_bIsActivated = false;
	}
}

void ProjectileSpawner::Update(float deltaTime)
{
	for (Projectile* proj : m_ProjectilesSpawned)
	{
		if (proj)
		{
			proj->Update(deltaTime);
		}
	}
	/*if (m_bIsAutomatic)
	{*/
		SetPosition(m_Owner->m_Location.x+m_DeltaPos.x, m_Owner->m_Location.z + m_DeltaPos.z);
		UpdateAutomaticSpawner(deltaTime);
		
	/*}
	else
	{
		UpdateManualSpawner(deltaTime);
	}*/
}

void ProjectileSpawner::Render()
{
	for (Projectile* proj : m_ProjectilesSpawned)
	{
		if (proj)
		{
 			proj->Render();
		}
	}
}

void ProjectileSpawner::UpdateAutomaticSpawner(float deltaTime)
{
 	if (bIsWaitingNextSalvo)
	{
		CurrentTimerSalvo+=deltaTime/1000.f;
		if (CurrentTimerSalvo >= m_DelaySalvo)
		{
			bCanLaunchSalvo = true;
			if (m_bIsAutomatic)
			{
				LaunchSalvo();
			}
			else if (bIsFiring)
			{
				LaunchSalvo();
			}
		}
	}

	if (bIsWaitingNextProj)
	{
		CurrentTimerProj+=deltaTime / 1000.f;
		if (CurrentTimerProj >= m_DelayProjectiles)
		{
			SpawnProjectile();
		}
	}
}

void ProjectileSpawner::UpdateManualSpawner(float deltaTime)
{
//	if (bIsWaitingNextSalvo)
//	{
//		CurrentTimerSalvo += deltaTime;
//		if (CurrentTimerSalvo >= m_DelaySalvo)
//		{
//			bCanLaunchSalvo = true;
//		}
//	}
//
//	if (bIsWaitingNextProj)
//	{
//		CurrentTimerProj += deltaTime;
//		if (CurrentTimerProj >= m_DelayProjectiles)
//		{
//			SpawnProjectile();
//		}
//	}
}


void ProjectileSpawner::LaunchSalvo()
{
	CurrentTimerSalvo = 0.f;
	bIsWaitingNextSalvo = false;
	CurrentProjSalvoLaunched = 0;
	bCanLaunchSalvo = false;

	SpawnProjectile();
}

void ProjectileSpawner::SpawnProjectile()
{
	Projectile* proj = new Projectile(m_TypeProjectile, m_DamageProjectile, m_ScaleProjectile, m_SpeedProjectile, m_FilenameProjectile);
	proj->SetGameManager(m_Owner->m_GameManager);
	proj->Init(App::Vector2{m_Location.x, m_Location.z});
	m_ProjectilesSpawned.push_back(proj);

	CurrentTimerProj = 0.f;
	CurrentProjSalvoLaunched++;
	if (CurrentProjSalvoLaunched >= m_NbProjBySalvo)
	{
		bIsWaitingNextProj = false;
		bIsWaitingNextSalvo = true;
	}
	else
	{
		bIsWaitingNextProj = true;
	}
}

void ProjectileSpawner::Death()
{ 
	for (Projectile* proj : m_ProjectilesSpawned)
	{
		if (proj)
		{
			proj->Destroy();
			delete proj;
			proj = nullptr;
		}
	}
	m_ProjectilesSpawned.clear();
	GameObject::Death();
}
