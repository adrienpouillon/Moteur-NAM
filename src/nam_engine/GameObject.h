#pragma once

namespace nam
{
	class App;
	class Scene;

	class GameObject
	{
	private:
		Entity m_entity;
		Scene* mp_scene;
		int m_tag;
		TransformComponent* mp_transform;
		bool m_canDeleteMesh;
		bool m_canDeleteSprite;
		bool m_canDeleteText;
		StateMachineComponent* m_stateMachine;
	public:

		GameObject();
		void Init(Scene* scene, Entity entity);
		void Start();
		void Update();
		void Collider(u32 self, u32 other, const CollisionInfo& collisionInfo);
		void Hovered();
		void Click();
		void Left();

		virtual void OnInit();
		virtual void OnStart();
		virtual void OnUpdate();
		virtual void OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo);
		virtual void OnDestroy();
		virtual void OnHovered();
		virtual void OnClick();
		virtual void OnLeft();
		virtual void OnInitStateMachine(StateMachineComponent* sM);


		void SetActiveEntity(bool active);
		void DestroyGameObject();

		template<typename Component>
		void AddComponent(const Component& data);
		template<typename Component>
		const bool HasComponent();
		template<typename Component>
		Component& GetComponent();

		void SetWorldPosition(const DirectX::XMFLOAT3& position);
		DirectX::XMFLOAT3 GetWorldPosition();
		void SetLocalPosition(const DirectX::XMFLOAT3& position);
		DirectX::XMFLOAT3 GetLocalPosition();

		void SetWorldRotation(const DirectX::XMFLOAT4& quat);
		DirectX::XMFLOAT4 GetWorldRotation();
		void SetLocalRotation(const DirectX::XMFLOAT4& quat);
		DirectX::XMFLOAT4 GetLocalRotation();

		void SetWorldScale(const DirectX::XMFLOAT3& scale);
		DirectX::XMFLOAT3 GetWorldScale();
		void SetLocalScale(const DirectX::XMFLOAT3& scale);
		DirectX::XMFLOAT3 GetLocalScale();

		void SetLocalYaw(const float yaw);
		void SetLocalPitch(const float pitch);
		void SetLocalRoll(const float roll);
		void SetLocalYPR(const float yaw, const float pitch, const float roll);
		void SetLocalYPR(const DirectX::XMFLOAT3& yawPitchRoll);
		DirectX::XMFLOAT3 GetLocalYPR();
		void SetWorldYaw(const float yaw);
		void SetWorldPitch(const float pitch);
		void SetWorldRoll(const float roll);
		void SetWorldYPR(const float yaw, const float pitch, const float roll);
		void SetWorldYPR(const DirectX::XMFLOAT3& yawPitchRoll);
		DirectX::XMFLOAT3 GetWorldYPR();

		void AddChild(TransformComponent* transform);
		void RemoveChild(TransformComponent* transform);
		const Vector<TransformComponent*>& GetAllChild();
		TransformComponent* GetParent();

		DirectX::XMFLOAT3 GetWorldForward();

		void TranslateLocal(const DirectX::XMFLOAT3& offset);
		void TranslateWorld(const DirectX::XMFLOAT3& offset);
		void RotateLocalYPR(const float yaw, const float pitch, const float roll);
		void RotateLocalYPR(const DirectX::XMFLOAT3& yawPitchRoll);
		void RotateWorldYPR(const float yaw, const float pitch, const float roll);
		void RotateWorldYPR(const DirectX::XMFLOAT3& yawPitchRoll);

		void MoveLocalForward(const float dis);
		void MoveWorldForward(const float dis);
		void MoveLocalTowards(const DirectX::XMFLOAT3& target, const float dis);
		void MoveWorldTowards(const DirectX::XMFLOAT3& target, const float dis);

		void LookToLocal(const DirectX::XMFLOAT3& direction);
		void LookToWorld(const DirectX::XMFLOAT3& direction);
		void LookAtLocal(const DirectX::XMFLOAT3& target);
		void LookAtWorld(const DirectX::XMFLOAT3& target);

		void ActiveDeleteMesh(bool isActive);
		void ActiveDeleteSprite(bool isActive);
		void ActiveDeleteText(bool isActive);

	private:
		void SetupTransform(const DirectX::XMFLOAT3& pos);

	public:
		void SetupMesh(Mesh& mesh);
		void SetupMesh(Mesh* mesh);

		void SetupSprite(Sprite& sprite);
		void SetupSprite(Sprite* sprite);

		void SetupText(const DirectX::XMFLOAT2& charaScale, float zoom, const DirectX::XMFLOAT4& color);

		void SetupBehavior();
		void SetupBoxCollider();
		void SetupSphereCollider();
		void SetupButton();

		void SetupParticle(const DirectX::XMFLOAT3& minXYZ, const DirectX::XMFLOAT3& maxXYZ, const DirectX::XMFLOAT3& minDir, const DirectX::XMFLOAT3& maxDir, const DirectX::XMFLOAT3& startColor, const DirectX::XMFLOAT3& endColor, float minSpeed, float maxSpeed, float lifeTime, float spawnRate);
		void SetupStateMachine(int stateCount);
		void SetupLight(Light* light);

		void SetupPhysic(const DirectX::XMFLOAT3& velocity, bool useGravity, float masse = 1.f);

		Entity* GetEntity();
		Scene* GetScene();

		void SetTag(int tag);
		bool IsTag(int tag) const;
		int GetTag() const;
		
		TransformComponent* GetTransform();



	private:
		void Destroy();

		template<typename T>
		void SetupFunctionUpdate(T* owner, void (T::* Update)());
		template<typename T>
		void SetupBoxCollider(T* owner, void(T::* Collide)(u32 self, u32 other, const CollisionInfo& collisionInfo));
		template<typename T>
		void SetupSphereCollider(T* owner, void(T::* Collide)(u32 self, u32 other, const CollisionInfo& collisionInfo));
		template<typename T>
		void SetupButton(T* owner, void(T::* Hovered)(), void(T::* Click)(), void(T::* Left)());

		friend class App;
		friend class Scene;
	};
}

#include "GameObject.inl"