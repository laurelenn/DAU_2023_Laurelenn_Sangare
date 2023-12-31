#include "stdafx.h"
#include "../App/app.h"

#include "Map.h"

void Map::SetPosition(float newX, float newZ)
{
	m_Position.x = newX;
	m_Position.z = newZ;
}

void Map::DrawMapBoundary(float rStart, float gStart, float bStart, float rEnd, float gEnd, float bEnd) {

    App::DrawLineWithThickness(m_Position.x, m_Position.z- m_Height, m_Position.x, m_Position.z + m_Height, 1.f, rStart, gStart, bStart);
    App::DrawLineWithThickness(m_Position.x-5.f + m_Width, m_Position.z- m_Height, m_Position.x-5.f + m_Width, m_Position.z + m_Height, 1.f, rEnd, gEnd, bEnd);
}