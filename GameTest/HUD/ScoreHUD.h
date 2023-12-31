#pragma once
#include "../App/app.h"

class ScoreHUD
{
	#pragma region VARIABLES
	public:

		App::Vector2 m_Location; // To do here

		float m_Scale = 1.f;
		float m_Width; // To do here
		float m_Height; // To do here

		CSimpleSprite* m_Sprite; // To do here
		const char* m_SpriteFilename; // To do here

		// Runtime
		int m_Score = 100;

	#pragma endregion


	#pragma region FUNCTIONS

	#pragma endregion
};

