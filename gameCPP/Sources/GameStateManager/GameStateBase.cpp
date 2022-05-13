#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSSetting.h"
#include "GSAbout.h"
#include "GSHighScore.h"
#include "GSInput.h"
#include "GSPause.h"
#include "GSEnd.h"

GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st)
	{
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case SETTING:
		gs = new GSSetting();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	case HIGHSCORE:
		gs = new GSHighScore();
		break;
	case _INPUT:
		gs = new GSInput();
		break;
	case PAUSE:
		gs = new GSPause();
		break;
	case END:
		gs = new GSEnd();
		break;
	}
	return gs;
}

GameStateBase::~GameStateBase()
{
	while (!m_Background.empty())
	{
		if (m_Background.front() != nullptr)
		{
			delete m_Background.front();
		}
		m_Background.pop_front();
	}
	while (!m_Button.empty())
	{
		if (m_Button.front() != nullptr)
		{
			delete m_Button.front();
		}
		m_Button.pop_front();
	}
	while (!m_Text.empty())
	{
		if (m_Text.front() != nullptr)
		{
			delete m_Text.front();
		}
		m_Text.pop_front();
	}
}
