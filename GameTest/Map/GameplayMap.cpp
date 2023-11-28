#include "stdafx.h"
#include "GameplayMap.h"

GameplayMap::GameplayMap(float Speed)
{
	m_SpeedMap = Speed;
}

GameplayMap::GameplayMap(float Speed, GameplayDatasMap Datas)
{
	m_SpeedMap = Speed;
	m_DatasGameplayMap = Datas;
}

void GameplayMap::Init()
{
	// To do : Spawn game object with pos
}

void GameplayMap::Update(float deltaTime)
{
	// To do : foreach game object update and set pos
}

void GameplayMap::Render()
{
	// To do : Foreach render
}

void GameplayMap::Destroy()
{
	// To do : for each destroy
}
