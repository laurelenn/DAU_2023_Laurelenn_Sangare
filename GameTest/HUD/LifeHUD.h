#pragma once
#include "../App/app.h"

enum AnimLifeHUD 
{
	IdleLifeHUD
};

class LifeHUD
{
	#pragma region VARIABLES
	public : 

		App::Vector2 m_Location; // Defined at constructor in game Manager

		float m_ScaleX = 1.0f * APP_VIRTUAL_SCALE;
		float m_ScaleY = 1.0f * APP_VIRTUAL_SCALE;
		float m_InitialLife = 100.f;
		const float m_DiffXLabel = 5.f * APP_VIRTUAL_SCALE;

		CSimpleSprite* m_SpriteBgGauge = nullptr;
		const char* m_SpriteBgGaugeFilename = ".\\.\\.\\Ressources\\HUD\\lifebar_bg.png";

		CSimpleSprite* m_SpriteGauge = nullptr;
		const char* m_SpriteGaugeFilename = ".\\.\\.\\Ressources\\HUD\\lifebar_fill.png";

		CSimpleSprite* m_SpriteBgValue = nullptr;
		const char* m_SpriteBgValueFilename = ".\\.\\.\\Ressources\\HUD\\hud_heartFull.png";

		// Runtime
		float m_CurrentLife = 100.f;
		float m_HealthPercentage = 100.f;
	#pragma endregion


	#pragma region FUNCTIONS
		LifeHUD(float scalex = 50.f, float scaley = 10.f, float initialLife = 100.0f, const App::Vector2& location = App::Vector2())
			: m_ScaleX(scalex), m_ScaleY(scaley), m_InitialLife(initialLife), m_Location(location)
			{}

		LifeHUD(float scalex = 50.f, float scaley = 10.f, float initialLife = 100.0f, float locX = 0.f, float locY = 0.f)
			: m_ScaleX(scalex), m_ScaleY(scaley), m_InitialLife(initialLife), m_Location(locX, locY) {}
	void Init();
	void Update(float currentLife);
	void Render();
	void DrawHealthBar();
	float GetPosGaugeX(){return m_SpriteBgGauge ? m_Location.x + (m_SpriteBgGauge->GetWidth() * m_ScaleX) / 2.f + m_DiffXLabel : 0.f;}
	void Destroy();
	#pragma endregion

};

