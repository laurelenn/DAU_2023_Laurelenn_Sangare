#include "stdafx.h"
#include "BackgroundMap.h"
#include "../App/app.h"

BackgroundMap::BackgroundMap(float Speed)
{
	m_SpeedMap = Speed;
}

BackgroundMap::BackgroundMap(float Speed, BackgroundDatasMap Datas)
{
	m_SpeedMap = Speed;
	m_DatasBgMap = Datas;
}

void BackgroundMap::Init()
{
// To do : use datasbgmap filename

	m_Sprite = App::CreateSprite("../Ressources/Background/swamp.png", 1, 1);
	m_Sprite->SetScale(2.f);
}

void BackgroundMap::Update(float deltaTime)
{
	// To do : Set position
	if (m_Sprite)
	{
		float newX = 0.f;
		float newZ = 0.f;
		m_Sprite->GetPosition(newX, newZ);
		newX = (m_SpeedMap * (deltaTime / 1000.f));
		m_Sprite->SetPosition(newX, newZ);
	}
}

void BackgroundMap::Render()
{
	if (m_Sprite)
	{
		m_Sprite->Draw();
	}
}

void BackgroundMap::Destroy()
{
// To do 
}

void BackgroundMap::SetPosition(float newX, float newZ)
{
	Map::SetPosition(newX, newZ);
	m_Sprite->SetPosition(newX, newZ);
}
