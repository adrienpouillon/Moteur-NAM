#pragma once
class Enemy : public GameObject
{
private:
	GameObject* mp_particleEmitter;
	Score* m_score;
	bool m_valide;
public:
	Enemy();

	void OnInit() override;
	void OnStart() override;
	void OnUpdate() override;
	void OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo) override;
	void OnDestroy() override;
	void OnInitStateMachine(StateMachineComponent* sM) override;
	
	void SetParticleEmitter(GameObject* particleEmitter);
	GameObject* GetParticleEmitter();

	void SetScore(Score* score);
	void IncreaseGameScore(int add);
	Score* GetScore();

private:
	template<typename T>
	void CreateStateMachine(StateMachineComponent* sM);
};

enum State
{
	_Idle,
	_Run,
	_Attack
};

class ActionIdle : public Action
{
public:
	void OnStart(GameObject* pOwner) override;
	void OnUpdate(GameObject* pOwner) override;
	void OnEnd(GameObject* pOwner) override;
};

class ActionRun : public Action
{
public:
	void OnStart(GameObject* pOwner) override;
	void OnUpdate(GameObject* pOwner) override;
	void OnEnd(GameObject* pOwner) override;
};

class ActionAttack : public Action
{
public:
	void OnStart(GameObject* pOwner) override;
	void OnUpdate(GameObject* pOwner) override;
	void OnEnd(GameObject* pOwner) override;
};
