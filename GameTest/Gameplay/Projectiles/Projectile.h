#pragma once
#include "../Gameplay/GameObject.h"
#include "../Gameplay/Collisions/CircleCollisionComponent.h"


class GameplayMap;

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
        float m_Damages = 10.f;
#pragma endregion

#pragma region FUNCTIONS

public :  
    Projectile(ProjectileType type, float Damage, float Scale, float Speed, const char* overridedFilename);

    void InitializeGameObjectDatas();

    void Update(float deltaTime) override;

    void CheckMapCollision(GameplayMap* map);

    void Death() override;
#pragma endregion
};

