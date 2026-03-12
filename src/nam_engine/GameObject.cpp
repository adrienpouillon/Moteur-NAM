#include "pch.h"
#include "GameObject.h"

using namespace DirectX;

namespace nam
{
	GameObject::GameObject()
	{
		mp_scene = nullptr;
		m_entity = Entity();
		m_tag = -1;

		mp_transform = nullptr;
		m_stateMachine = nullptr;

		m_canDeleteMesh = false;
		m_canDeleteSprite = false;
		m_canDeleteText = false;
	}

	void GameObject::Init(Scene* scene, Entity entity)
	{
		App* app = App::Get();
		mp_scene = scene;
		m_entity = entity;

		m_canDeleteMesh = false;
		m_canDeleteSprite = false;
		m_canDeleteText = false;

		SetupTransform(XMFLOAT3(0.f, 0.f, 0.f));

		OnInit();
	}

	void GameObject::Start()
	{
		OnStart();
	}

	void GameObject::Update()
	{
		OnUpdate();
	}

	void GameObject::Collider(u32 self, u32 other, const CollisionInfo& collisionInfo)
	{
		OnCollision(self, other, collisionInfo);
	}

	void GameObject::Hovered()
	{
		OnHovered();
	}

	void GameObject::Click()
	{
		OnClick();
	}

	void GameObject::Left()
	{
		OnLeft();
	}

//private
	void GameObject::Destroy()
	{
		OnDestroy();

		if (m_canDeleteMesh && HasComponent<MeshRendererComponent>())
		{
			MeshRendererComponent& meshRenderer = GetComponent<MeshRendererComponent>();
			meshRenderer.DeleteMeshInstance();
		}
		if (m_canDeleteSprite && HasComponent<SpriteRendererComponent>())
		{
			SpriteRendererComponent& spriteRenderer = GetComponent<SpriteRendererComponent>();
			spriteRenderer.DeleteSpriteInstance();
		}
		if (m_canDeleteText && HasComponent<TextRendererComponent>())
		{
			TextRendererComponent& textRenderer = GetComponent<TextRendererComponent>();
			textRenderer.DeleteTextInstance();
		}

		if (m_stateMachine != nullptr)
		{
			delete m_stateMachine;
		}

		mp_scene->DestroyEntity(m_entity);
	}
//public

	void GameObject::OnInit()
	{

	}

	void GameObject::OnStart()
	{

	}

	void GameObject::OnUpdate()
	{

	}

	void GameObject::OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo)
	{

	}

	void GameObject::OnDestroy()
	{

	}

	void GameObject::OnHovered()
	{

	}

	void GameObject::OnClick()
	{

	}

	void GameObject::OnLeft()
	{

	}

	void GameObject::OnInitStateMachine(StateMachineComponent* sM)
	{

	}

	void GameObject::SetActiveEntity(bool active)
	{
		mp_scene->SetActiveEntity(m_entity, active);
	}

	void GameObject::DestroyGameObject()
	{
		mp_scene->DestroyGameObject(this);
	}

	void GameObject::SetWorldPosition(const XMFLOAT3& position)
	{
		mp_transform->SetWorldPosition(position);
	}

	XMFLOAT3 GameObject::GetWorldPosition()
	{
		return mp_transform->GetWorldPosition();
	}

	void GameObject::SetLocalPosition(const XMFLOAT3& position)
	{
		mp_transform->SetLocalPosition(position);
	}

	XMFLOAT3 GameObject::GetLocalPosition()
	{
		return mp_transform->GetLocalPosition();
	}

	void GameObject::SetWorldRotation(const XMFLOAT4& quat)
	{
		mp_transform->SetWorldRotation(quat);
	}

	XMFLOAT4 GameObject::GetWorldRotation()
	{
		return mp_transform->GetWorldRotation();
	}

	void GameObject::SetLocalRotation(const XMFLOAT4& quat)
	{
		mp_transform->SetLocalRotation(quat);
	}

	XMFLOAT4 GameObject::GetLocalRotation()
	{
		return mp_transform->GetLocalRotation();
	}

	void GameObject::SetWorldScale(const XMFLOAT3& scale)
	{
		mp_transform->SetWorldScale(scale);
	}

	XMFLOAT3 GameObject::GetWorldScale()
	{
		return mp_transform->GetWorldScale();
	}

	void GameObject::SetLocalScale(const XMFLOAT3& scale)
	{
		mp_transform->SetLocalScale(scale);
	}

	XMFLOAT3 GameObject::GetLocalScale()
	{
		return mp_transform->GetLocalScale();
	}

	void GameObject::SetLocalYaw(const float yaw)
	{
		mp_transform->SetLocalYPR(yaw, 0.f, 0.f);
	}

	void GameObject::SetLocalPitch(const float pitch)
	{
		mp_transform->SetLocalYPR(0.f, pitch, 0.f);
	}

	void GameObject::SetLocalRoll(const float roll)
	{
		mp_transform->SetLocalYPR(0.f, 0.f, roll);
	}

	void GameObject::SetLocalYPR(const float yaw, const float pitch, const float roll)
	{
		mp_transform->SetLocalYPR(yaw, pitch, roll);
	}

	void GameObject::SetLocalYPR(const XMFLOAT3& yawPitchRoll)
	{
		mp_transform->SetLocalYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
	}

	XMFLOAT3 GameObject::GetLocalYPR()
	{
		XMFLOAT3 yawPitchRoll;
		mp_transform->GetLocalYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
		return yawPitchRoll;
	}

	void GameObject::SetWorldYaw(const float yaw)
	{
		mp_transform->SetWorldYPR(yaw, 0.f, 0.f);
	}

	void GameObject::SetWorldPitch(const float pitch)
	{
		mp_transform->SetWorldYPR(0.f, pitch, 0.f);
	}

	void GameObject::SetWorldRoll(const float roll)
	{
		mp_transform->SetWorldYPR(0.f, 0.f, roll);
	}

	void GameObject::SetWorldYPR(const float yaw, const float pitch, const float roll)
	{
		mp_transform->SetWorldYPR(yaw, pitch, roll);
	}

	void GameObject::SetWorldYPR(const XMFLOAT3& yawPitchRoll)
	{
		mp_transform->SetWorldYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
	}

	XMFLOAT3 GameObject::GetWorldYPR()
	{
		XMFLOAT3 yawPitchRoll;
		mp_transform->GetWorldYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
		return yawPitchRoll;
	}

	void GameObject::AddChild(TransformComponent* transform)
	{
		mp_transform->AddChild(transform);
	}

	void GameObject::RemoveChild(TransformComponent* transform)
	{
		mp_transform->RemoveChild(transform);
	}

	const Vector<TransformComponent*>& GameObject::GetAllChild()
	{
		return mp_transform->GetChildren();
	}

	TransformComponent* GameObject::GetParent()
	{
		return mp_transform->GetParent();
	}

	XMFLOAT3 GameObject::GetWorldForward()
	{
		return mp_transform->GetWorldForward();
	}

	void GameObject::TranslateLocal(const XMFLOAT3& offset)
	{
		mp_transform->TranslateLocal(offset);
	}

	void GameObject::TranslateWorld(const XMFLOAT3& offset)
	{
		mp_transform->TranslateWorld(offset);
	}

	void GameObject::RotateLocalYPR(const float yaw, const float pitch, const float roll)
	{
		mp_transform->RotateLocalYPR(yaw, pitch, roll);
	}

	void GameObject::RotateLocalYPR(const DirectX::XMFLOAT3& yawPitchRoll)
	{
		mp_transform->RotateLocalYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
	}

	void GameObject::RotateWorldYPR(const float yaw, const float pitch, const float roll)
	{
		mp_transform->RotateWorldYPR(yaw, pitch, roll);
	}

	void GameObject::RotateWorldYPR(const XMFLOAT3& yawPitchRoll)
	{
		mp_transform->RotateWorldYPR(yawPitchRoll.x, yawPitchRoll.y, yawPitchRoll.z);
	}

	void GameObject::MoveLocalForward(const float dis)
	{
		mp_transform->MoveLocalForward(dis);
	}

	void GameObject::MoveWorldForward(const float dis)
	{
		mp_transform->MoveWorldForward(dis);
	}

	void GameObject::MoveLocalTowards(const XMFLOAT3& target, const float dis)
	{
		mp_transform->MoveLocalTowards(target, dis);
	}

	void GameObject::MoveWorldTowards(const XMFLOAT3& target, const float dis)
	{
		mp_transform->MoveWorldTowards(target, dis);
	}

	void GameObject::LookToLocal(const XMFLOAT3& direction)
	{
		mp_transform->LookToLocal(direction);
	}

	void GameObject::LookToWorld(const XMFLOAT3& direction)
	{
		mp_transform->LookToWorld(direction);
	}

	void GameObject::LookAtLocal(const XMFLOAT3& target)
	{
		mp_transform->LookAtLocal(target);
	}

	void GameObject::LookAtWorld(const XMFLOAT3& target)
	{
		mp_transform->LookAtWorld(target);
	}

	void GameObject::ActiveDeleteMesh(bool isActive)
	{
		m_canDeleteMesh = isActive;
	}

	void GameObject::ActiveDeleteSprite(bool isActive)
	{
		m_canDeleteSprite = isActive;
	}

	void GameObject::ActiveDeleteText(bool isActive)
	{
		m_canDeleteText = isActive;
	}

	void GameObject::SetupTransform(const XMFLOAT3& pos)
	{
		TransformComponent transform = TransformComponent();
		transform.SetWorldPosition(pos);
		AddComponent(transform);

		//save le component
		mp_transform = &GetComponent<TransformComponent>();
	}

	void GameObject::SetupMesh(Mesh& mesh)
	{
		if (HasComponent<MeshRendererComponent>() == false)
		{
			MeshRendererComponent meshRenderer;
			meshRenderer.SetMeshInstance(&mesh);

			AddComponent(meshRenderer);
		}
		else
		{
			MeshRendererComponent& meshRenderer = GetComponent<MeshRendererComponent>();
			meshRenderer.SetMeshInstance(&mesh);
		}
	}
  
	void GameObject::SetupMesh(Mesh* mesh)
	{
		if (HasComponent<MeshRendererComponent>() == false)
		{
			MeshRendererComponent meshRenderer;
			meshRenderer.SetMeshInstance(mesh);
			AddComponent(meshRenderer);
		}
		else
		{
			MeshRendererComponent& meshRenderer = GetComponent<MeshRendererComponent>();
			meshRenderer.SetMeshInstance(mesh);
		}
	}

	void GameObject::SetupSprite(Sprite& sprite)
	{
		if (HasComponent<SpriteRendererComponent>() == false)
		{
			SpriteRendererComponent spriteRenderer;
			spriteRenderer.SetSpriteInstance(&sprite);

			AddComponent(spriteRenderer);
		}
		else
		{
			SpriteRendererComponent& spriteRenderer = GetComponent<SpriteRendererComponent>();
			spriteRenderer.SetSpriteInstance(&sprite);
		}
	}

	void GameObject::SetupSprite(Sprite* sprite)
	{
		if (HasComponent<SpriteRendererComponent>() == false)
		{
			SpriteRendererComponent spriteRenderer;
			spriteRenderer.SetSpriteInstance(sprite);
			AddComponent(spriteRenderer);
		}
		else
		{
			SpriteRendererComponent& spriteRenderer = GetComponent<SpriteRendererComponent>();
			spriteRenderer.SetSpriteInstance(sprite);
		}
	}

	void GameObject::SetupText(const XMFLOAT2& charaScale, float zoom, const XMFLOAT4& color)
	{
		if (HasComponent<MeshRendererComponent>() == false)
		{
			TextRendererComponent textRender;
			Text* p_text = textRender.CreateTextInstance();
			p_text->SetDatas(charaScale, zoom, color);
			p_text->SetText("??? : ");
			p_text->SetTexture(_FontPusab);
			p_text->SetToDynamic(MAX_TEXT_VERTICES, MAX_TEXT_INDICES);
			AddComponent(textRender);
		}
		else
		{
			TextRendererComponent& textRender = GetComponent<TextRendererComponent>();
			Text* p_text = textRender.CreateTextInstance();
			p_text->SetDatas(charaScale, zoom, color);
			p_text->SetText("??? : ");
			p_text->SetTexture(_FontPusab);
			p_text->SetToDynamic(MAX_TEXT_VERTICES, MAX_TEXT_INDICES);
			textRender.SetTextInstance(p_text);
		}
	}

	void GameObject::SetupBehavior()
	{
		SetupFunctionUpdate(this, &GameObject::Update);
	}

	void GameObject::SetupBoxCollider()
	{
		SetupBoxCollider(this, &GameObject::Collider);
	}

	void GameObject::SetupSphereCollider()
	{
		SetupSphereCollider(this, &GameObject::Collider);
	}

	void GameObject::SetupButton()
	{
		SetupButton(this, &GameObject::Hovered, &GameObject::Click, &GameObject::Left);
	}

	void GameObject::SetupParticle(const XMFLOAT3& minXYZ, const XMFLOAT3& maxXYZ, const XMFLOAT3& minDir, const XMFLOAT3& maxDir, const XMFLOAT3& startColor, const XMFLOAT3& endColor, float minSpeed, float maxSpeed, float lifeTime, float spawnRate)
	{
		if (HasComponent<ParticleEmitersComponent>() == false)
		{
			ParticleEmitersComponent emiters;
			emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
			AddComponent(emiters);
		}
		else
		{
			ParticleEmitersComponent& emiters = GetComponent<ParticleEmitersComponent>();
			emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
		}
	}

	void GameObject::SetupStateMachine(int stateCount)
	{
		if (HasComponent<StateMachineComponent>() == false)
		{
			StateMachineComponent* stateMachine = new StateMachineComponent(this, stateCount);
			OnInitStateMachine(stateMachine);
			AddComponent(stateMachine);
			m_stateMachine = stateMachine;
		}
		else
		{
			StateMachineComponent& stateMachine = GetComponent<StateMachineComponent>();
			OnInitStateMachine(&stateMachine);
		}
	}

	void GameObject::SetupLight(Light* light)
	{
		if (HasComponent<LightComponent>() == false)
		{
			LightComponent lightC;
			lightC.SetLightInstance(light);
			AddComponent(lightC);
		}
		else
		{
			LightComponent& lightC = GetComponent<LightComponent>();
			lightC.SetLightInstance(light);
		}
	}

	void GameObject::SetupPhysic(const XMFLOAT3& velocity, bool useGravity, float masse)
	{
		if (HasComponent<PhysicComponent>() == false)
		{
			PhysicComponent physic;
			physic.m_velocity = velocity;
			physic.m_useGravity = useGravity;
			physic.m_mass = masse;
			AddComponent(physic);
		}
		else
		{
			PhysicComponent& physic = GetComponent<PhysicComponent>();
			physic.m_velocity = velocity;
			physic.m_useGravity = useGravity;
			physic.m_mass = masse;
		}
	}

	Entity* GameObject::GetEntity()
	{
		return &m_entity;
	}

	Scene* GameObject::GetScene()
	{
		return mp_scene;
	}

	void GameObject::SetTag(int tag)
	{
		m_tag = tag;
	}

	bool GameObject::IsTag(int tag) const
	{
		return m_tag == tag;
	}

	int GameObject::GetTag() const
	{
		return m_tag;
	}

	TransformComponent* GameObject::GetTransform()
	{
		return mp_transform;
	}
}