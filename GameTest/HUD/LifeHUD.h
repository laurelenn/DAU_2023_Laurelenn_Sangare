#pragma once
#include "../App/app.h"

class LifeHUD
{
	#pragma region VARIABLES
	public : 

		App::Vector2 m_Location; // To do here

		float m_Scale = 1.f;
		float m_Width; // To do here
		float m_Height; // To do here
		float m_InitialLife = 100.f;

		//CSimpleSprite* m_Sprite;
		//const char* m_SpriteFilename; // To do here

		// Runtime
		float m_CurrentLife = 100.f;
		float m_HealthPercentage = 100.f;
	#pragma endregion


	#pragma region FUNCTIONS
		LifeHUD(float scale = 1.0f, float width = 50.f, float height = 10.f, float initialLife = 100.0f, const App::Vector2& location = App::Vector2())
			: m_Scale(scale), m_Width(width), m_Height(height), m_InitialLife(initialLife), m_Location(location) 
			{}

		LifeHUD(float scale = 1.0f, float width = 50.f, float height = 10.f, float initialLife = 100.0f, float locX = 0.f, float locY = 0.f)
			: m_Scale(scale), m_Width(width), m_Height(height), m_InitialLife(initialLife), m_Location(locX, locY) {}
	void Update(float deltaTime);
	void Render();
	void DrawHealthBar(float x, float y, float width, float height, float healthPercentage);
	void DrawRoundedRect(float x, float y, float width, float height, float borderRadius);
	#pragma endregion

};

