#pragma once

namespace nam
{
	class LightManagerSystem : public ISystem
	{
	public:
		void Update(Ecs& ecs) override;
	};
}

