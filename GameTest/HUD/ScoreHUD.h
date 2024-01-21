#pragma once
#include "../App/app.h"


enum AnimScoreHUD
{
	IdleScoreHUD
};


class ScoreHUD
{
	#pragma region VARIABLES
	public:

		App::Vector2 m_Location; // Defined at constructor in game Manager

		float m_ScaleX = 1.0f * APP_VIRTUAL_SCALE;
		float m_ScaleY = 1.0f * APP_VIRTUAL_SCALE;

		CSimpleSprite* m_Sprite = nullptr;
		const char* m_SpriteFilename = ".\\.\\.\\Ressources\\HUD\\score_star_bg.png";
		
		// Runtime
		int m_Score = 0;

	#pragma endregion


	#pragma region FUNCTIONS
	ScoreHUD(float scalex = 50.f, float scaley = 10.f, const App::Vector2& location = App::Vector2())
		: m_ScaleX(scalex), m_ScaleY(scaley), m_Location(location)
	{}

	ScoreHUD(float scalex = 50.f, float scaley = 10.f, float locX = 0.f, float locY = 0.f)
		: m_ScaleX(scalex), m_ScaleY(scaley), m_Location(locX, locY)
	{}

	void Init();
	void Update(int newScore);
	void Render();
	void Destroy();
	#pragma endregion
};

