#pragma once
#include "Enemy.h"

template<typename T>
inline void Enemy::CreateStateMachine(StateMachineComponent* sM, T* owner)
{
	m_stateMachine = sM;
	ActionIdle* aIdle = sM->CreateAction<ActionIdle>(_Idle);
	ActionRun* aRun = sM->CreateAction<ActionRun>(_Run);
	ActionAttack* aAttack = sM->CreateAction<ActionAttack>(_Attack);

	Transition* tIdleRun = aIdle->CreateTransition(_Run);
	Transition* tIdleAttack = aIdle->CreateTransition(_Attack);

	Transition* tRunAttack = aRun->CreateTransition(_Attack);

	Transition* tAttackIdle = aAttack->CreateTransition(_Idle);
	Transition* tAttackRun = aAttack->CreateTransition(_Run);


	auto* cIdleRun = CreateCondition<T>(tIdleRun, true, [](GameObject* owner)
		{
			T* ownerType = (T*)owner;
			return ownerType->m_valide;
		});

	auto* cIdleAttack = CreateCondition<T>(tIdleAttack, true, [](GameObject* owner)
		{
			T* ownerType = (T*)owner;
			return ownerType->m_valide;
		});

	auto* cRunAttack = CreateCondition<T>(tRunAttack, true, [](GameObject* owner)
		{
			T* ownerType = (T*)owner;
			return ownerType->m_valide;
		});

	auto* cAttackRun = CreateCondition<T>(tAttackRun, true, [](GameObject* owner)
		{
			T* ownerType = (T*)owner;
			return ownerType->m_valide;
		});

	auto* cAttackIdle = CreateCondition<T>(tAttackIdle, true, [](GameObject* owner)
		{
			T* ownerType = (T*)owner;
			return ownerType->m_valide;
		});

	sM->SetState(_Idle);
}