#include "pch.h"
#include "Score.h"

Score::Score()
{
	m_score = 0;
}

void Score::OnInit()
{
	m_timer.Init(1.f);
	m_score = 0;

	XMFLOAT3 pos = { 20, 20, 0 };
	SetWorldPosition(pos);
	SetupText(XMFLOAT2(40, 40), 0.5f, { 1.f, 1.f, 1.f, 1.f });
	mp_textRender = &GetComponent<TextRendererComponent>();

	SetupBehavior();
	SetTag((int)Tag::_None);
}

void Score::OnStart()
{
	m_score = 0;
}

void Score::OnUpdate()
{
	App* app = App::Get();
	float dt = app->GetChrono().GetScaledDeltaTime();

	m_timer.Update(dt);

	if (m_timer.IsTargetReached())
	{
		m_timer.ResetProgress();
		IncreaseScore(1);
	}

	mp_textRender->SetTextPrint("Score : " + std::to_string(m_score), true);
}

void Score::OnDestroy()
{

}

void Score::SetScore(int score)
{
	m_score = score;
}

void Score::IncreaseScore(int add)
{
	m_score += add;
}

int Score::GetScore()
{
	return m_score;
}


