#include "stdafx.h"
#include "CollisionComponent.h"
#include "../App/app.h"
#include <cmath>

void CollisionComponent::SetPosition(const Vector2& position) {
    m_Position = position;
}

bool CollisionComponent::IsColliding(const CollisionComponent& other) const
{
    std::vector<Vector2> axes = GetAxes();
    axes.insert(axes.end(), other.GetAxes().begin(), other.GetAxes().end());

    Projection Projection1 = Project(axes);
    Projection Projection2 = other.Project(axes);

    // V�rification de la s�paration des intervalles sur tous les axes
    if (Projection1.max < Projection2.min || Projection2.max < Projection1.min) {
        return false; // Aucune intersection
    }

    return true; // Intersection d�tect�e
}

// Fonction principale pour dessiner la forme de collision en fonction du type de forme
void CollisionComponent::DrawDebugCollision() const {}
