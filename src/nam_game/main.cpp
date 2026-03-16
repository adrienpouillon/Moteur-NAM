#include "pch.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow)
{
    App* app = App::Get(hInstance, 1920, 1080);

	//start game
	{
		//system
		//Make::AddSystem<...>();

		Make::LoadTexture(L"yellow.dds", (size)Textures::_Yellow, true);
		Make::LoadTexture(L"rainbow.dds", (size)Textures::_Rainbow, true);
		Make::LoadTexture(L"stone.dds", (size)Textures::_Stone, true);

		Make::LoadTexture(L"crepit.dds", (size)Textures::_Crepit, true);
		Make::LoadTexture(L"tuile.dds", (size)Textures::_Tuile, true);
		Make::LoadTexture(L"heart.dds", (size)Textures::_Heart, true);
		Make::LoadTexture(L"grass.dds", (size)Textures::_Grass, true);

		//creation uiScene
		UiScene* uiScene = Make::CreateScene<UiScene>((size)TagScene::_UI);
		uiScene->GenerateGameObject();

		//creation gameScene
		GameScene* gameScene = Make::CreateScene<GameScene>((size)TagScene::_Scene);
		gameScene->GenerateGameObject();

		//lancer
		uiScene->Start();
		gameScene->Start();
		Make::AddCurrentScene(uiScene);
		Make::AddCurrentScene(gameScene);
	}

	//lancer le jeu
	app->Run();	
}