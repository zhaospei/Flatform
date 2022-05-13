#pragma once
#include"Map.h"
class Map3 : public Map
{
private:
	const int map3[12][20] = {
		//	 0   1   2   3   4  5  6   7   8   9   0   1  2  3  4  5  6  7  8  9 
			{9 , 9 , 9 , 9 , 9, 9, 2 , 0 , 0 , 10, 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 0
			{9 , 9 , 3 , 9 , 9, 9, 2 , 0 , 0 , 0 , 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 1
			{3 , 8 , 0 , 5 , 3, 3, 8 , 0 , 0 , 0 , 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,14,13}, // 2
			{0 , 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 0 , 0 , 0 ,0, 0 ,0, 13,0 ,0 ,0 ,0 }, // 3
			{0 , 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 11, 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 4
			{0 , 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 12, 0 , 13,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 5
			{0 , 0 , 0 , 6 , 1, 1, 7 , 0 , 0 , 12, 0 , 0 ,0, 0 ,0, 0 ,0 ,13,0 ,0 }, // 6
			{13, 13, 13, 9 , 3, 3, 9 , 7 , 0 , 12, 0 , 0 ,0, 13,0, 0 ,0 ,0 ,0 ,0 }, // 7
			{0 , 0 , 0 , 10, 0, 0, 10, 0 , 0 , 12, 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 8
			{0 , 0 , 0 , 0 , 0, 0, 0 , 0 , 0 , 12, 0 , 0 ,0, 0 ,0, 0 ,0 ,0 ,0 ,0 }, // 9
			{1 , 1 , 1 , 7 , 0, 0, 6 , 1 , 1 , 9 , 7 , 0 ,0, 0 ,0, 13,0 ,0 ,6 ,1 }, // 10
			{9 , 9 , 9 , 2 , 0, 0, 4 , 9 , 9 , 9 , 2 , 0 ,0, 0 ,0, 0 ,0 ,0 ,4 ,9 }, // 11

	};
public:
	Map3();
	~Map3();
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
	void setWater();
	void setAnimation();
	void setPlayer();
	void setEnemies();
	void setBox();
};
