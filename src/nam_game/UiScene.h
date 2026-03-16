#pragma once
class UiScene : public Scene
{
private:

public:
	UiScene();

	void OnInit() override;
	void OnStart() override;
	void OnDestroy() override;

	void GenerateGameObject();
};

