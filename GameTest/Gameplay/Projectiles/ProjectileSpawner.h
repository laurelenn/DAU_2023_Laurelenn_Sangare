#pragma once

#include "Projectile.h"

class ProjectileSpawner :
public GameObject
{

#pragma region VARIABLES

public : 

GameObject* m_Owner;

// Salve
float m_DelaySalvo = 1.f;
int m_NbProjBySalvo = 1;
float m_DelayProjectiles = 0.5f;
bool m_bIsAutomatic = false;
App::Vector2 m_DeltaPos;

// Projectile
ProjectileType m_TypeProjectile = PlayerProjectile;
float m_ScaleProjectile = 1.f;
int m_DamageProjectile = 10;
float m_SpeedProjectile = 20.f;

// Runtime
bool bIsWaitingNextProj = false;
bool bIsWaitingNextSalvo = true;
bool bCanLaunchSalvo = true;
float CurrentTimerSalvo = 0.f;
float CurrentTimerProj = 0.f;
int CurrentProjSalvoLaunched = 0;
std::vector<Projectile*> m_ProjectilesSpawned;

bool bIsFiring = false;

// ProjectileType type, float Damage, float Scale, float Speed
#pragma endregion

#pragma region FUNCTION

ProjectileSpawner(GameObject* owner, App::Vector2 deltaPos, float delaySalvo, int nbProjBySalvo, float delayProjectiles, bool isAutomatic,
    ProjectileType type, float scale, int damage, float speed)
    : m_Owner(owner), m_DeltaPos(deltaPos), m_DelaySalvo(delaySalvo), m_NbProjBySalvo(nbProjBySalvo), m_DelayProjectiles(delayProjectiles),
    m_bIsAutomatic(isAutomatic), m_TypeProjectile(type), m_ScaleProjectile(scale),
    m_DamageProjectile(damage), m_SpeedProjectile(speed), CurrentTimerSalvo(delaySalvo){};

void InitializeGameObjectDatas();

void Update(float deltaTime);

void Render();

void UpdateAutomaticSpawner(float deltaTime);

void UpdateManualSpawner(float deltaTime);

void SpawnProjectile();

void Death() override;

public : 
void LaunchSalvo();


#pragma endregion

};

