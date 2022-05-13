#pragma once
#include"Map.h"

class Map4 : public Map
{
private:
	const int map4[12][20] =
	{
		//   0 1 2 3 4 5 6 7  8 9 0 1 2  3 4 5 6 7 8 9
			{0,0,0,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0,0,4}, // 0
			{0,0,0,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0,0,4}, // 1
			{1,1,1,7,0,0,0,0 ,0,0,0,0,0 ,0,0,0,6,1,1,9}, // 2
			{9,9,9,2,0,0,0,0 ,0,0,0,0,0 ,0,0,0,4,9,9,9}, // 3
			{9,9,9,2,0,0,0,0 ,0,0,0,0,0 ,0,0,0,4,9,9,9}, // 4
			{9,9,9,2,0,0,0,0 ,0,6,7,0,0 ,0,0,0,4,9,9,9}, // 5 
			{9,3,3,8,0,0,0,0 ,0,5,8,0,0 ,0,0,0,4,9,9,9}, // 6 
			{2,0,0,0,0,0,0,13,0,0,0,0,13,0,0,0,5,3,3,9}, // 7
			{2,0,0,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0,0,4}, // 8
			{9,1,1,1,1,1,1,7 ,0,0,0,0,11,0,0,0,0,0,0,4}, // 9
			{9,9,9,9,9,9,9,9 ,1,1,1,1,9 ,7,0,0,0,0,0,4}, // 10
			{9,9,9,9,9,9,9,9 ,9,9,9,9,9 ,9,1,1,1,1,1,4}, // 11
	};
public:
	Map4();
	~Map4();
	void Render(sf::RenderWindow* window);
	void Update(const float& deltaTime);
private:
	void setBackGround();
	void setButtom();
	void setCoins();
	void setDoor();
	void setExitdoor();
	void setGround();
	void setMushroom();
	void setSpikes();
	void setStone();
	void setAnimation();
	void setPlayer();
	void setEnemies();
	void setLeverTurn();
	void setBox();
};
