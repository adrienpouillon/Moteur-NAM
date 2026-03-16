#include "pch.h"
#include "UiScene.h"

UiScene::UiScene() : Scene()
{

}

void UiScene::OnInit()
{

}

void UiScene::OnStart()
{

}

void UiScene::OnDestroy()
{

}

void UiScene::GenerateGameObject()
{
	//button
	GameObject* button = CreateGameObject<GameObject>();
	{
		XMFLOAT3 pos = { 960, 540, 0 };
		button->SetWorldPosition(pos);

		XMFLOAT3 ypr = { 0, 0, XM_PIDIV4 };
		button->SetWorldYPR(ypr);

		Sprite* sprite = Make::CreateEmptySprite();
		sprite->BuildRect({ 200 ,100 }, { 1,1,1,1 });
		sprite->SetTexture((size)Textures::_Yellow);

		button->SetupSprite(sprite);
		button->SetupButton();
	}

	//creation score
	Score* score = CreateGameObject<Score>();
}