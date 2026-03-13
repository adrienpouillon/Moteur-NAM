#pragma once
namespace nam
{
	class ParticleSystem : public ISystem
	{
	public:
		void Update(Ecs& ecs) override;
	};
}

