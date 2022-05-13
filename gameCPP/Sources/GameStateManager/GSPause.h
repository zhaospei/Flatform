#pragma once
#include "GameButton.h"
#include "GameStateBase.h"

class GSPause : public GameStateBase
{
public:
	GSPause();
	virtual ~GSPause();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	GameButton* sound = nullptr;
	GameButton* music = nullptr;

	sf::Text* text_Sound = nullptr;
	sf::Text* text_Music = nullptr;
};

