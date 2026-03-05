#include "pch.h"
#include "Player.h"

Player::Player()
{

}

void Player::OnInit()
{
	SetBehavior();
	SetTag((int)Tag::_Player);
}

void Player::OnStart()
{

}

void Player::OnUpdate()
{
	AppChrono& chrono = App::Get()->GetChrono();
	float dt = chrono.GetScaledDeltaTime();

	XMFLOAT3 posPlayer = GetWorldPosition();

	GameObject* gameObjectParticleEmitter = GetParticleEmitter();
	ParticleEmitersComponent& particleEmiters = gameObjectParticleEmitter->GetComponent<ParticleEmitersComponent>();
	particleEmiters.m_maxXYZ[INDEX_PARTICLE_PlAYER] = XMFLOAT3(posPlayer.x + OFFSET_CENTER_PARTICLE, posPlayer.y + OFFSET_CENTER_PARTICLE, posPlayer.z + OFFSET_CENTER_PARTICLE);
	particleEmiters.m_minXYZ[INDEX_PARTICLE_PlAYER] = XMFLOAT3(posPlayer.x - OFFSET_CENTER_PARTICLE, posPlayer.y - OFFSET_CENTER_PARTICLE, posPlayer.z - OFFSET_CENTER_PARTICLE);

	if (Input::IsKey('Z'))
	{
		MoveWorldForward(5 * dt);
	}
	if (Input::IsKey('S'))
	{
		MoveWorldForward(-5 * dt);
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
		XMFLOAT3 translation = { 0, 3 * dt, 0 };
		TranslateWorld(translation);
	}
	if (Input::IsKey(VK_LCONTROL))
	{
		XMFLOAT3 translation = { 0, -3 * dt, 0 };
		TranslateWorld(translation);
	}

	if (Input::IsKeyDown(VK_LBUTTON))
	{
		XMFLOAT3 forward = GetWorldForward();
		XMFLOAT3 multiply = XMFLOAT3(2.f, 2.f, 2.f);
		XMFLOAT3 posShot;
		XMStoreFloat3(&posShot, XMVectorAdd((FXMVECTOR)XMVectorMultiply((FXMVECTOR)XMLoadFloat3(&forward), (FXMVECTOR)XMLoadFloat3(&multiply)), (FXMVECTOR)XMLoadFloat3(&posPlayer)));
		Shot* shot = Shot::CreateShot(GetScene(), posShot, GetWorldRotation(), XMFLOAT3(0.5f, 0.5f, 0.5f), GetMeshShot(), SPEED_SHOT, LIFETIME_SHOT);
		int i = 0;
	}
}

void Player::OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo)
{

}

void Player::OnDestroy()
{

}

void Player::SetParticleEmitter(GameObject* particleEmitter)
{
	mp_particleEmitter = particleEmitter;
}

GameObject* Player::GetParticleEmitter()
{
	return mp_particleEmitter;
}

void Player::SetMeshShot(Mesh* mesh)
{
	m_meshShot = mesh;
}

Mesh* Player::GetMeshShot()
{
	return m_meshShot;
}
