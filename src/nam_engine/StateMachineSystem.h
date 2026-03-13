#pragma once

namespace nam
{
	class StateMachineSystem : public ISystem
	{
	public:
		void Update(Ecs& ecs) override;
	};
}

