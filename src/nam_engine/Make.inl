#pragma once
#include "Make.h"

namespace nam
{
	template<typename T>
	T* Make::CreateGameObject(Scene* scene)
	{
		return scene->CreateGameObject<T>(scene);
	}

	template<typename T>
	T* Make::CreateGameObject(u32 idScene)
	{
		return msp_sceneManager->GetScene(idScene)->CreateGameObject<T>(idScene);
	}

	template<typename Component>
	void Make::AddComponent(const Entity& entity, const Component& data)
	{
		msp_ecs->AddComponent(entity, data);
	}

	//template<typename Component>
	//void App::RemoveComponent()
	//{
	//	msp_ecs->
	//}

	template<typename Component>
	const bool Make::HasComponent(const Entity& entity)
	{
		return msp_ecs->HasComponent(entity);
	}

	template<typename Component>
	Component& Make::GetComponent(const Entity& entity)
	{
		return msp_ecs->GetComponent(entity);
	}

	template<typename System, typename... Args>
	void Make::AddSystem(Args&&... args)
	{
		msp_ecs->AddSystem<System>(std::forward<Args>(args)...);
	}

	//template<typename System>
	//void App::RemoveSystem()
	//{
	//	m_ecs.
	//}

	template<typename System>
	void Make::SetSystemEnabled(const bool enabled)
	{
		msp_ecs->SetSystemEnabled(enabled);
	}

	template<typename... Components, typename Func>
	void Make::ForEach(Func&& func)
	{
		msp_ecs->ForEach(func);
	}

	template<typename... Components, typename Func>
	void Make::DoubleForEach(Func&& func)
	{
		msp_ecs->DoubleForEach(func);
	}

}