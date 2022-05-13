#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSSetting : public GameStateBase {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Text* music;
	sf::Text* sound;
	GameButton* Gmusic;
	GameButton* Gsound;
};