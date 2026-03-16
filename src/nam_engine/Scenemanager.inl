#pragma once
#include "SceneManager.h"

namespace nam
{
	template<typename T>
	inline T* SceneManager::CreateScene(size sceneTag)
	{
		T* scene = new T();
		scene->SetId(m_idNext);
		scene->SetEcs(mp_ecs);
		scene->SetAllGameObjectInAllScene(&m_allGameObjectInAllScene);
		scene->m_tag = sceneTag;
		IncreaseIdNext();

		m_allScene[scene->GetId()] = scene;
		m_allSceneByTag[sceneTag] = scene;

		SetActiveScene(scene, false);
		return scene;
	}



}