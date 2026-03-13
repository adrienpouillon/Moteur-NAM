#pragma once

namespace nam
{
	class UISystem : public ISystem
	{
	public:
		void Update(Ecs& ecs) override;
	};
}

