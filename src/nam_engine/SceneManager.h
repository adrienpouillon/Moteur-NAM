#pragma once
#include <FrameworkCore.h>
namespace nam
{
	class Ecs;
	class Scene;
	class GameObject;

	class SceneManager final
	{
	private:
		Ecs* mp_ecs;
		UnMap<u32, Scene*> m_allCurrentScene;
		UnMap<u32, Scene*> m_allScene;
		UnMap<u32, GameObject*> m_allGameObjectInAllScene;
		uint32_t m_idNext;
	public:

		SceneManager();

		void Init();
		void Start();
		void CleanUpdate();
		void Destroy();

		void Reset();

		void AddCurrentScene(Scene* scene);
		void AddCurrentScene(u32 idScene);
		void RemoveCurrentScene(Scene* scene);
		void RemoveCurrentScene(u32 idScene);
		void SwitchCurrentScene(Scene* sceneClose, Scene* sceneOpen);
		void SwitchCurrentScene(u32 idSceneClose, u32 idSceneOpen);

		Scene* CreateScene();
		void DestroyScene(Scene* scene);

	private:

		void SetActiveScene(Scene* scene, bool active);
		void SetActiveScene(u32 idScene, bool active);

		void SetActiveAllScene(bool active);

		void DestroyAllScene();

		void IncreaseIdNext();

	public:

		Scene* GetScene(u32 idScene);
		GameObject* GetGameObjectInGame(Entity& entity);
		GameObject* GetGameObjectInGame(u32 idEntity);

		const UnMap<u32, Scene*>& GetAllScene() const;

		const UnMap<u32, GameObject*>& GetAllGameObjectInAllScene() const;

		const UnMap<u32, Scene*>& GetCurrenteScene() const;

		void SetEcs(Ecs* ecs);
		//Ecs* GetEcs();

		~SceneManager();

	private:
		friend class Scene;
	};
}

