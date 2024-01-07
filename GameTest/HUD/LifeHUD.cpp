#include "stdafx.h"
#include "LifeHUD.h"
#include "../App/app.h"


void LifeHUD::Init()
{

    // Create Animations
    m_SpriteBgGauge = App::CreateSprite(m_SpriteBgGaugeFilename, 1, 1);
    m_SpriteBgGauge->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteBgGauge->SetAnimation(IdleLifeHUD);
    m_SpriteBgGauge->SetScales(m_ScaleX, m_ScaleY, true);


    m_SpriteGauge = App::CreateSprite(m_SpriteGaugeFilename, 1, 1);
    m_SpriteGauge->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteBgGauge->SetAnimation(IdleLifeHUD);
    m_SpriteGauge->SetScales(m_ScaleX, m_ScaleY, true);

    m_SpriteBgValue = App::CreateSprite(m_SpriteBgValueFilename, 1, 1);
    m_SpriteBgValue->CreateAnimation(IdleLifeHUD, 1, { 0 });
    m_SpriteBgGauge->SetAnimation(IdleLifeHUD);
    m_SpriteBgValue->SetScales(m_ScaleX*1.25f, m_ScaleY*1.25f, true); // Arbitraire

   const float WidthGauge = (m_SpriteBgGauge->GetWidth()* m_ScaleX)/2.f;


   // Set positions

    m_SpriteBgGauge->SetPosition(m_Location.x + WidthGauge+m_DiffXLabel, m_Location.z);
    m_SpriteGauge->SetPosition(m_Location.x+ WidthGauge+m_DiffXLabel, m_Location.z);
    m_SpriteBgValue->SetPosition(m_Location.x, m_Location.z);


    // Value
    m_CurrentLife = m_InitialLife;
    m_HealthPercentage = CLAMP((m_CurrentLife / m_InitialLife), 0.00000f, 1.00000f);
}

void LifeHUD::Update(float currentLife)
{
    m_CurrentLife = currentLife;
    m_HealthPercentage = CLAMP((m_CurrentLife / m_InitialLife), 0.00000f, 1.00000f);

    if (m_SpriteBgGauge)
    {
        m_SpriteBgGauge->Update(0.1f);
    }

    if (m_SpriteGauge)
    {
        m_SpriteGauge->Update(0.1f);
    }

    if (m_SpriteBgValue)
    {
        m_SpriteBgValue->Update(0.1f);
    }
}

void LifeHUD::Render()
{
   DrawHealthBar();
   char textBuffer[64];
   sprintf(textBuffer, "%d", (int)m_CurrentLife);
   float PosX = 0.f;
   if ((int)m_CurrentLife >= 100)
   {
    PosX = m_Location.x * 0.5f + m_SpriteBgValue->GetWidth() * 0.2f * m_ScaleX;
   }
   else if ((int)m_CurrentLife >= 10)
   {
     PosX = m_Location.x * 0.5f + m_SpriteBgValue->GetWidth() * 0.35f * m_ScaleX;
   }
   else
   {
       PosX = m_Location.x * 0.5f + m_SpriteBgValue->GetWidth() * 0.45f * m_ScaleX;
   }
   App::Print(PosX, m_Location.z - m_Location.z/120.f, textBuffer, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_HELVETICA_18);

}

void LifeHUD::DrawHealthBar() {

    m_SpriteGauge->SetScales(m_ScaleX*m_HealthPercentage, m_ScaleY, true);

    const float DiffWithCenter = m_SpriteGauge->GetWidth() * (m_ScaleX * (1.f - m_HealthPercentage));
    const float LimitMin = (m_SpriteBgValue->GetWidth() * m_ScaleX) + m_DiffXLabel + m_Location.x;
    const float LimitMax = m_Location.x + ((m_SpriteBgGauge->GetWidth() * m_ScaleX) / 2.f) + m_DiffXLabel;

    float NewPosX = m_Location.x + m_DiffXLabel + ((m_SpriteBgGauge->GetWidth() * m_ScaleX) / 2.f) - (DiffWithCenter / 2.f);
    //NewPosX = CLAMP( NewPosX , LimitMin, LimitMax );

    m_SpriteGauge->SetPosition(NewPosX, m_Location.z);
    m_SpriteGauge->SetColor(1.f-m_HealthPercentage+0.8f, m_HealthPercentage*1.8f, 0.f);


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

