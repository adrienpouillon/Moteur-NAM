#include "pch.h"
#include "GameScene.h"

GameScene::GameScene() : Scene()
{

}

void GameScene::OnInit()
{
	
}

void GameScene::OnStart()
{

}

void GameScene::OnDestroy()
{

}

void GameScene::GenerateGameObject()
{
	GameObject* appCamera = App::Get()->GetCamera();

	//initialisation des objets
	Light* p_sun = Make::CreateEmptyLight();
	p_sun->SetToDirectionalLight(0.75f, { 0, -1, 0 }, { 1, 1, 1 });

	//creation player
	Player* player = CreateGameObject<Player>();
	{
		Mesh* mesh = Make::CreateEmptyMesh();
		mesh->BuildCylinder(0.5f, 20, 1.f, { 1.f,1.f,1.f,1.f });
		mesh->SetTexture((size)Textures::_Stone);


		XMFLOAT3 pos = XMFLOAT3(0.f, 1.f, 0.f);
		player->SetWorldPosition(pos);
		player->SetupMesh(mesh);
	}

	//creation enemy
	Enemy* enemy = CreateGameObject<Enemy>();
	{
		Mesh* mesh = Make::CreateEmptyMesh();
		mesh->BuildUvSphere(1.f, 20, 20, { 1, 1, 1, 1 });
		mesh->MakeRainbowVertices();
		mesh->SetTexture((size)Textures::_Stone);

		XMFLOAT3 pos = XMFLOAT3(10.f, 1.f, -5.f);

		Light* light = Make::CreateEmptyLight();
		light->SetToPointLight(1.f, pos, 5.f, { 1, 1, 1 });

		enemy->SetupSphereCollider();
		enemy->SetWorldPosition(pos);
		enemy->SetupMesh(mesh);
		enemy->SetupLight(light);

		LifeComponent& lifeComponent = enemy->SetupCustom<LifeComponent>();
		lifeComponent.m_life = 162;
	}

	//creation enemy
	Enemy* enemy2 = CreateGameObject<Enemy>();
	{
		Mesh* mesh = Make::CreateEmptyMesh();
		mesh->BuildCube(1.f, { 1, 1, 1, 1 });
		mesh->MakeRainbowVertices();
		mesh->SetTexture((size)Textures::_Stone);

		XMFLOAT3 pos = XMFLOAT3(10.f, 1.f, 5.f);

		enemy2->SetupSphereCollider();
		enemy2->SetWorldPosition(pos);
		enemy2->SetupMesh(mesh);

		LifeComponent& lifeComponent = enemy2->SetupCustom<LifeComponent>();
		lifeComponent.m_life = 233;
	}

	//creation floor
	GameObject* floor = CreateGameObject<GameObject>();
	{
		Mesh* mesh = Make::CreateEmptyMesh();
		mesh->BuildPlane(XMFLOAT2(50.f, 50.f), { 1,1,1,1 }, true);
		mesh->SetTexture((size)Textures::_Grass);

		XMFLOAT3 pos = XMFLOAT3(0.f, -5.f, 10.f);
		floor->SetWorldPosition(pos);
		floor->SetupMesh(mesh);
	}

	//creation Camera
	Camera* camera = CreateGameObject<Camera>();
	{
		camera->SetAppCamera(appCamera);
		camera->SetTarget(player);
	}

	//creation Particle Emitter
	GameObject* particleEmitter = CreateGameObject<GameObject>();
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
}
