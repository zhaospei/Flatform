#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

#include <list>
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Map/Map1.h"
#include "../GameObjects/Map/Map2.h"
#include "../GameObjects/Map/Map3.h"
#include "../GameObjects/Map/Map4.h"
#include "../GameObjects/Map/Map5.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Map*> list_Map;
	sf::RectangleShape health[3];
	sf::Text* pickcoin;
};