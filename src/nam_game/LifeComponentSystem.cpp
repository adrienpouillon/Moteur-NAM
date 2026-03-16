#include "pch.h"
#include "LifeComponentSystem.h"

void LifeSystem::Update(Ecs& ecs)
{
	ecs.ForEach<LifeComponent>([&](u32 idEntity, LifeComponent& life) {
			if (life.m_life <= life.m_minLife)
			{
				Make::GetGameObject(idEntity)->DestroyGameObject();
			}
		});
}