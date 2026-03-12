#include "pch.h"

enum Textures : size
{
	_Yellow,
	_Rainbow,
	_Stone,

	_Crepit,
	_Tuile,
	_Heart,
	_Grass,
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow)
{
    App* app = App::Get(hInstance, 1920, 1080);

	//start game
	{
		//system
		//Make::AddSystem<...>();

		Make::LoadTexture(L"yellow.dds", _Yellow, true);
		Make::LoadTexture(L"rainbow.dds", _Rainbow, true);
		Make::LoadTexture(L"stone.dds", _Stone, true);

		Make::LoadTexture(L"crepit.dds", _Crepit, true);
		Make::LoadTexture(L"tuile.dds", _Tuile, true);
		Make::LoadTexture(L"heart.dds", _Heart, true);
		Make::LoadTexture(L"grass.dds", _Grass, true);

		GameObject* appCamera = app->GetCamera();

		//creation caveScene
		Scene* caveScene = Make::CreateScene(0);
		{
			//initialisation des objets
			Light* p_sun = Make::CreateEmptyLight();
			p_sun->SetToDirectionalLight(0.75f, { 0, -1, 0 }, { 1, 1, 1 });

			//creation player
			Player* player = caveScene->CreateGameObject<Player>();
			{
				Mesh* mesh = Make::CreateEmptyMesh();
				mesh->BuildCylinder(0.5f, 20, 1.f, { 1.f,1.f,1.f,1.f });
				mesh->SetTexture(_Stone);


				XMFLOAT3 pos = XMFLOAT3(0.f, 1.f, 0.f);
				player->SetWorldPosition(pos);
				player->SetupMesh(mesh);
			}

			//creation enemy
			Enemy* enemy = caveScene->CreateGameObject<Enemy>();
			{
				Mesh* mesh = Make::CreateEmptyMesh();
				mesh->BuildUvSphere(1.f, 20, 20, { 1, 1, 1, 1 });
				mesh->MakeRainbowVertices();
				mesh->SetTexture(_Stone);

				XMFLOAT3 pos = XMFLOAT3( 10.f, 1.f, -5.f);

				Light* light = Make::CreateEmptyLight();
				light->SetToPointLight(1.f, pos, 5.f, { 1, 1, 1 });

				enemy->SetupSphereCollider();
				enemy->SetWorldPosition(pos);
				enemy->SetupMesh(mesh);
				enemy->SetupLight(light);
			}

			//creation enemy
			Enemy* enemy2 = caveScene->CreateGameObject<Enemy>();
			{
				Mesh* mesh = Make::CreateEmptyMesh();
				mesh->BuildCube(1.f, { 1, 1, 1, 1 });
				mesh->MakeRainbowVertices();
				mesh->SetTexture(_Stone);

				XMFLOAT3 pos = XMFLOAT3(10.f, 1.f, 5.f);

				enemy2->SetupSphereCollider();
				enemy2->SetWorldPosition(pos);
				enemy2->SetupMesh(mesh);
			}

			//creation floor
			GameObject* floor = caveScene->CreateGameObject<GameObject>();
			{
				Mesh* mesh = Make::CreateEmptyMesh();
				mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh->SetTexture(_Grass);

				XMFLOAT3 pos = XMFLOAT3( 0.f, -5.f, 10.f);
				floor->SetWorldPosition(pos);
				floor->SetupMesh(mesh);
			}

			//creation Camera
			Camera* camera = caveScene->CreateGameObject<Camera>();
			{
				camera->SetAppCamera(appCamera);
				camera->SetTarget(player);
			}

			//creation Particle Emitter
			GameObject* particleEmitter = caveScene->CreateGameObject<GameObject>();
			{
				XMFLOAT3 pos = { 0, 1, 4 };
				particleEmitter->SetWorldPosition(pos);

				{
					XMFLOAT3 minXYZ = { 0,2,0 }; XMFLOAT3 maxXYZ = { 0,2,0 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 startColor = { 1,0,0 }; XMFLOAT3 endColor = { 1,1,0 }; float minSpeed = 0.3f; float maxSpeed = 0.5f; float lifeTime = 2.f; float spawnRate = 100.f;
					particleEmitter->SetupParticle(minXYZ, maxXYZ, minDir, maxDir, startColor, endColor, minSpeed, maxSpeed, lifeTime, spawnRate);
				}

				{
					XMFLOAT3 minXYZ = { 0,3,0 }; XMFLOAT3 maxXYZ = { 0,3,0 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 startColor = { 0,1,0 }; XMFLOAT3 endColor = { 0,1,1 }; float minSpeed = 0.3f; float maxSpeed = 0.5f; float lifeTime = 2.f; float spawnRate = 100.f;
					particleEmitter->SetupParticle(minXYZ, maxXYZ, minDir, maxDir, startColor, endColor, minSpeed, maxSpeed, lifeTime, spawnRate);
				}

				{
					XMFLOAT3 minXYZ = { 0,1,0 }; XMFLOAT3 maxXYZ = { 0,1,0 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 startColor = { 0,0,1 }; XMFLOAT3 endColor = { 1,0,1 }; float minSpeed = 0.3f; float maxSpeed = 0.5f; float lifeTime = 2.f; float spawnRate = 100.f;
					particleEmitter->SetupParticle(minXYZ, maxXYZ, minDir, maxDir, startColor, endColor, minSpeed, maxSpeed, lifeTime, spawnRate);
				}
			}

			//creation score
			Score* score = caveScene->CreateGameObject<Score>();
			{
				//score->AddComponent<>
			}

			//button
			GameObject* button = caveScene->CreateGameObject<GameObject>();
			{
				XMFLOAT3 pos = { 960, 540, 0 };
				button->SetWorldPosition(pos);

				XMFLOAT3 ypr = { 0, 0, DirectX::XM_PIDIV4 };
				button->SetWorldYPR(ypr);
				
				Sprite* sprite = Make::CreateEmptySprite();
				sprite->BuildRect({200 ,100},{1,1,1,1});
				sprite->SetTexture(_Yellow);

				button->SetupSprite(sprite);
				button->SetupButton();
			}

			//lancer
			caveScene->Start();
			Make::AddCurrentScene(caveScene);
		}
	}

	//lancer le jeu
	app->Run();	
}