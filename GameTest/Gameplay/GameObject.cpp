#include "stdafx.h"
#include <iostream>
#include <type_traits>
#include "../App/app.h"
#include "../Gameplay/Collisions/CollisionComponent.h"
#include "GameObject.h"

void GameObject::Init()
{
	Init(App::Vector2());
}

void GameObject::Init(App::Vector2 InitialLocation)
{
	InitializeGameObjectDatas();
	SetPosition(InitialLocation.x, InitialLocation.z);
}

void GameObject::Update(float Deltatime) // ms
{
	if (m_bIsActivated)
	{
		int NewPosX = (int)(m_SpeedX * (Deltatime / 1000.f));
		int NewPosZ = (int)(m_SpeedZ * (Deltatime / 1000.f));
		SetPosition(m_Location.x+NewPosX, m_Location.z+NewPosZ);
		if (m_Sprite)
		{
			m_Sprite->Update(Deltatime);
		}

		if (m_Collision && m_Collision->m_bDrawdebug)
		{
			m_Collision->DrawDebugCollision();
		}
	}
}

void GameObject::Render()
{
	if (m_Sprite)
	{
		m_Sprite->Draw();
	}
}

void GameObject::Destroy()
{
delete m_Sprite;
m_Collision.reset(nullptr);
delete this;
}

void GameObject::SetPosition(float x, float z)
{
	if (m_Sprite)
	{
		m_Sprite->SetPosition(x, z);
	}
	if (m_Collision)
	{
		m_Collision->SetPosition(x, z);
	}
	m_Location.x = x;
	m_Location.z = z;
}