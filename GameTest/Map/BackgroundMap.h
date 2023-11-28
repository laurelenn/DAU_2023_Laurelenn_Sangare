#pragma once
#include "Map.h"
#include "../App/SimpleSprite.h"

struct BackgroundDatasMap
{
    // To do : Create Background Datas with type and filename
};


class BackgroundMap :
    public Map
{

#pragma region VARIABLES

    BackgroundDatasMap m_DatasBgMap;
    CSimpleSprite* m_Sprite;
#pragma endregion

#pragma region FUNCTIONS
public:
    BackgroundMap(float Speed);
    BackgroundMap(float Speed, BackgroundDatasMap Datas);

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Destroy() override;
#pragma endregion

};

