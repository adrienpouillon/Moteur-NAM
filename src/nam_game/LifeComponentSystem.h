#pragma once

struct LifeComponent
{
	int m_life = 1;
	int m_minLife = 0;
};

class LifeSystem : public ISystem
{
	void Update(Ecs& ecs) override;
};
