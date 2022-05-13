#include "Map5.h"
Map5::Map5() {
	setBackGround();
	setButtom();
	setCoins();
	setDoor();
	setExitdoor();
	setGround();
	setSpikes();
	setStone();
	setPlayer();
	setEnemies();
	setMushroom();
	setLeverTurn();
	setWater();
}
Map5::~Map5() {
}
void Map5::Render(sf::RenderWindow* window) {
	RenderBackGround(window);
	RenderButtom(window);
	RenderWater(window);
	RenderCoins(window);
	RenderDoor(window);
	RenderExitdoor(window);
	RenderGround(window);
	RenderSpikes(window);
	RenderStone(window);
	RenderAnimation(window);
	RenderPlayer(window);
	RenderEnemies(window);
	RenderMushroom(window);
	RenderLeverTurn(window);
}
void Map5::Update(const float& deltaTime) {
	Map::Update(deltaTime);
	UpdateButtom(deltaTime);
	UpdateCoins(deltaTime);
	UpdateDoor(deltaTime);
	UpdateSpikes(deltaTime);
	UpdateStone(deltaTime);
	UpdateAnimation(deltaTime);
	UpdatePlayer(deltaTime);
	UpdateEnemies(deltaTime);
	UpdateMushroom(deltaTime);
	UpdateLeverTurn(deltaTime);
}
void Map5::setBackGround() {
	AddBackGround("BackGround/background", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(10.0f * _SIZE_, 4.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(11.0f * _SIZE_, 4.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(15.5f * _SIZE_, 2.5f * _SIZE_));
	AddBackGround("BackGround/bigflowers_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(6.5f * _SIZE_, 9.5f * _SIZE_));
	AddBackGround("BackGround/bigflowers_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(11.0f * _SIZE_, 9.5f * _SIZE_));
	AddBackGround("BackGround/flowers_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(18.0f * _SIZE_, 2.5f * _SIZE_));
}
void Map5::setButtom() {
	buttoms.push_back(new Buttom(sf::Vector2f(17.5f * _SIZE_, 10.0f * _SIZE_ - 6.25f)));
}
void Map5::setCoins() {
	coins.push_back(new Coin(sf::Vector2f(4.5f * _SIZE_, 4.75f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(4.5f * _SIZE_, 5.75f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(4.5f * _SIZE_, 6.75f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(50.0f, 200.0f)));
	coins.push_back(new Coin(sf::Vector2f(50.0f, 265.0f)));
	coins.push_back(new Coin(sf::Vector2f(50.0f, 350.0f)));
	coins.push_back(new Coin(sf::Vector2f(50.0f, 400.0f)));
	coins.push_back(new Coin(sf::Vector2f(90.0f, 400.0f)));
	coins.push_back(new Coin(sf::Vector2f(130.0f, 400.0f)));
	coins.push_back(new Coin(sf::Vector2f(873.0f, 458.0f)));
	coins.push_back(new Coin(sf::Vector2f(650.0f, 525.0f)));
}
void Map5::setDoor() {
	door = new Door(sf::Vector2f(15.5f * _SIZE_, 1.5f * _SIZE_));
}
void Map5::setExitdoor() {
	exitdoor = new ExitDoor(sf::Vector2f(17.5f * _SIZE_, 2.25f * _SIZE_));
}
void Map5::setGround() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map5[i][j] != 0)
				grounds[i][j].setGround("Ground/" + to_string(map5[i][j]), j * _SIZE_, i * _SIZE_, map5[i][j]);
		}
	}
}
void Map5::setSpikes() {
	spikes.push_back(new Spikes(sf::Vector2f(0.5f * _SIZE_, 10.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(1.5f * _SIZE_, 10.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(2.5f * _SIZE_, 10.5 * _SIZE_), true));
}
void Map5::setStone() {
	stones.push_back(new Stone(sf::Vector2f(2.5f * _SIZE_, 2.5f * _SIZE_)));
}
void Map5::setPlayer() {
	player = new Player(sf::Vector2f(15.0f * _SIZE_, 7.5f * _SIZE_), true);
}
void Map5::setEnemies() {
	enemies.push_back(new Enemies(3, sf::Vector2f(5.5f * _SIZE_, 9.5f * _SIZE_), sf::Vector2f(16.5f * _SIZE_, 9.5f * _SIZE_), sf::Vector2f(5.5f * _SIZE_, 9.5f * _SIZE_)));
	enemies.push_back(new Enemies(1, sf::Vector2f(8.5f * _SIZE_, 4.75f * _SIZE_), sf::Vector2f(11.5f * _SIZE_, 4.75f * _SIZE_), sf::Vector2f(11.5f * _SIZE_, 4.75f * _SIZE_)));
}
void Map5::setMushroom() {
	mushrooms.push_back(new MushRoom(sf::Vector2f(4.5f * _SIZE_, 9.5f * _SIZE_)));
}
void Map5::setLeverTurn() {
	leverturn = new LeverTurn(sf:: Vector2f(3.5f * _SIZE_, 2.5f * _SIZE_));
	leverturn->addWall(sf::Vector2f(1.0f * _SIZE_, 3.5f * _SIZE_), 1);
	leverturn->addWall(sf::Vector2f(13.0f * _SIZE_, 10.5f * _SIZE_), 1);
}
void Map5::setWater() {
	waters.push_back(new Water(sf::Vector2f(12.5f * _SIZE_, 11.25f * _SIZE_)));
	waters.push_back(new Water(sf::Vector2f(13.5f * _SIZE_, 11.25f * _SIZE_)));
}