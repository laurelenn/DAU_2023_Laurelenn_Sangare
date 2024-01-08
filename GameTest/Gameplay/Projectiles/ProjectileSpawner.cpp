#include "stdafx.h"
#include "ProjectileSpawner.h"

void ProjectileSpawner::Init()
{

}

void ProjectileSpawner::Update(float deltaTime)
{
	/*if (m_bIsAutomatic)
	{*/
		UpdateAutomaticSpawner(deltaTime);
	/*}
	else
	{
		UpdateManualSpawner(deltaTime);
	}*/
}

void ProjectileSpawner::UpdateAutomaticSpawner(float deltaTime)
{
	if (bIsWaitingNextSalvo)
	{
		CurrentTimerSalvo+=deltaTime;
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
		CurrentTimerProj+=deltaTime;
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
	new Projectile(m_TypeProjectile, m_DamageProjectile, m_ScaleProjectile, m_SpeedProjectile);

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
