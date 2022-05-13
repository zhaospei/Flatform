#pragma once
#include "../GameManager/ResourceManager.h"
#include "../GameManager/OperationsManager.h"
#include "../GameManager/HighScore.h"

#include "GameStateMachine.h"
#include <iostream>
#include "GameButton.h"

class GameStateBase {
public:
	GameStateBase(){}
	virtual ~GameStateBase();

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	static GameStateBase* CreateState(StateTypes st);
protected:
	list<RectangleShape*> m_Background;
	list<GameButton*> m_Button;
	list<Text*> m_Text;
};
