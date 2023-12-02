#pragma once
#include "Map.h"
#include "../App/SimpleSprite.h"
#include "../Datas/Map_DatasBackground.h"


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
    void SetPosition(float newX, float newZ) override;
#pragma endregion

};

