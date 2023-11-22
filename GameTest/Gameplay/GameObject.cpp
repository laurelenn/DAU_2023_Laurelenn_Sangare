#include "stdafx.h"
#include <iostream>
#include <type_traits>
#include "../App/app.h"
#include "../Gameplay/Collisions/CollisionComponent.h"
#include "GameObject.h"

void GameObject::SetPosition(float x, float z)
{
	m_Sprite.SetPosition(x, z);
	m_Collision->SetPosition(x,z);
}