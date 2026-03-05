#pragma once

#define DEFORMATION 0.5f

class Enemy : public GameObject
{
private:
	bool m_valide;
	StateMachineComponent* m_stateMachine;
	int m_life;
public:
	Enemy();

	void OnInit() override;
	void OnStart() override;
	void OnUpdate() override;
	void OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo) override;
	void OnDestroy() override;

	template<typename T>
	void CreateStateMachine(StateMachineComponent* sM, T* owner);

	void SetLife(int life);
	int GetLife();

};

enum stateEnemy
{
	_Idle,
	_Run,
	_Attack,
	_CountStateEnemy
};

class ActionIdle : public Action
{
	void OnStart(GameObject* pOwner) {};
	void OnUpdate(GameObject* pOwner) {};
	void OnEnd(GameObject* pOwner) {};
};

class ActionRun : public Action
{
	void OnStart(GameObject* pOwner) {};
	void OnUpdate(GameObject* pOwner) {};
	void OnEnd(GameObject* pOwner) {};
};

class ActionAttack : public Action
{
	void OnStart(GameObject* pOwner) {};
	void OnUpdate(GameObject* pOwner) {};
	void OnEnd(GameObject* pOwner) {};
};

#include "Enemy.inl"

