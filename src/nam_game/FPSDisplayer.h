#pragma once

class FPSDisplayer : public GameObject
{
	Timer m_refreshTimer = {};
public:
	void OnInit() override;
	void OnStart() override;
	void OnUpdate() override;
	void OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo) override;
	void OnDestroy() override;

	Timer* GetTimer();
};

