//---------------------------------------------------------------------------------
// App.cpp
// Implementation of the calls that are exposed via the App namespace.
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include <string>
#include "main.h"
#include "app.h"
#include "SimpleSound.h"
#include "SimpleController.h"
#include "SimpleSprite.h"
#include <cmath>

//---------------------------------------------------------------------------------
// Utils and externals for system info.

namespace App
{	
	void DrawLine(float sx, float sy, float ex, float ey, float r, float g, float b)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(sx, sy);
		APP_VIRTUAL_TO_NATIVE_COORDS(ex, ey);
#endif
		glBegin(GL_LINES);
		glColor3f(r, g, b); // Yellow
		glVertex2f(sx, sy);
		glVertex2f(ex, ey);
		glEnd();
	}
	
	void DrawLineWithThickness(float sx, float sy, float ex, float ey, float thickness, float r, float g, float b) {
#if APP_USE_VIRTUAL_RES
		APP_VIRTUAL_TO_NATIVE_COORDS(sx, sy);
		APP_VIRTUAL_TO_NATIVE_COORDS(ex, ey);
#endif

		// Calcul de la moiti� de l'�paisseur
		float halfThickness = thickness * 0.5f / 300.f;

		// Calcul du vecteur entre les points de d�but et de fin
		float dx = ex - sx;
		float dy = ey - sy;
		float length = sqrt(dx * dx + dy * dy);

		// Normalisation du vecteur
		dx /= length;
		dy /= length;

		// Calcul des vecteurs perpendiculaires pour former un rectangle
		float vx = -dy * halfThickness;
		float vy = dx * halfThickness;

		glBegin(GL_QUADS);
		glColor3f(r, g, b); // Couleur sp�cifi�e

		// Sommets du rectangle pour former la ligne
		glVertex2f(sx - vx, sy - vy);
		glVertex2f(ex - vx, ey - vy);
		glVertex2f(ex + vx, ey + vy);
		glVertex2f(sx + vx, sy + vy);

		glEnd();
	}

	CSimpleSprite *CreateSprite(const char *fileName, int columns, int rows)
	{
		return new CSimpleSprite(fileName, columns, rows);
	}

	bool IsKeyPressed(int key)
	{
		return ((GetAsyncKeyState(key) & 0x8000) != 0);
	}

	void GetMousePos(float &x, float &y)
	{
		POINT mousePos;
		GetCursorPos(&mousePos);	// Get the mouse cursor 2D x,y position			
		ScreenToClient(MAIN_WINDOW_HANDLE, &mousePos);
		x = (float)mousePos.x;
		y = (float)mousePos.y;
		x = (x * (2.0f / WINDOW_WIDTH) - 1.0f);
		y = -(y * (2.0f / WINDOW_HEIGHT) - 1.0f);

#if APP_USE_VIRTUAL_RES		
		APP_NATIVE_TO_VIRTUAL_COORDS(x, y);
#endif
	}
	void PlaySound(const char *fileName, bool looping)
	{
		DWORD flags = (looping) ? DSBPLAY_LOOPING : 0;
		CSimpleSound::GetInstance().PlaySound(fileName, flags);
	}
	void StopSound(const char *fileName)
	{
		CSimpleSound::GetInstance().StopSound(fileName);
	}
	bool IsSoundPlaying(const char *fileName)
	{
		return CSimpleSound::GetInstance().IsPlaying(fileName);
	}
	// This prints a string to the screen
	void Print(float x, float y, const char *st, float r, float g, float b, void *font)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
#endif		
		// Set location to start printing text
		glColor3f(r, g, b); // Yellow
		glRasterPos2f(x, y);
		int l = (int)strlen(st);
		for (int i = 0; i < l; i++)
		{
			glutBitmapCharacter(font, st[i]); // Print a character on the screen
		}
	}
	const CController &GetController( int pad )
	{
		return CSimpleControllers::GetInstance().GetController(pad);
	}

	void DrawCircle(int segments, float radius, Vector2 pos, float r, float g, float b)
	{
		DrawCircle(segments, radius, pos.x, pos.z, r, g, b);
	}

	void DrawCircle(int segments, float radius, float posX, float posY, float r, float g, float b)
	{
		for (int i = 0; i < segments; ++i) {
			float theta1 = static_cast<float>(i) / static_cast<float>(segments) * 2.0f * 3.1415926f;
			float theta2 = static_cast<float>(i + 1) / static_cast<float>(segments) * 2.0f * 3.1415926f;

			float x1 = posX + radius * std::cos(theta1);
			float y1 = posY + radius * std::sin(theta1);
			float x2 = posX + radius * std::cos(theta2);
			float y2 = posY + radius * std::sin(theta2);

			App::DrawLine(x1, y1, x2, y2, r, g, b); // Jaune
		}
	}
}