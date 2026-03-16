#include "pch.h"
#include "Make.h"

namespace nam
{
	App* Make::msp_app = nullptr;
	Ecs* Make::msp_ecs = nullptr;
	SceneManager* Make::msp_sceneManager = nullptr;
	AppChrono* Make::msp_appChrono = nullptr;

	Make::Make()
	{

	}

	Make::~Make()
	{
		SetApp(nullptr);
	}

	App* Make::GetApp()
	{
		return msp_app;
	}

	void Make::RefreshValue()
	{
		SetApp(App::Get());
	}

	void Make::SetApp(App* app)
	{
		if (app != nullptr)
		{
			msp_app = app;
			msp_ecs = &msp_app->GetEcs();
			msp_sceneManager = &msp_app->GetSceneManager();
			msp_appChrono = &msp_app->GetChrono();
		}
		else
		{
			msp_app = nullptr;
			msp_ecs = nullptr;
			msp_sceneManager = nullptr;
			msp_appChrono = nullptr;
		}
	}

	void Make::DestroyGameObject(GameObject* gameObject, Scene* scene)
	{
		scene->DestroyGameObject(gameObject);
	}

	void Make::DestroyGameObject(GameObject* gameObject, u32 idScene)
	{
		msp_sceneManager->GetScene(idScene)->DestroyGameObject(gameObject);
	}

	void Make::DestroyGameObjectIsSingle(GameObject* gameObject, Scene* scene, bool isSingleGameObject)
	{
		scene->DestroyGameObjectIsSingle(gameObject, isSingleGameObject);
	}

	void Make::DestroyGameObjectIsSingle(GameObject* gameObject, u32 idScene, bool isSingleGameObject)
	{
		msp_sceneManager->GetScene(idScene)->DestroyGameObjectIsSingle(gameObject, isSingleGameObject);
	}

	void Make::SetActiveGameObject(Scene* scene, GameObject* gameObject, bool active)
	{
		scene->SetActiveEntity(*gameObject->GetEntity(), active);
	}

	void Make::SetActiveGameObject(u32 idScene, GameObject* gameObject, bool active)
	{
		msp_sceneManager->GetScene(idScene)->SetActiveEntity(*gameObject->GetEntity(), active);
	}

	void Make::SetActiveEntity(Scene* scene, const Entity& entity, bool active)
	{
		scene->SetActiveEntity(entity, active);
	}

	void Make::SetActiveEntity(u32 idScene, const Entity& entity, bool active)
	{
		msp_sceneManager->GetScene(idScene)->SetActiveEntity(entity, active);
	}

	GameObject* Make::GetGameObject(Scene* scene, u32 idEntity)
	{
		return scene->GetGameObject(idEntity);
	}

	GameObject* Make::GetGameObject(Scene* scene, const Entity& entity)
	{
		return scene->GetGameObject(entity);
	}

	GameObject* Make::GetGameObject(u32 idScene, u32 idEntity)
	{
		return msp_sceneManager->GetScene(idScene)->GetGameObject(idEntity);
	}

	GameObject* Make::GetGameObject(u32 idScene, const Entity& entity)
	{
		return msp_sceneManager->GetScene(idScene)->GetGameObject(entity);
	}

	GameObject* Make::GetGameObject(u32 idEntity)
	{
		return msp_sceneManager->GetGameObjectInGame(idEntity);
	}

	GameObject* Make::GetGameObject(const Entity& entity)
	{
		return msp_sceneManager->GetGameObjectInGame(entity);
	}

	void Make::DestroyScene(Scene* scene)
	{
		msp_sceneManager->DestroyScene(scene);
	}

	void Make::AddCurrentScene(u32 idScene)
	{
		msp_sceneManager->AddCurrentScene(idScene);
	}

	void Make::AddCurrentScene(Scene* scene)
	{
		msp_sceneManager->AddCurrentScene(scene);
	}

	void Make::AddCurrentScene(size sceneTag)
	{
		msp_sceneManager->AddCurrentScene(sceneTag);
	}

	void Make::RemoveCurrentScene(Scene* scene)
	{
		msp_sceneManager->RemoveCurrentScene(scene);
	}

	void Make::RemoveCurrentScene(u32 idScene)
	{
		msp_sceneManager->RemoveCurrentScene(idScene);
	}

	void Make::RemoveCurrentScene(size sceneTag)
	{
		msp_sceneManager->RemoveCurrentScene(sceneTag);
	}

	void Make::SwitchCurrentScene(Scene* sceneClose, Scene* sceneOpen)
	{
		msp_sceneManager->SwitchCurrentScene(sceneClose, sceneOpen);
	}

	void Make::SwitchCurrentScene(u32 idSceneClose, u32 idSceneOpen)
	{
		msp_sceneManager->SwitchCurrentScene(idSceneClose, idSceneOpen);
	}

	void Make::SwitchCurrentScene(size sceneTag1, size sceneTag2)
	{
		msp_sceneManager->SwitchCurrentScene(sceneTag1, sceneTag2);
	}

	Scene* Make::GetScene(u32 idScene)
	{
		return msp_sceneManager->GetScene(idScene);
	}

	Scene* Make::GetScene(const Entity& entity)
	{
		UnMap<u32, Scene*> allScene = msp_sceneManager->GetAllScene();
		for (auto it1 = allScene.begin(); it1 != allScene.end(); it1++)
		{
			Entity entityFind = it1->second->GetEntity(entity.m_id);
			if (entityFind.m_id != -1)
			{
				return it1->second;
			}
		}
		return nullptr;
	}

	Mesh* Make::CreateEmptyMesh()
	{
		return Render->GetRenderItemManager().CreateRenderItem<Mesh>();
	}

	Sprite* Make::CreateEmptySprite()
	{
		return Render->GetRenderItemManager().CreateRenderItem<Sprite>();
	}

	Text* Make::CreateEmptyText()
	{
		return Render->GetRenderItemManager().CreateRenderItem<Text>();
	}

	Light* Make::CreateEmptyLight()
	{
		return Render->GetLightManager().CreateLight();
	}

	Light* Make::GetLight(u8 lightID)
	{
		return Render->GetLightManager().GetLight(lightID);
	}

	const float Make::GetRealDeltaTime()
	{
		return msp_appChrono->GetRealDeltaTime();
	}

	const float Make::GetScaledDeltaTime()
	{
		return msp_appChrono->GetScaledDeltaTime();
	}

	void Make::LoadTexture(std::wstring path, size uniqueTag, bool usingTextureFolder)
	{
		msp_app->LoadTexture(path, uniqueTag, usingTextureFolder);
	}
}
