#include "stdafx.h"

#include "LDMap.h"
LDMap::LDMap(float Speed)
{
	m_SpeedMap = Speed;
}
LDMap::LDMap(float Speed, LDDatasMap Datas)
{
	m_SpeedMap = Speed;
	m_DatasLdMap = Datas;
}


void LDMap::Init()
{
	// To do -- spawn tiles LD at positions
}

void LDMap::Update(float deltaTime)
{
	// To do : Move each tiles LD from x pixels on the left
}

void LDMap::Render()
{
// For each tiles LD -> Render

}

void LDMap::Destroy()
{
// For each tiles LD -> Destroy

}
