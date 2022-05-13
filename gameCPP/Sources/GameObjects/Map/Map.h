#pragma once
#include"MapManager.h"
#include "../../GameManager/OperationsManager.h"

class Map
{
public:
	Map();
	virtual ~Map();
public:
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Update(const float& deltaTime);
	int ExitGame();
protected:
	void AddBackGround(const std::string& name, const Vector2f& size, const Vector2f& position);
	void RenderBackGround(sf::RenderWindow* window);
	void RenderGround(sf::RenderWindow* window);
	void RenderButtom(sf::RenderWindow* window);
	void RenderCoins(sf::RenderWindow* window);
	void RenderDoor(sf::RenderWindow* window);
	void RenderExitdoor(sf::RenderWindow* window);
	void RenderSpikes(sf::RenderWindow* window);
	void RenderStone(sf::RenderWindow* window);
	void RenderWater(sf::RenderWindow* window);
	void RenderAnimation(sf::RenderWindow* window);
	void RenderPlayer(sf::RenderWindow* window);
	void RenderEnemies(sf::RenderWindow* window);
	void RenderMushroom(sf::RenderWindow* window);
	void RenderLeverTurn(sf::RenderWindow* window);
	void RenderBox(sf::RenderWindow* window);
	void UpdateButtom(const float& deltaTime);
	void UpdateCoins(const float& deltaTime);
	void UpdateDoor(const float& deltaTime);
	void UpdateSpikes(const float& deltaTime);
	void UpdateStone(const float& deltaTime);
	void UpdateAnimation(const float& deltaTime);
	void UpdatePlayer(const float& deltaTime);
	void UpdateEnemies(const float& deltaTime);
	void UpdateMushroom(const float& deltaTime);
	void UpdateLeverTurn(const float& deltaTime);
	void UpdateBox(float deltaTime);
protected:
	Ground** grounds;
	int width = 0, height = 0;
	vector<Coin*> coins;
	vector<Enemies*> enemies;
	vector<RectangleShape*> background;
	list<Buttom*> buttoms;
	list<MushRoom*> mushrooms;
	list<Spikes*> spikes;
	list<Stone*> stones;
	list<Water*> waters;
	list<Box*> boxes;
	Player* player;
	Door* door;
	ExitDoor* exitdoor;
	LeverTurn* leverturn;
	ManagerAnimation managerAniamation;
	int exitgame;
	bool wingame;
};

