#include"Map2.h"
Map2::Map2() {
	setBackGround();
	setGround();
	setButtom();
	setCoins();
	setDoor();
	setExitdoor();
	setMushroom();
	setStone();
	setPlayer();
	setAnimation();
}
Map2::~Map2() {
}
void Map2::Render(sf::RenderWindow* window) {
	RenderBackGround(window);
	RenderGround(window);
	RenderButtom(window);
	RenderCoins(window);
	RenderDoor(window);
	RenderExitdoor(window);
	RenderMushroom(window);
	RenderStone(window);
	RenderAnimation(window);
	RenderPlayer(window);
}
void Map2::Update(const float& deltaTime) {
	Map::Update(deltaTime);
	UpdateButtom(deltaTime);
	UpdateCoins(deltaTime);
	UpdateDoor(deltaTime);
	UpdateMushroom(deltaTime);
	UpdateStone(deltaTime);
	UpdatePlayer(deltaTime);
	UpdateAnimation(deltaTime);
}
void Map2::setBackGround() {
	AddBackGround("BackGround/background", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/bg_1", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/grass_props1", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(11.0f * _SIZE_, 3.0f * _SIZE_));
	AddBackGround("BackGround/grass_props1", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(12.0f * _SIZE_, 3.0f * _SIZE_));
	AddBackGround("BackGround/grass_props1", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(15.0f * _SIZE_, 7.0f * _SIZE_));
	AddBackGround("BackGround/grass_props1", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(18.0f * _SIZE_, 9.0f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(10.0f * _SIZE_, 8.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(17.0f * _SIZE_, 9.5f * _SIZE_));
	AddBackGround("BackGround/bigflowers_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(12.0f * _SIZE_, 1.5f * _SIZE_));
}
void Map2::setButtom() {
	buttoms.push_back(new Buttom(sf::Vector2f(15.5f * _SIZE_, 5.0f * _SIZE_ - 6.25f)));
	buttoms.push_back(new Buttom(sf::Vector2f(19.5f * _SIZE_, 6.0f * _SIZE_ - 6.25f)));
}
void Map2::setCoins() {
	coins.push_back(new Coin(sf::Vector2f(175.0f, 184.0f)));
	coins.push_back(new Coin(sf::Vector2f(229.0f, 200.0f)));
	coins.push_back(new Coin(sf::Vector2f(254.0f, 230.0f)));
	coins.push_back(new Coin(sf::Vector2f(272.0f, 255.0f)));
	coins.push_back(new Coin(sf::Vector2f(294.0f, 292.0f)));
	coins.push_back(new Coin(sf::Vector2f(320.0f, 326.0f)));
	coins.push_back(new Coin(sf::Vector2f(359.0f, 259.0f)));
	coins.push_back(new Coin(sf::Vector2f(397.0f, 201.0f)));
	coins.push_back(new Coin(sf::Vector2f(412.0f, 158.0f)));
	coins.push_back(new Coin(sf::Vector2f(429.0f, 122.0f)));
	coins.push_back(new Coin(sf::Vector2f(441.0f, 88.0f)));
	coins.push_back(new Coin(sf::Vector2f(477.0f, 74.0f)));
	coins.push_back(new Coin(sf::Vector2f(775.0f, 216.0f)));
	coins.push_back(new Coin(sf::Vector2f(973.0f, 267.0f)));
}
void Map2::setDoor() {
	door = new Door(sf::Vector2f(13.0f * _SIZE_, 8.5f * _SIZE_));
}
void Map2::setExitdoor() {
	exitdoor = new ExitDoor(sf::Vector2f(15.5f * _SIZE_, 9.25f * _SIZE_));
}
void Map2::setGround() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map2[i][j] != 0) {
				grounds[i][j].setGround("Ground/" + to_string(map2[i][j]), j * _SIZE_, i * _SIZE_, map2[i][j]);
			}
		}
	}
}
void Map2::setMushroom() {
	mushrooms.push_back(new MushRoom(sf::Vector2f(2.5f * _SIZE_, 9.5f * _SIZE_)));
	mushrooms.push_back(new MushRoom(sf::Vector2f(6.5f * _SIZE_, 7.5f * _SIZE_)));
}
void Map2::setStone() {
	stones.push_back(new Stone(sf::Vector2f(10.5f * _SIZE_, 1.5f * _SIZE_)));
	stones.push_back(new Stone(sf::Vector2f(17.5f * _SIZE_, 1.5f * _SIZE_)));
}
void Map2::setAnimation() {
	managerAniamation.Add(new Animation("Animation/tiki_torch_props_strip_12", sf::Vector2u(12, 1), 0.1f), sf::Vector2f(16.0f * _SIZE_, 2.0f * _SIZE_ - 72.0f), sf::Vector2f(32.0f, 72.0f));
}
void Map2::setPlayer() {
	player = new Player(sf::Vector2f(1.0f * _SIZE_, 7.5f * _SIZE_),true);
}