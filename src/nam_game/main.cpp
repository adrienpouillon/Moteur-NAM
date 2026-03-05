#include "pch.h"
#include "main.h"

#include <LoadingScreen.h>
#include <Benchmark.h>

enum Textures : size
{
	_Yellow,
	_Rainbow,
	_Stone,
	_Dirt,
	_Crepit,
	_Tuile,
	_Heart,
	_Grass,
	_Bat,
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow)
{
    App* app = App::Get(hInstance, 1920, 1040);

	Light* p_sun = app->GetLightManager().CreateLight();
	p_sun->SetToDirectionalLight(0.75f, { 0, -1, 0 }, { 1, 1, 1 });
	
	//start game
	{
		//system
		app->LoadTexture(L"yellow.dds", _Yellow, true);
		app->LoadTexture(L"rainbow.dds", _Rainbow, true);
		app->LoadTexture(L"stone.dds", _Stone, true);
		app->LoadTexture(L"dirt.dds", _Dirt, true);

		app->LoadTexture(L"crepit.dds", _Crepit, true);
		app->LoadTexture(L"tuile.dds", _Tuile, true);
		app->LoadTexture(L"heart.dds", _Heart, true);
		app->LoadTexture(L"grass.dds", _Grass, true);
  		app->LoadTexture(L"../../res/Assets/Bat/bat.dds", _Bat);

		GameObject* appCamera = app->GetCamera();

		//creation caveScene
		Scene* caveScene = app->CreateScene();
		{
			//initialisation des objets

			//creation player
			Player* player = caveScene->CreateGameObject<Player>();
			{
				MeshRendererComponent meshComp;
				float tall = 1.f;
				meshComp.CreateMeshInstance();
				meshComp.mp_mesh->BuildCylinder(0.5f, 20, tall, { 1,1,1,1 });
				meshComp.mp_mesh->SetTexture(_Stone);
				
				XMFLOAT3 pos = XMFLOAT3(0.f, 0.f, -5.f);
				player->SetWorldPosition(pos);

				Mesh* mesh = app->CreateEmptyMesh();
				mesh->BuildUvSphere(1.f, 5, 5, { 1.f, 1.f, 1.f, 1.f });
				mesh->SetTexture(_Heart);

				player->SetBoxCollider();
				player->SetMeshShot(mesh);
				player->AddComponent(meshComp);
			}

		
			//voxel test
			GameObject* testVoxel = caveScene->CreateGameObject<GameObject>();
			{
				VoxelGrid vgrid;
				vgrid.MakeVoxelSphere(0.2f, 2.f);
				vgrid.MakeHole({ -2,-2,-2 }, { 2,2,2 }, 1.f);

				MeshRendererComponent mesh;
				mesh.CreateMeshInstance();

				mesh.mp_mesh->BuildFromVoxels(vgrid,{1,1,1,1});
				mesh.mp_mesh->SetTexture(_Stone);
		
				mesh.mp_mesh->MakeRainbowVertices();

				XMFLOAT3 pos = XMFLOAT3(0.f, 0.f, 5.f);
				testVoxel->SetWorldPosition(pos);
				testVoxel->AddComponent(mesh);
				testVoxel->SetSphereCollider();

			}

			//voxel test 2
			GameObject* testVoxel2 = caveScene->CreateGameObject<GameObject>();
			{
				VoxelGrid vgrid;
				vgrid.MakeVoxelSphere(0.2f, 3.f);
				vgrid.MakeHole({ -2,-2,-2 }, { 2,2,2 }, 1.f);

				MeshRendererComponent mesh;
				mesh.CreateMeshInstance();

				mesh.mp_mesh->BuildFromVoxels(vgrid, { 1,1,1,1 });
				mesh.mp_mesh->MakeNoise();
				mesh.mp_mesh->MakeVerticesColorFromNormals({ 0,1,0,1 }, { 0.5, 0.5, 0.5, 1 });

				//mesh.m_mesh.SetTexture(_Stone);

				XMFLOAT3 pos = XMFLOAT3(5.f, 0.f, 5.f);
				testVoxel2->SetWorldPosition(pos);
				testVoxel2->AddComponent(mesh);
				testVoxel2->SetSphereCollider();
			}

			//creation enemy
			Mesh* p_bat_origin = app->CreateEmptyMesh();
			//p_bat_origin->LoadObj(L"../../res/Assets/Mogwai/mogwai.obj");
			p_bat_origin->LoadObj(L"../../res/Assets/Bat/bat.obj");
			p_bat_origin->SetTexture(_Bat);

			for (int i = 0; i < 10; i++)
			{
				Enemy* bat = caveScene->CreateGameObject<Enemy>();
				{
					MeshRendererComponent meshComp;
					float tall = 1.f;
					Mesh* p_bat = app->CreateEmptyMesh();
					*p_bat = *p_bat_origin;
					p_bat->SetToDynamic(65536, 131072);
					meshComp.SetMeshInstance(p_bat);
					
					XMFLOAT3 pos = XMFLOAT3(cos(i * 10) * 2, 1, sin(i * 10) * 2);
					float ran = Rng::Float(0.2f, 1.f);
					XMFLOAT3 scale = XMFLOAT3(ran, ran, ran);

					bat->SetLife(5);
					bat->SetWorldPosition(pos);
					bat->SetWorldScale(scale);
					bat->AddComponent(meshComp);
					bat->SetBoxCollider();
					bat->ActiveDeleteMesh(true);
				}
			}
			
			FPSDisplayer* fps = caveScene->CreateGameObject<FPSDisplayer>();

			//creation floor
			GameObject* floor = caveScene->CreateGameObject<GameObject>();
			{
				MeshRendererComponent mesh;
				mesh.CreateMeshInstance();
				mesh.mp_mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh.mp_mesh->SetTexture(_Grass);
	
				XMFLOAT3 pos = XMFLOAT3( 0.f, -5.f, 0.f);
				floor->SetWorldPosition(pos);

				floor->AddComponent(mesh);
			}

			//creation wall x-
			GameObject* wallXLess = caveScene->CreateGameObject<GameObject>();
			{
				MeshRendererComponent mesh;
				float tall = 0.1f;
				mesh.CreateMeshInstance();
				mesh.mp_mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh.mp_mesh->SetTexture((int)Textures::_Stone);

				XMFLOAT3 pos = XMFLOAT3(-50.f, -tall, 0.f);
				wallXLess->SetWorldPosition(pos);
				XMFLOAT3 rot = XMFLOAT3(0.f, 0.f, 3.14f / 2.f);
				wallXLess->SetWorldYPR(rot);
				XMFLOAT3 scale = XMFLOAT3(1.f, 1.f, 3.f);
				wallXLess->SetWorldScale(scale);

				wallXLess->AddComponent(mesh);
			}

			//creation wall x+
			GameObject* wallXMore = caveScene->CreateGameObject<GameObject>();
			{
				MeshRendererComponent mesh;
				float tall = 0.1f;
				mesh.CreateMeshInstance();
				mesh.mp_mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh.mp_mesh->SetTexture((int)Textures::_Stone);

				XMFLOAT3 pos = XMFLOAT3(50.f, -tall, 0.f);
				wallXMore->SetWorldPosition(pos);
				XMFLOAT3 rot = XMFLOAT3(0.f, 0.f, 3.14f / 2.f);
				wallXMore->SetWorldYPR(rot);
				XMFLOAT3 scale = XMFLOAT3(1.f, 1.f, 3.f);
				wallXMore->SetWorldScale(scale);

				wallXMore->AddComponent(mesh);
			}

			//creation wall y+
			GameObject* wallYMore = caveScene->CreateGameObject<GameObject>();
			{
				MeshRendererComponent mesh;
				float tall = 0.1f;
				mesh.CreateMeshInstance();
				mesh.mp_mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh.mp_mesh->SetTexture((int)Textures::_Stone);

				XMFLOAT3 pos = XMFLOAT3(0.f, -tall, 50.f);
				wallYMore->SetWorldPosition(pos);
				XMFLOAT3 rot = XMFLOAT3(0.f, 3.14f / 2.f, 0.f);
				wallYMore->SetWorldYPR(rot);
				XMFLOAT3 scale = XMFLOAT3(3.f, 1.f, 1.f);
				wallYMore->SetWorldScale(scale);

				wallYMore->AddComponent(mesh);
			}

			//creation wall y-
			GameObject* wallYLess = caveScene->CreateGameObject<GameObject>();
			{
				MeshRendererComponent mesh;
				float tall = 0.1f;
				mesh.CreateMeshInstance();
				mesh.mp_mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
				mesh.mp_mesh->SetTexture((int)Textures::_Stone);
	
				XMFLOAT3 pos = XMFLOAT3(0.f, -tall, -50.f);
				wallYLess->SetWorldPosition(pos);
				XMFLOAT3 rot = XMFLOAT3(0.f, 3.14f / 2.f, 0.f);
				wallYLess->SetWorldYPR(rot);
				XMFLOAT3 scale = XMFLOAT3(3.f, 1.f, 1.f);
				wallYLess->SetWorldScale(scale);

				wallYLess->AddComponent(mesh);
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
				TransformComponent transform;
				DirectX::XMFLOAT3 pos = { 0, 0, 0 };
				transform.SetWorldPosition(pos);

				ParticleEmitersComponent emiters;
				// {
				//	XMFLOAT3 maxXYZ = { 0,2,0 }; XMFLOAT3 minXYZ = { 0,2,0 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 startColor = { 1,0,0 }; XMFLOAT3 endColor = { 1,1,0 }; float maxSpeed = 0.3f; float minSpeed = 0.05f;
				//	float lifeTime = 5.f; float spawnRate = 20000.f;
				//	emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
				//}

				//{
				//	XMFLOAT3 maxXYZ = { 0,3,0 }; XMFLOAT3 minXYZ = { 0,3,0 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 startColor = { 0,1,0 }; XMFLOAT3 endColor = { 0,1,1 }; float maxSpeed = 0.3f; float minSpeed = 0.05f;
				//	float lifeTime = 5.f; float spawnRate = 20000.f;
				//	emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
				//}

				//{
				//	XMFLOAT3 maxXYZ = { 0,1,0 }; XMFLOAT3 minXYZ = { 0,1,0 }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 startColor = { 0,0,1 }; XMFLOAT3 endColor = { 1,0,1 }; float maxSpeed = 0.3f; float minSpeed = 0.05f;
				//	float lifeTime = 5.f; float spawnRate = 20000.f;
				//	emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
				//}

				{
					// partical emmiter index 0			{ pos.x + 6.f, pos.y + 1.f, pos.z + 1.f }	{ pos.x + 4.f, pos.y - 1.f, pos.z - 1.f }												{0.30f, 0.15f, 0.05f} {0.65f, 0.40f, 0.20f}
					//XMFLOAT3 pos = player->GetWorldPosition();
					XMFLOAT3 maxXYZ = { 0.f, 0.f, 0.f }; XMFLOAT3 minXYZ = { 0.f, 0.f, 0.f }; XMFLOAT3 maxDir = { 1,1,1 }; XMFLOAT3 minDir = { -1,-1,-1 }; XMFLOAT3 startColor = { 0.65f, 0.40f, 0.20f }; XMFLOAT3 endColor = { 0.975f, 0.60f, 0.30f }; float maxSpeed = 0.5f; float minSpeed = 0.1f;
					float lifeTime = 10.f; float spawnRate = 2000.f;
					emiters.AddEmiter(maxXYZ, minXYZ, maxDir, minDir, startColor, endColor, maxSpeed, minSpeed, lifeTime, spawnRate);
				}

				particleEmitter->AddComponent(transform);
				particleEmitter->AddComponent(emiters);
				player->SetParticleEmitter(particleEmitter);
			}

			//button
			{
				GameObject* e1 = caveScene->CreateGameObject<GameObject>();

				DirectX::XMFLOAT3 pos = { 960, 540, 0 };
				DirectX::XMFLOAT3 ypr = { 0, 0, DirectX::XM_PIDIV4 };

				e1->SetWorldPosition(pos);
				e1->SetWorldYPR(ypr);

				ButtonComponent button;
				button.OnHovered = []() { std::cout << "hover" << std::endl; };
				button.OnClick = []() { std::cout << "click" << std::endl; };
				button.OnLeft = []() { std::cout << "left" << std::endl; };
				
				SpriteRendererComponent sprite;
				sprite.CreateSpriteInstance();
				sprite.mp_sprite->BuildRect({200 ,100},{1,1,1,1});
				sprite.mp_sprite->SetTexture(_SplashScreen);
				sprite.mp_sprite->SetDrawLayer(1);

				e1->AddComponent(sprite);
				e1->AddComponent(button);
			}

			//lancer
			caveScene->Start();
			app->AddCurrentScene(caveScene);
		}
	}

	//lancer le jeu
	app->Run();	
}
