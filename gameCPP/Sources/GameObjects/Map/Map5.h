#pragma once
#include"Map.h"

class Map5 : public Map
{
private:
	const int map5[12][20] = {
		//   0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9 
			{0 ,0 ,0 ,-5,-3,-3,4 ,9 ,9 ,9 ,8 ,-2,0 ,0 ,0 ,0 ,5 ,3 ,3 ,9 }, // 0
			{0 ,0 ,0 ,0 ,0 ,0 ,4 ,9 ,9 ,8 ,-9,-2,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 }, // 1
			{0 ,0 ,0 ,0 ,0 ,0 ,4 ,9 ,8 ,-9,-9,-2,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 }, // 2
			{0 ,0 ,14,13,15,0 ,5 ,8 ,0 ,-5,-3,-8,0 ,0 ,17,1 ,1 ,1 ,1 ,9 }, // 3
			{0 ,0 ,0 ,12,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5 ,3 ,9 ,9 ,9 }, // 4
			{0 ,0 ,0 ,12,0 ,14,13,13,13,13,13,15,0 ,0 ,0 ,0 ,0 ,5 ,9 ,9 }, // 5 
			{0 ,0 ,0 ,10,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5 ,9 }, // 6 
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 }, // 7
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 }, // 8
			{0 ,0 ,0 ,11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 }, // 9
			{0 ,0 ,0 ,4 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,7 ,0 ,0 ,6 ,1 ,1 ,1 ,1 ,9 }, // 10
			{1 ,1 ,1 ,4 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,2 ,0 ,0 ,4 ,9 ,9 ,9 ,9 ,9 }, // 11
	};
public:
	Map5();
	~Map5();
	void Render(sf::RenderWindow* window);
	void Update(const float& deltaTime);
private:
	void setBackGround();
	void setButtom();
	void setCoins();
	void setDoor();
	void setExitdoor();
	void setGround();
	void setSpikes();
	void setStone();
	void setPlayer();
	void setEnemies();
	void setMushroom();
	void setLeverTurn();
	void setWater();
};