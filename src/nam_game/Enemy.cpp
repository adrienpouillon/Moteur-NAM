#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::OnInit()
{
	SetupBehavior();
	SetTag((int)Tag::_Player);
}

void Enemy::OnStart()
{

}

void Enemy::OnUpdate()
{
	AppChrono& chrono = App::Get()->GetChrono();
	float dt = chrono.GetScaledDeltaTime();

	XMFLOAT3 scalePlayer = GetWorldScale();
	float speed = SPEED_PLAYER * dt;
	XMFLOAT3 posPlayer = GetWorldPosition();

	if (Input::IsKey('Z'))
	{
		MoveWorldForward(speed);
	}
	if (Input::IsKey('S'))
	{
		MoveWorldForward(-speed);
	}

	chrono.SetTimeWarp(1.f);

	if (Input::IsKey('A'))
	{
		chrono.SetTimeWarp(0.25f);
	}
	if (Input::IsKey('E'))
	{
		chrono.SetTimeWarp(4.f);
	}

	if (Input::IsKey(VK_SPACE))
	{
		XMFLOAT3 translation = { 0, speed, 0 };
		TranslateWorld(translation);
	}
	if (Input::IsKey(VK_LCONTROL))
	{
		XMFLOAT3 translation = { 0, -speed, 0 };
		TranslateWorld(translation);
	}

	/*GameObject* gameObjectParticleEmitter = GetParticleEmitter();
	ParticleEmitersComponent& particleEmiters = gameObjectParticleEmitter->GetComponent<ParticleEmitersComponent>();
	particleEmiters.m_maxXYZ[INDEX_PARTICLE_PlAYER] = XMFLOAT3(posPlayer.x + OFFSET_CENTER_PARTICLE, posPlayer.y + OFFSET_CENTER_PARTICLE, posPlayer.z + OFFSET_CENTER_PARTICLE);
	particleEmiters.m_minXYZ[INDEX_PARTICLE_PlAYER] = XMFLOAT3(posPlayer.x - OFFSET_CENTER_PARTICLE, posPlayer.y - OFFSET_CENTER_PARTICLE, posPlayer.z - OFFSET_CENTER_PARTICLE);*/
}

void Enemy::OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo)
{

}

void Enemy::OnDestroy()
{

}

void Enemy::SetParticleEmitter(GameObject* particleEmitter)
{
	mp_particleEmitter = particleEmitter;
}

GameObject* Enemy::GetParticleEmitter()
{
	return mp_particleEmitter;
}

void Enemy::SetScore(Score* score)
{
	m_score = score;
}

void Enemy::IncreaseGameScore(int add)
{
	m_score->IncreaseScore(add);
}

Score* Enemy::GetScore()
{
	return m_score;
}





void Enemy::OnInitStateMachine(StateMachineComponent* sM)
{
	ActionIdle* aIdle = sM->CreateAction<ActionIdle>(_Idle);
	ActionRun* aRun = sM->CreateAction<ActionRun>(_Run);
	ActionAttack* aAttack = sM->CreateAction<ActionAttack>(_Attack);

	Transition* tIdleRun = aIdle->CreateTransition(_Run);
	Transition* tIdleAttack = aIdle->CreateTransition(_Attack);

	Transition* tRunAttack = aRun->CreateTransition(_Attack);

	Transition* tAttackIdle = aAttack->CreateTransition(_Idle);
	Transition* tAttackRun = aAttack->CreateTransition(_Run);

	using T = Enemy;
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

void ActionIdle::OnStart(GameObject* pOwner)
{

}

void ActionIdle::OnUpdate(GameObject* pOwner)
{

}

void ActionIdle::OnEnd(GameObject* pOwner)
{

}

void ActionRun::OnStart(GameObject* pOwner)
{

}

void ActionRun::OnUpdate(GameObject* pOwner)
{

}

void ActionRun::OnEnd(GameObject* pOwner)
{

}

void ActionAttack::OnStart(GameObject* pOwner)
{

}

void ActionAttack::OnUpdate(GameObject* pOwner)
{

}

void ActionAttack::OnEnd(GameObject* pOwner)
{

}
