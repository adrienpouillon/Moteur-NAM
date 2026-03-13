#pragma once
#include "Ecs.h"
#include "SceneManager.h"

namespace nam
{
	class RenderManager;
	class Scene;
	class LightManager;
	class GameObject;
	class Make;
  
	struct Mesh;
	struct Sprite;
	struct Text;

	class LoadingScreen;

	class App final
	{
	private:
		static App* msp_instance;

		Ecs m_ecs;
		SceneManager m_sceneManager;
		Window m_window;
		AppChrono m_chrono;
		RenderManager* mp_renderManager;
		Make* m_make;

		GameObject* mp_camera;
		LoadingScreen* mp_loadingScreen;
		
		bool m_minimized;
		bool m_maximized;
		bool m_resizing;
		bool m_fullscreen;

		struct TextureData
		{
			std::wstring m_path = L"";
			size m_uniqueTag = 0;
			bool m_usingTextureFolder = false;
		};
		Vector<TextureData> m_texturesDataToLoad;

	private:
		App(HINSTANCE hInst, int startWindowWidth, int startWindowHeight);
	public:
		~App();

		// Pass the Window Settings the first time to Init the App, next times, just call Get() without anything in parameters !
		static App* Get(HINSTANCE hInst = 0, int startWindowWidth = -1, int startWindowHeight = -1);
		static void Destroy();

		void Init();
		void Start();
		void Run();

		int MainLoop();
		void Update();
		void Resize();

	private:
		void CreateCamera();
		void StartCamera();
		void CameraDefaultSettings(); 

		void ToggleDebugConsole(bool state);
	public:

		/*template<typename Component>
		void AddComponent(const Entity& entity, const Component& data);
		//template<typename Component>
		//void RemoveComponent();
		template<typename Component>
		const bool HasComponent(const Entity& entity) const;
		template<typename Component>
		Component& GetComponent(const Entity& entity);

		template<typename System, typename... Args>
		void AddSystem(Args&&... args);
		//template<typename System>
		//void RemoveSystem();
		template<typename System>
		void SetSystemEnabled(const bool enabled);

		template<typename... Components, typename Func>
		void ForEach(Func&& func);
		template<typename... Components, typename Func>
		void DoubleForEach(Func&& func);

		template<typename T>
		T* CreateGameObject(Scene* scene);
		template<typename T>
		T* CreateGameObject(u32 idScene);
		void DestroyGameObject(GameObject* gameObject, Scene* scene);
		void DestroyGameObject(GameObject* gameObject, u32 idScene);
		void SetActiveGameObject(Scene* scene, GameObject* gameObject, bool active);
		void SetActiveGameObject(u32 idScene, GameObject* gameObject, bool active);
		void SetActiveEntity(Scene* scene, const Entity& entity, bool active);
		void SetActiveEntity(u32 idScene, const Entity& entity, bool active);
		GameObject* GetGameObject(Scene* scene, u32 idEntity);
		GameObject* GetGameObject(Scene* scene, const Entity& entity);
		GameObject* GetGameObject(u32 idScene, u32 idEntity);
		GameObject* GetGameObject(u32 idScene, const Entity& entity);
		GameObject* GetGameObject(u32 idEntity);
		GameObject* GetGameObject(const Entity& entity);

		Scene* CreateScene(size sceneTag);
		void DestroyScene(Scene* scene);
		void AddCurrentScene(u32 idScene);
		void AddCurrentScene(Scene* scene);
		void AddCurrentScene(size sceneTag);

		void RemoveCurrentScene(Scene* scene);
		void RemoveCurrentScene(u32 idScene);
		void RemoveCurrentScene(size sceneTag);

		void SwitchCurrentScene(Scene* sceneClose, Scene* sceneOpen);
		void SwitchCurrentScene(u32 idSceneClose, u32 idSceneOpen);
		void SwitchCurrentScene(size sceneTag1, size sceneTag2);
		//Use it if your mesh need to be used in many Objects;
		//After that, Use the SetMeshInstance in the MeshRendererComponent
		Mesh* CreateEmptyMesh();

		//Useful if your sprite need to be used in many Objects;
		//After that, Use the SetSpriteInstance in the SpriteRendererComponent
		Sprite* CreateEmptySprite();

		//Useful if your text need to be used in many Objects;
		//After that, Use the SetTextInstance in the TextRendererComponent
		Text* CreateEmptyText();

		Light* CreateEmptyLight();
		Light* GetLight(u8 lightID);

		Scene* GetScene(u32 idScene);
		Scene* GetScene(const Entity& entity);

		const float GetRealDeltaTime() const;
		const float GetScaledDeltaTime() const;
		*/
		// To call before Run() | if usingTextureFolder true -> the path will remains in the Textures Folder
		void LoadTexture(std::wstring path, size uniqueTag, bool usingTextureFolder = false);
    
		Window& GetWindow();
		GameObject* GetCamera();

		//Ecs& GetEcs();
		SceneManager& GetSceneManager();

		AppChrono& GetChrono();

		LightManager& GetLightManager();

		LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	private:
		void RenderFirstFrame();
		void LoadTextures();

		Ecs& GetEcs();

		friend class GameObject;
		friend class Make;
	};
}

#include "App.inl"
