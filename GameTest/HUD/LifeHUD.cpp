#include "stdafx.h"
#include "LifeHUD.h"
#include "../App/app.h"
#include "../App/app.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void LifeHUD::Init()
{



    // Create Animations
    m_SpriteBgGauge = App::CreateSprite(m_SpriteBgGaugeFilename, 1, 1);
    m_SpriteBgGauge->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteBgGauge->SetAnimation(AnimLifeHUD::IdleLifeHUD);
   
    m_SpriteGauge = App::CreateSprite(m_SpriteGaugeFilename, 1, 1);
    m_SpriteGauge->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteGauge->SetScales(m_ScaleX, m_ScaleY, true);

    m_SpriteBgValue = App::CreateSprite(m_SpriteBgValueFilename, 1, 1);
    m_SpriteBgValue->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteBgValue->SetScales(m_ScaleX, m_ScaleY, true); // Arbitraire


    // Determinate Width & Height & Positions

    m_Width = (m_SpriteBgGauge->GetWidth() + m_DiffXLabel + m_SpriteBgValue->GetWidth()) * m_ScaleX;
    m_Height = m_SpriteBgGauge->GetHeight() * m_ScaleY;

   const float WidthGauge = m_SpriteBgGauge->GetWidth()* m_ScaleX;


   // Set positions

    m_SpriteBgGauge->SetScales(m_ScaleX, m_ScaleY, true);
    m_SpriteBgGauge->SetPosition(m_Location.x + WidthGauge+m_DiffXLabel, m_Location.z);
   
    m_SpriteGauge->SetAnimation(AnimLifeHUD::IdleLifeHUD);
    m_SpriteGauge->SetPosition(m_Location.x+ WidthGauge+m_DiffXLabel, m_Location.z);
    
    m_SpriteBgValue->SetAnimation(AnimLifeHUD::IdleLifeHUD);
    m_SpriteBgValue->SetPosition(m_Location.x-m_DiffXLabel, m_Location.z);


    // Value
    m_CurrentLife = m_InitialLife;
    m_HealthPercentage = CLAMP((m_CurrentLife / m_InitialLife), 0, 1);
}

void LifeHUD::Update(float currentLife)
{
    m_CurrentLife = currentLife;
    m_HealthPercentage = CLAMP((m_CurrentLife / m_InitialLife), 0, 1);

    if (m_SpriteBgGauge)
    {
        m_SpriteBgGauge->Update(0.1);
    }

    if (m_SpriteGauge)
    {
        m_SpriteGauge->Update(0.1);
    }

    if (m_SpriteBgValue)
    {
        m_SpriteBgValue->Update(0.1);
    }
}

void LifeHUD::Render()
{
   DrawHealthBar();
   const char* text = "HP: ";
   char textBuffer[64];
   sprintf(textBuffer, "%s %d %%", text, (int)m_CurrentLife);
   App::Print(m_Location.x-m_DiffXLabel, m_Location.z- m_Location.z/100, textBuffer, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18);

}

void LifeHUD::DrawHealthBar() {

    m_SpriteGauge->SetScales(m_ScaleX*m_HealthPercentage, m_ScaleY, true);
    const float DiffWithCenter = ((m_SpriteGauge->GetWidth() * m_ScaleX) * (1 - m_HealthPercentage))/2;
    float NewPosX = m_Location.x + m_DiffXLabel + m_SpriteGauge->GetWidth() * m_ScaleX - DiffWithCenter;
    m_SpriteGauge->SetPosition(NewPosX, m_Location.z);

    if (m_SpriteBgGauge)
    {                                 
        m_SpriteBgGauge->Draw();
    }

    if (m_SpriteGauge)
    {
        m_SpriteGauge->Draw();
    }
    
    if (m_SpriteBgValue)
    {
        m_SpriteBgValue->Draw();
    }

}

