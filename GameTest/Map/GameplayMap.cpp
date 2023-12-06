#include "stdafx.h"
#include <random>

#include "GameplayMap.h"

///-------- All Gameplay Object includes ------///
#include "../Gameplay/Enemies/Enemy.h"
#include "../Gameplay/Enemies/BlockerGreen.h"
///-------------------------------------------///



GameplayMap::GameplayMap(float Speed, std::vector<GameplayDatasMap> Datas)
	: Map(Speed), m_DatasGameplayMap(Datas)
{}

void GameplayMap::Init()
{
	//Spawn Object then Init

	for (auto& DataGameplay : m_DatasGameplayMap)
	{

		auto newGameObject = SpawnNewObjectFormData(DataGameplay);
		if (newGameObject)
		{
			App::Vector2 positionNewObject;

			// Z Pos
			float baseZPos = 0.f;
			switch (DataGameplay.m_FloorSpawn)
			{
				case Floor_Cave : 
					baseZPos = HEIGHT_FLOOR_CAVE;
					break;
				case Floor_Level0:
					baseZPos = HEIGHT_FLOOR_0;
					break;
				case Floor_Level1:
					baseZPos = HEIGHT_FLOOR_1;
					break;
				default : 
					baseZPos = HEIGHT_FLOOR_0;
					break;
			}


			// Delta on Z pos
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> distrib(-DataGameplay.m_DeltaPosZ, DataGameplay.m_DeltaPosZ);

			float deltaZ = distrib(gen);

			// Final position on spawn
			positionNewObject.z = CLAMP(baseZPos+deltaZ, m_MinMaxPosZ.x, m_MinMaxPosZ.z);
			positionNewObject.x = m_Position.x + DataGameplay.m_SpawnPositionX + (APP_VIRTUAL_WIDTH*1.25);

			newGameObject->Init(positionNewObject);
			newGameObject->SetGameManager(m_GameManager);

			m_GameObjectGameplayMap.push_back(newGameObject);
		}
	}
}

void GameplayMap::Update(float deltaTime)
{
	float NewPosX = ((m_SpeedMap / 1000.f) * deltaTime) * -1.f;
	SetPosition(m_Position.x - NewPosX, m_Position.z); // Update the map speed

	for (auto& gameObject : m_GameObjectGameplayMap)
	{
		if (gameObject && gameObject->m_bIsActivated)
		{
			gameObject->SetPosition(gameObject->m_Location.x - NewPosX, gameObject->m_Location.z); // Move the objects with the map
			gameObject->Update(deltaTime);
		}
	}
}

void GameplayMap::Render()
{
	for (auto& gameObject : m_GameObjectGameplayMap)
	{
		if (gameObject && gameObject->m_bIsActivated)
		{
			gameObject->Render();
		}
	}
}

void GameplayMap::Destroy()
{
	for (auto& gameObject : m_GameObjectGameplayMap)
	{
		if (gameObject)
		{
			gameObject->Destroy();
		}
	}
}

GameObject* GameplayMap::SpawnNewObjectFormData(GameplayDatasMap data)
{
	GameObject* newGameObject = nullptr;

	switch (data.m_TypeGameObject)
	{
		case Monster1 : 
			newGameObject = new BlockerGreen();
			break;

		default : 
		break;
	}


	return newGameObject;
}
