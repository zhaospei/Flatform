#pragma once
#include "../GameManager/Singleton.h"
#include <stack>

#define GSM GameStateMachine::GetInstance()

class GameStateBase;

enum StateTypes
{
	INTRO,
	MENU,
	PLAY,
	SETTING,
	ABOUT,
	HIGHSCORE,
	_INPUT,
	PAUSE,
	END,
};


class GameStateMachine :public CSingleton<GameStateMachine>{
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();

	void PerformStateChange();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;
	bool NeedToChangeState();
	bool HasState();

private:
	std::stack<GameStateBase*> m_StateStack;
	GameStateBase* m_ActivesState;
	GameStateBase* m_NextState;
};