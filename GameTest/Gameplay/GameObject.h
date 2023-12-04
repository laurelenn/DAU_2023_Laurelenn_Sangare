#pragma once
#include "../App/SimpleSprite.h"
#include "../App/app.h"
#include "../Gameplay/Collisions/CollisionComponent.h"
#include "../Gameplay/LifeManager.h"

#include <iostream>
#include <memory>

class GameObject
{

#pragma region VARIABLES

public:


App::Vector2 m_Location;
float m_SpeedX;
float m_SpeedZ;

CSimpleSprite* m_Sprite;
const char* m_SpriteFilename;
int m_SpriteColumns;
int m_SpriteLines;
LifeManager* m_LifeManager;

std::unique_ptr<CollisionComponent> m_Collision;
bool m_bIsActivated = false;

#pragma endregion

#pragma region FUNCTIONS

public :
~GameObject() {};

void Init();
void Init(App::Vector2 InitialLocation);
virtual void InitializeGameObjectDatas() = 0;
virtual void Update(float Deltatime);
void Render();
void Destroy();
void SetActivated(bool Activate){m_bIsActivated = Activate;}
void SetPosition(float x, float z);

#pragma endregion

};

