#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSAbout : public GameStateBase {
public:
	GSAbout();
	virtual ~GSAbout();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	float time = 0.5f;
	sf::RectangleShape click;
	sf::Text* link;
};