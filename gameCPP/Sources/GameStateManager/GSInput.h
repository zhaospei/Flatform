#pragma once
#include"GameButton.h"
#include"GameStateBase.h"
#include"../GameManager/HighScore.h"

class GSInput : public GameStateBase
{
public:
	GSInput();
	virtual ~GSInput();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Text* namePlayer = nullptr;
};

