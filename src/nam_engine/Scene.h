#pragma once



namespace nam
{
	class Ecs;
	class SceneManager;
	class GameObject;

	class Scene
	{
	private:
		Ecs* mp_ecs;
		UnMap<u32, GameObject*> m_allGameObject;
		UnMap<u32, Entity> m_allEntityActiveFalse;
		UnMap<u32, GameObject*>* mp_allGameObjectInAllScene;
		UnMap<u32, GameObject*> m_allGameObjectToDestroy;
		u32 m_id;
		bool m_isActive;

		size m_tag = -1;
	protected:
		Scene();

	public:
		void Init();
		void Start();
		virtual void CleanUpdate();
		void Destroy();

		virtual void OnInit();
		virtual void OnStart();
		virtual void OnDestroy();

		void ResetScene();

		template<typename T>
		T* CreateGameObject();

		void DestroyGameObject(GameObject* gameObject);
		void DestroyGameObjectIsSingle(GameObject* gameObject, bool isSingleGameObject);

		void SetActiveEntity(const Entity& entity, bool active);

		void SetActiveAllEntity(bool active);

	protected:

		void DestroyEntity(const Entity& entity);
		void DestroyAllGameObjectIsSingle(bool isSingle);

		void SetAllGameObjectInAllScene(UnMap<u32, GameObject*>* allGameObjectInAllScene);

	public:

		const Entity GetEntity(u32 idEntity);
		GameObject* GetGameObject(const Entity& entity);
		GameObject* GetGameObject(u32 idEntity);

		const UnMap<u32, GameObject*>& GetAllGameObject() const;

		void SetId(u32 id);
		u32 GetId() const;

		void SetEcs(Ecs* ecs);
		//Ecs* GetEcs();

		bool GetIsActive() const;
		const size& GetTag() const;

		virtual ~Scene();

	private:

		void SetIsActive(bool isActive);

		friend class SceneManager;
		friend class GameObject;

	};
}
#include "Scene.inl"

