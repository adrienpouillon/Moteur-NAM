#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_life = 1;
	m_stateMachine = nullptr;
	m_valide = true;
}

void Enemy::OnInit()
{
	m_life = 1;
	SetBehavior();
}

void Enemy::OnStart()
{
	SetTag((int)Tag::_Enemy);
}

void Enemy::OnUpdate()
{
	float dt = App::Get()->GetChrono().GetScaledDeltaTime();
	XMFLOAT3 pos = XMFLOAT3(-0.001f, 0.0f, 0.f);
	TranslateWorld(pos);

	if (m_life < 1)
	{
		DestroyGameObject();
	}
}

void Enemy::OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo)
{
	GameObject* gameObject = App::Get()->GetGameObject(other);
	int tagOther = gameObject->GetTag();
	if (tagOther == (int)Tag::_Shot)
	{
		m_life--;
		MeshRendererComponent& meshRenderer = GetComponent<MeshRendererComponent>();
		meshRenderer.mp_mesh->MakeNoise(1, 1.f, DEFORMATION);
	}
}

void Enemy::OnDestroy()
{
  delete m_stateMachine;
}

void Enemy::SetLife(int life)
{
	m_life = life;
}

int Enemy::GetLife()
{
	return m_life;
}


