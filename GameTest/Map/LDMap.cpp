#include "stdafx.h"
#include "LDMap.h"
#include "../App/app.h"
#include "../Gameplay/GameManager.h"

// Literaly the same as Background (no time for tile system)

LDMap::LDMap(float Speed)
{
	m_SpeedMap = Speed;
}
LDMap::LDMap(float Speed, LDDatasMap Datas)
{
	m_SpeedMap = Speed;
	m_DatasLdMap = Datas;
}


void LDMap::Init()
{
	m_Sprite = App::CreateSprite(".\\Ressources\\LD\\SimpleTileMap.png", 1, 1);
	m_Sprite->SetScale(m_Scale);
}

void LDMap::Update(float deltaTime)
{
	if (m_Sprite)
	{
		float newX = 0.f;
		float newZ = 0.f;
		m_Sprite->GetPosition(newX, newZ);
		newX += ((m_SpeedMap * m_GameManager->m_SpeedMulti / 1000.f) * deltaTime);
		m_Sprite->SetPosition(newX, newZ);
		m_Position.x = newX;
	}
}

void LDMap::Render()
{
	if (m_Sprite)
	{
		m_Sprite->Draw();
	}
}

void LDMap::Destroy()
{
	delete m_Sprite;
	m_Sprite = nullptr;

}

void LDMap::SetPosition(float newX, float newZ)
{
	Map::SetPosition(newX, newZ);
	if (m_Sprite)
	{
		m_Sprite->SetPosition(newX, newZ);
	}
}
