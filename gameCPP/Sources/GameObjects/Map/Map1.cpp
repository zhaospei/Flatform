#include"Map1.h"
Map1::Map1() {
	setBackGround();
	setButtom();
	setCoins();
	setDoor();
	setExitdoor();
	setGround();
	setSpikes();
	setStone();
	setAnimation();
	setPlayer();
	setEnemies();
}
Map1::~Map1() {

}
void Map1::Update(const float& deltaTime) {
	Map::Update(deltaTime);
	UpdateButtom(deltaTime);
	UpdateCoins(deltaTime);
	UpdateDoor(deltaTime);
	UpdateSpikes(deltaTime);
	UpdateStone(deltaTime);
	UpdateAnimation(deltaTime);
	UpdatePlayer(deltaTime);
	UpdateEnemies(deltaTime);
}
void Map1::Render(sf::RenderWindow* window) {
	RenderBackGround(window);
	RenderButtom(window);
	RenderCoins(window);
	RenderDoor(window);
	RenderExitdoor(window);
	RenderGround(window);
	RenderSpikes(window);
	RenderStone(window);
	RenderAnimation(window);
	RenderPlayer(window);
	RenderEnemies(window);
}
void Map1::setBackGround() {
	AddBackGround("BackGround/background", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/bg_2", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/arrow_plate_left", sf::Vector2f(_SIZE_, _SIZE_), sf::Vector2f(4 * _SIZE_, 10 * _SIZE_));
	AddBackGround("BackGround/arrow_plate_right", sf::Vector2f(_SIZE_, _SIZE_), sf::Vector2f(6 * _SIZE_, 0 * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(12 * _SIZE_, 10.5 * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(1 * _SIZE_, 7.5 * _SIZE_));
	AddBackGround("BackGround/drygrass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(1 * _SIZE_, 10.5 * _SIZE_));
	AddBackGround("BackGround/drygrass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(15 * _SIZE_, 9.5 * _SIZE_));
	AddBackGround("BackGround/bigflowers_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(10 * _SIZE_, 3.5 * _SIZE_));
	AddBackGround("BackGround/drygrass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5), sf::Vector2f(17 * _SIZE_ - 10.0f, 9.5 * _SIZE_));
}
void Map1::setGround() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map1[i][j] != 0)
				grounds[i][j].setGround("Ground/" + to_string(map1[i][j]), j * _SIZE_, i * _SIZE_, map1[i][j]);
		}
	}
}
void Map1::setButtom() {
	buttoms.push_back(new Buttom(sf::Vector2f(17 * _SIZE_, 4 * _SIZE_ - 6.25f)));
}
void Map1::setCoins() {
	coins.push_back(new Coin(sf::Vector2f(1.5f * _SIZE_, 7.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(4.5f * _SIZE_, 5.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(148.0f, 192.0f)));
	coins.push_back(new Coin(sf::Vector2f(1.5f * _SIZE_, 2.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(151.0f, 53.0f)));
	coins.push_back(new Coin(sf::Vector2f(8.7f * _SIZE_, 2.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(13.5f * _SIZE_, 3.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(14.3f * _SIZE_, 3.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(15.1f * _SIZE_, 3.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(15.9f * _SIZE_, 3.5f * _SIZE_)));
	coins.push_back(new Coin(sf::Vector2f(848.0f, 143.0f)));
	coins.push_back(new Coin(sf::Vector2f(825.0f, 118.0f)));
	coins.push_back(new Coin(sf::Vector2f(871.0f, 118.0f)));
	coins.push_back(new Coin(sf::Vector2f(802.0f, 93.0f)));
	coins.push_back(new Coin(sf::Vector2f(894.0f, 93.0f)));
	coins.push_back(new Coin(sf::Vector2f(848.0f, 93.0f)));
	coins.push_back(new Coin(sf::Vector2f(848.0f, 59.0f)));
	coins.push_back(new Coin(sf::Vector2f(848.0f, 29.0f)));
}
void Map1::setDoor() {
	door = new Door(sf::Vector2f(15 * _SIZE_ - 5, 7 * _SIZE_ + _SIZE_ * 1.5));
}
void Map1::setExitdoor() {
	exitdoor = new ExitDoor(sf::Vector2f(18 * _SIZE_, 10 * _SIZE_ - 0.75 * _SIZE_));
}
void Map1::setSpikes() {
	spikes.push_back(new Spikes(sf::Vector2f(8.5 * _SIZE_, 7.5 * _SIZE_),false));
	spikes.push_back(new Spikes(sf::Vector2f(9.5 * _SIZE_, 7.5 * _SIZE_),false));
	spikes.push_back(new Spikes(sf::Vector2f(10.5 * _SIZE_, 7.5 * _SIZE_),false));
}
void Map1::setStone() {
	stones.push_back(new Stone(sf::Vector2f(12.0 * _SIZE_ + 10.f, 3.5 * _SIZE_)));
}
void Map1::setAnimation() {
	managerAniamation.Add(new Animation("Animation/tiki_torch_props_strip_12", sf::Vector2u(12, 1), 0.1f), sf::Vector2f(340.0f, 478.0f), sf::Vector2f(32.0f, 72.0f));
}
void Map1::setPlayer() {
	player = new Player(sf::Vector2f(11.5 * _SIZE_, 430.0f),false);
}
void Map1::setEnemies() {
	enemies.push_back(new Enemies(1, sf::Vector2f(8.5 * _SIZE_, 3 * _SIZE_ - 0.25 * _SIZE_), sf::Vector2f(9.5 * _SIZE_, 3 * _SIZE_ - 0.25 * _SIZE_), sf::Vector2f(8.5 * _SIZE_, 3 * _SIZE_ - 0.25 * _SIZE_)));
	enemies.push_back(new Enemies(1, sf::Vector2f(1.8 * _SIZE_, 11 * _SIZE_ - 0.25 * _SIZE_), sf::Vector2f(3.5 * _SIZE_, 11 * _SIZE_ - 0.25 * _SIZE_), sf::Vector2f(1.8 * _SIZE_, 11 * _SIZE_ - 0.25 * _SIZE_)));
}