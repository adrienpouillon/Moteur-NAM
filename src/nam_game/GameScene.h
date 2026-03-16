#pragma once
class GameScene : public Scene
{
private:

public:
	GameScene();

	void OnInit() override;
	void OnStart() override;
	void OnDestroy() override;

	void GenerateGameObject();
};

