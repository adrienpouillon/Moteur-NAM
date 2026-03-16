#pragma once
namespace nam
{
	class Make
	{
	private:
		Make();
		~Make();

		static App* msp_app;
		static Ecs* msp_ecs;
		static SceneManager* msp_sceneManager;
		static AppChrono* msp_appChrono;
	public:
		//for clean and replace static value
		static void RefreshValue();

		static App* GetApp();

		template<typename Component>
		static void AddComponent(const Entity& entity, const Component& data);
		//template<typename Component>
		//void RemoveComponent();
		template<typename Component>
		static const bool HasComponent(const Entity& entity);
		template<typename Component>
		static Component& GetComponent(const Entity& entity);

		template<typename System, typename... Args>
		static void AddSystem(Args&&... args);
		//template<typename System>
		//static void RemoveSystem();
		template<typename System>
		static void SetSystemEnabled(const bool enabled);

		template<typename... Components, typename Func>
		static void ForEach(Func&& func);
		template<typename... Components, typename Func>
		static void DoubleForEach(Func&& func);

		template<typename T>
		static T* CreateGameObject(Scene* scene);
		template<typename T>
		static T* CreateGameObject(u32 idScene);
		static void DestroyGameObject(GameObject* gameObject, Scene* scene);
		static void DestroyGameObject(GameObject* gameObject, u32 idScene);
		static void DestroyGameObjectIsSingle(GameObject* gameObject, Scene* scene, bool isSingleGameObject);
		static void DestroyGameObjectIsSingle(GameObject* gameObject, u32 idScene, bool isSingleGameObject);
		static void SetActiveGameObject(Scene* scene, GameObject* gameObject, bool active);
		static void SetActiveGameObject(u32 idScene, GameObject* gameObject, bool active);
		static void SetActiveEntity(Scene* scene, const Entity& entity, bool active);
		static void SetActiveEntity(u32 idScene, const Entity& entity, bool active);
		static GameObject* GetGameObject(Scene* scene, u32 idEntity);
		static GameObject* GetGameObject(Scene* scene, const Entity& entity);
		static GameObject* GetGameObject(u32 idScene, u32 idEntity);
		static GameObject* GetGameObject(u32 idScene, const Entity& entity);
		static GameObject* GetGameObject(u32 idEntity);
		static GameObject* GetGameObject(const Entity& entity);

		template<typename T>
		static T* CreateScene(size sceneTag);
		static void DestroyScene(Scene* scene);
		static void AddCurrentScene(u32 idScene);
		static void AddCurrentScene(Scene* scene);
		static void AddCurrentScene(size sceneTag);
		
		static void RemoveCurrentScene(Scene* scene);
		static void RemoveCurrentScene(u32 idScene);
		static void RemoveCurrentScene(size sceneTag);
		
		static void SwitchCurrentScene(Scene* sceneClose, Scene* sceneOpen);
		static void SwitchCurrentScene(u32 idSceneClose, u32 idSceneOpen);
		static void SwitchCurrentScene(size sceneTag1, size sceneTag2);

		//Use it if your mesh need to be used in many Objects;
		//After that, Use the SetMeshInstance in the MeshRendererComponent
		static Mesh* CreateEmptyMesh();

		//Useful if your sprite need to be used in many Objects;
		//After that, Use the SetSpriteInstance in the SpriteRendererComponent
		static Sprite* CreateEmptySprite();

		//Useful if your text need to be used in many Objects;
		//After that, Use the SetTextInstance in the TextRendererComponent
		static Text* CreateEmptyText();

		//Useful if your text need to be used in many Objects;
		//After that, Use the SetLightInstance in the LightComponent
		static Light* CreateEmptyLight();
		static Light* GetLight(u8 lightID);

		static Scene* GetScene(u32 idScene);
		static Scene* GetScene(const Entity& entity);

		static const float GetRealDeltaTime();
		static const float GetScaledDeltaTime();

		// To call before Run() | if usingTextureFolder true -> the path will remains in the Textures Folder
		static void LoadTexture(std::wstring path, size uniqueTag, bool usingTextureFolder = false);

	private:
		static void SetApp(App* app);

		friend class App;
	};
	
}

#include "Make.inl"
