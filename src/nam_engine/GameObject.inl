#pragma once
#include "GameObject.h"

namespace nam
{
	template<typename Component>
	void GameObject::AddComponent(const Component& data)
	{
		return App::Get()->m_ecs.AddComponent(m_entity, data);
	}

	template<typename Component>
	const bool GameObject::HasComponent()
	{
		return App::Get()->m_ecs.HasComponent<Component>(m_entity);
	}

	template<typename Component>
	Component& GameObject::GetComponent()
	{
		return App::Get()->m_ecs.GetComponent<Component>(m_entity);
	}

	template<typename T>
	inline void GameObject::SetupFunctionUpdate(T* owner, void(T::* Update)())
	{
		if (HasComponent<BehaviorComponent>() == false)
		{
			BehaviorComponent behavior;
			behavior.Update = [owner, Update]() {
				(owner->*Update)();
				};
			AddComponent(behavior);
		}
		else
		{
			BehaviorComponent& behavior = GetComponent<BehaviorComponent>();
			behavior.Update = [owner, Update]() {
				(owner->*Update)();
				};
		}
	}

	template<typename T>
	inline void GameObject::SetupBoxCollider(T* owner, void(T::* Collide)(u32 self, u32 other, const CollisionInfo& collisionInfo))
	{
		if (HasComponent<BoxColliderComponent>() == false)
		{
			BoxColliderComponent boxCollider;
			boxCollider.OnCollision = [owner, Collide](u32 self, u32 other, const CollisionInfo& collisionInfo) {
				(owner->*Collide)(self, other, collisionInfo);
				};

			AddComponent(boxCollider);
		}
		else
		{
			BoxColliderComponent& boxCollider = GetComponent<BoxColliderComponent>();
			boxCollider.OnCollision = [owner, Collide](u32 self, u32 other, const CollisionInfo& collisionInfo) {
				(owner->*Collide)(self, other, collisionInfo);
				};
		}
	}

	template<typename T>
	void GameObject::SetupSphereCollider(T* owner, void(T::* Collide)(u32 self, u32 other, const CollisionInfo& collisionInfo))
	{
		if (HasComponent<BoxColliderComponent>() == false)
		{
			SphereColliderComponent sphereCollider;
			sphereCollider.OnCollision = [owner, Collide](u32 self, u32 other, const CollisionInfo& collisionInfo) {
				(owner->*Collide)(self, other, collisionInfo);
				};

			AddComponent(sphereCollider);
		}
		else
		{
			SphereColliderComponent& sphereCollider = GetComponent<SphereColliderComponent>();
			sphereCollider.OnCollision = [owner, Collide](u32 self, u32 other, const CollisionInfo& collisionInfo) {
				(owner->*Collide)(self, other, collisionInfo);
				};
		}
	}

	template<typename T>
	void GameObject::SetupButton(T* owner, void(T::* Hovered)(), void(T::* Click)(), void(T::* Left)())
	{
		if (HasComponent<ButtonComponent>() == false)
		{
			ButtonComponent button;
			button.OnHovered = [owner, Hovered]() {
				(owner->*Hovered)();
				};
			button.OnClick = [owner, Click]() {
				(owner->*Click)();
				};
			button.OnLeft = [owner, Left]() {
				(owner->*Left)();
				};

			AddComponent(button);
		}
		else
		{
			ButtonComponent& button = GetComponent<ButtonComponent>();
			button.OnHovered = [owner, Hovered]() {
				(owner->*Hovered)();
				};
			button.OnClick = [owner, Click]() {
				(owner->*Click)();
				};
			button.OnLeft = [owner, Left]() {
				(owner->*Left)();
				};
		}
	}
}