#pragma once
#include"Map.h"

class Map1 : public Map {
private:
	const int map1[12][20] = {
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, 
			{2,0,0,0,6,1,7,0,0,0,0,0,0,0,0,0,0,0,0,4}, 
			{2,0,0,0,5,9,9,7,0,0,0,0,0,0,0,0,0,0,0,4}, 
			{9,7,0,0,0,4,9,9,1,7,0,0,0,0,0,0,0,0,0,4}, 
			{9,8,0,0,0,4,9,9,9,9,1,1,1,1,1,1,1,1,1,9}, 
			{2,0,0,0,0,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9}, 
			{2,0,0,0,6,9,9,9,3,3,3,3,9,9,3,3,3,3,3,9}, 
			{2,0,0,0,4,9,9,8,0,0,0,0,5,8,0,0,0,0,0,4}, 
			{9,7,0,0,4,9,8,0,0,0,0,0,0,0,0,0,0,0,0,4}, 
			{9,8,0,0,5,8,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, 
			{2,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,1,1,1,9}, 
			{9,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9}, 
	};
public:
	Map1();
	~Map1();
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
	void setAnimation();
	void setPlayer();
	void setEnemies();
};

