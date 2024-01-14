#pragma once
#include "../App/SimpleSprite.h"
#include "../App/app.h"
#include "../Gameplay/Collisions/CollisionComponent.h"
#include "../Gameplay/LifeManager.h"
#include "../App/AppSettings.h"

#include <iostream>
#include <memory>

enum GameObjectType 
{
	Pawn,
	EnemyElement,
	ProjectileElement,
	Obstacle,
	Tile,
	Hole,
	PowerUpBonus
};

class GameManager;
class GameplayMap;
class GameObject
{

#pragma region VARIABLES

public:

GameManager *m_GameManager = nullptr;
GameplayMap *m_OwnerGameplayMap = nullptr;
LifeManager* m_LifeManager;
std::unique_ptr<CollisionComponent> m_Collision;

GameObjectType m_TypeObject;

App::Vector2 m_Location;
float m_SpeedX;
float m_SpeedZ;
float m_MinZ = HEIGHT_FLOOR_0;
float m_MaxZ = 3.f*HEIGHT_FLOOR_0;
bool m_bUseMultiplierGameManager = false;
float m_DeltaZSprite = 0.0f;

float m_Scale = 1.f;
float m_Width;
float m_Height;

CSimpleSprite* m_Sprite;
const char* m_SpriteFilename;
int m_SpriteColumns;
int m_SpriteLines;

bool m_bIsActivated = true;
#pragma endregion

#pragma region FUNCTIONS

public :
~GameObject() {};
void SetGameManager(GameManager* gameManager){ m_GameManager  = gameManager;}

void Init();
void Init(App::Vector2 InitialLocation);
virtual void InitializeGameObjectDatas() = 0;
virtual void Update(float Deltatime);
void Render();
void Destroy();
void SetActivated(bool Activate){m_bIsActivated = Activate;}
void SetPosition(float x, float z);
bool ReachEndMap();

void ApplyDamages(float damages);
virtual void Death();

#pragma endregion

};

