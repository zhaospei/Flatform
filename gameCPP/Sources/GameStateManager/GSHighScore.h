#pragma once
#include "GameStateBase.h"
#include "GameButton.h"
#include <fstream>
#include "../GameManager/HighScore.h"


class GSHighScore : public GameStateBase {
public:
	GSHighScore();
	virtual ~GSHighScore();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Hight_Score* arrHightScore;
	sf::Text textHightScore[5][3];
};