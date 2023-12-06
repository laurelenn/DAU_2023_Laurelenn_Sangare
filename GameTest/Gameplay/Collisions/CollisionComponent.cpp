#include "stdafx.h"
#include "CollisionComponent.h"
#include "../App/app.h"
#include <cmath>

void CollisionComponent::SetPosition(const App::Vector2& position) 
{
    m_Position = position;
}

void CollisionComponent::SetPosition(const float x, const float z) 
{
    m_Position.x = x;
    m_Position.z = z;
}


bool CollisionComponent::IsColliding(const CollisionComponent& other) const
{
    if (&other)
    {
        std::vector<App::Vector2> axesOwner = GetAxes();
        std::vector<App::Vector2> axesOther = other.GetAxes();
        axesOwner.insert(axesOwner.end(), axesOther.begin(), axesOther.end());

        Projection Projection1 = Project(axesOwner);
        Projection Projection2 = other.Project(axesOwner);

        // Vérification de la séparation des intervalles sur tous les axes
        if (Projection1.max < Projection2.min || Projection2.max < Projection1.min) {
            return false; // Aucune intersection
        }

         return true; // Intersection détectée
    }
    return false;
}
