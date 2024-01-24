#include "stdafx.h"
#include "ScoreHUD.h"

void ScoreHUD::Init()
{
    m_Sprite = App::CreateSprite(m_SpriteFilename, 1, 1);
    m_Sprite->CreateAnimation(IdleScoreHUD, 1, { 0 });
    m_Sprite->SetAnimation(IdleScoreHUD);
    m_Sprite->SetScales(m_ScaleX, m_ScaleY, true);

    const float WidthGauge = (m_Sprite->GetWidth() * m_ScaleX) / 1.75f;
    m_Sprite->SetPosition(m_Location.x-WidthGauge, m_Location.z);

    m_Score = 0;
}

void ScoreHUD::Update(int newScore)
{
    if (m_Sprite)
    {
        m_Sprite->Update(0.1f);
    }
    m_Score = newScore;
}

void ScoreHUD::Render()
{

    char textBuffer[64];
    sprintf(textBuffer, "%03d %03d", m_Score / 1000, m_Score % 1000);
    const float WidthGauge = (m_Sprite->GetWidth() * m_ScaleX) / 1.5f;
    
    if (m_Sprite)
    {
        m_Sprite->Draw();
    }

    float PosX = m_Location.x - WidthGauge;
    App::Print(PosX, m_Location.z - m_Location.z / 100.f, textBuffer, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

}

void ScoreHUD::Destroy()
{
    delete m_Sprite;
    m_Sprite = nullptr;
}
