#pragma once

#include "Projectile.h"

class ProjectileSpawner
{

#pragma region VARIABLES

public : 
// Salve
float m_DelaySalvo = 1.f;
int m_NbProjBySalvo = 1;
float m_DelayProjectiles = 0.5f;
bool m_bIsAutomatic = false;

// Projectile
ProjectileType m_TypeProjectile = PlayerProjectile;
float m_ScaleProjectile = 1.f;
int m_DamageProjectile = 10;
float m_SpeedProjectile = 20.f;

// Runtime
bool bIsWaitingNextProj = false;
bool bIsWaitingNextSalvo = false;
bool bCanLaunchSalvo = true;
float CurrentTimerSalvo = 0.f;
float CurrentTimerProj = 0.f;
int CurrentProjSalvoLaunched = 0;

bool bIsFiring = false;

// ProjectileType type, float Damage, float Scale, float Speed
#pragma endregion

#pragma region FUNCTION

ProjectileSpawner(float delaySalvo, int nbProjBySalvo, float delayProjectiles, bool isAutomatic,
    ProjectileType type, float scale, int damage, float speed)
    : m_DelaySalvo(delaySalvo), m_NbProjBySalvo(nbProjBySalvo), m_DelayProjectiles(delayProjectiles),
    m_bIsAutomatic(isAutomatic), m_TypeProjectile(type), m_ScaleProjectile(scale),
    m_DamageProjectile(damage), m_SpeedProjectile(speed),
    bIsWaitingNextProj(false), bIsWaitingNextSalvo(false), bCanLaunchSalvo(true),
    CurrentTimerSalvo(0.0f), CurrentTimerProj(0.0f){};

void Init();

void Update(float deltaTime);

void UpdateAutomaticSpawner(float deltaTime);

void UpdateManualSpawner(float deltaTime);

void SpawnProjectile();

public : 
void LaunchSalvo();


#pragma endregion

};

