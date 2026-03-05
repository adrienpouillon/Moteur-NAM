#pragma once

#define OFFSET_CENTER_PARTICLE 1.f
#define INDEX_PARTICLE_PlAYER 0

#define SPEED_SHOT 25.f
#define LIFETIME_SHOT 5.f

class Player : public GameObject
{
private:
	GameObject* mp_particleEmitter;
	Mesh* m_meshShot;
public:
	Player();

	void OnInit() override;
	void OnStart() override;
	void OnUpdate() override;
	void OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo) override;
	void OnDestroy() override;

	void SetParticleEmitter(GameObject* particleEmitter);
	GameObject* GetParticleEmitter();

	void SetMeshShot(Mesh* mesh);
	Mesh* GetMeshShot();
};
