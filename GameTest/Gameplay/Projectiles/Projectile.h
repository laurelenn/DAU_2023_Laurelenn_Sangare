#pragma once
#include "../Gameplay/GameObject.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"

enum ProjectileType
{
    PlayerProjectile,
    EnemyProjectile
};

class Projectile :
    public GameObject
{

#pragma region VARIABLES
        CircleCollisionComponent* m_SphereCollision = nullptr;
        ProjectileType m_ProjectileType = ProjectileType::PlayerProjectile;
        std::vector<GameObject*> m_HitObjects;

        public :
        float m_Damages = 10;
#pragma endregion

#pragma region FUNCTIONS

public :  
    Projectile(ProjectileType type, float Damage, float Scale, float Speed);

    void InitializeGameObjectDatas() override;

    void Update(float deltaTime) override;

    void Death() override;
#pragma endregion
};

