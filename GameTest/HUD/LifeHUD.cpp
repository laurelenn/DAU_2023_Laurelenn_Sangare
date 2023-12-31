#include "stdafx.h"
#include "LifeHUD.h"

void LifeHUD::Update(float currentLife)
{
    m_CurrentLife = currentLife;
    m_HealthPercentage = (m_InitialLife <= 0.0f) ? (m_CurrentLife / m_InitialLife) * 100.0f : 0.0f;
}

void LifeHUD::Render()
{
   DrawHealthBar(m_Location.x, m_Location.z, m_Width*m_Scale, m_Height* m_Scale, m_HealthPercentage);
   const char* text = "Life : ";
   char textBuffer[64];
   sprintf(textBuffer, "%s %f", text, m_CurrentLife);
   App::Print(m_Location.x+m_Width+5, m_Location.z, textBuffer, 1.0f, 0.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

}

void LifeHUD::DrawHealthBar(float x, float y, float width, float height, float healthPercentage) {
#if APP_USE_VIRTUAL_RES
    APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
    width /= APP_VIRTUAL_WIDTH;
    height /= APP_VIRTUAL_HEIGHT;
#endif

    const float borderRadius = height * 0.5f;
    const float remainingWidth = width * (healthPercentage / 100.0f);

    glBegin(GL_QUADS);

    // Fond noir de la jauge
    glColor3f(0.0f, 0.0f, 0.0f);
    DrawRoundedRect(x, y, width, height, borderRadius);

    // Barre de vie en fonction du pourcentage restant
    glColor3f(1.0f - healthPercentage / 100.0f, healthPercentage / 100.0f, 0.0f);
    DrawRoundedRect(x, y, remainingWidth, height, borderRadius);

    glEnd();
}

void LifeHUD::DrawRoundedRect(float x, float y, float width, float height, float borderRadius) {
    const int segments = 30;

    // Dessiner le rectangle arrondi
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + borderRadius, y + borderRadius);
    for (int i = 0; i <= segments; ++i) {
        float angle = static_cast<float>(i) / static_cast<float>(segments) * 90.0f;
        float vx = x + width - borderRadius + borderRadius * cosf(angle * 3.1415926f / 180.0f);
        float vy = y + borderRadius + borderRadius * sinf(angle * 3.1415926f / 180.0f);
        glVertex2f(vx, vy);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + width - borderRadius, y + borderRadius);
    for (int i = 0; i <= segments; ++i) {
        float angle = static_cast<float>(i) / static_cast<float>(segments) * 90.0f;
        float vx = x + width - borderRadius + borderRadius * cosf(angle * 3.1415926f / 180.0f);
        float vy = y + height - borderRadius + borderRadius * sinf(angle * 3.1415926f / 180.0f);
        glVertex2f(vx, vy);
    }
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + borderRadius, y);
    glVertex2f(x + width - borderRadius, y);
    glVertex2f(x + width - borderRadius, y + height);
    glVertex2f(x + borderRadius, y + height);
    glEnd();
}