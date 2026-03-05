#include "pch.h"
#include "FPSDisplayer.h"
#include <TextRendererComponent.h>

void FPSDisplayer::OnInit()
{
	SetBehavior();
	SetTag((int)Tag::_Player);

	TextRendererComponent textRender;

	Text* p_text = textRender.CreateTextInstance();

	p_text->SetDatas({ 56, 56 }, 0.75f, { 1, 1, 1, 1 });
	p_text->SetText("FPS,.;:/'!?@()%123456789\"UwU");
	p_text->MakeRainbowVertices();

	p_text->SetTexture(_FontPusab);
	p_text->SetToDynamic(MAX_TEXT_VERTICES, MAX_TEXT_INDICES);

	XMFLOAT3 pos = { 20, 20, 0 };
	SetWorldPosition(pos);
	AddComponent(textRender);

	m_refreshTimer.Init(1.f, false);
}

void FPSDisplayer::OnStart()
{

}

void FPSDisplayer::OnUpdate()
{
	App* app = App::Get();
	int fpsCount = app->GetChrono().GetFPS();
	float dt = app->GetChrono().GetRealDeltaTime();

	Timer* p_timer = GetTimer();

	p_timer->Update(dt);

	if (p_timer->IsTargetReached())
	{
		p_timer->ResetProgress();

		std::string toDisplay = "FPS : " + std::to_string(fpsCount);

		TextRendererComponent& textComp = GetComponent<TextRendererComponent>();

		textComp.mp_text->SetText(toDisplay);
		textComp.mp_text->MakeRainbowVertices();
	}
}

void FPSDisplayer::OnCollision(u32 self, u32 other, const CollisionInfo& collisionInfo)
{

}

void FPSDisplayer::OnDestroy()
{
}

Timer* FPSDisplayer::GetTimer()
{
	return &m_refreshTimer;
}

