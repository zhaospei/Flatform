#include "Map4.h"
Map4::Map4() {
	setLeverTurn();
	setButtom();
	setCoins();
	setDoor();
	setExitdoor();
	setGround();
	setSpikes();
	setStone();
	setEnemies();
	setPlayer();
	setMushroom();
	setBackGround();
	setAnimation();
	setBox();
}
Map4::~Map4() {
}
void Map4::Render(sf::RenderWindow* window) {
	RenderBackGround(window);
	RenderButtom(window);
	RenderCoins(window);
	RenderDoor(window);
	RenderGround(window);
	RenderExitdoor(window);
	RenderLeverTurn(window);
	RenderSpikes(window);
	RenderStone(window);
	RenderEnemies(window);
	RenderMushroom(window);
	RenderAnimation(window);
	RenderBox(window);
	RenderPlayer(window);
}
void Map4::Update(const float& deltaTime) {
	Map::Update(deltaTime);
	UpdateButtom(deltaTime);
	UpdateCoins(deltaTime);
	UpdateDoor(deltaTime);
	UpdateSpikes(deltaTime);
	UpdateStone(deltaTime);
	UpdateEnemies(deltaTime);
	UpdateMushroom(deltaTime);
	UpdateAnimation(deltaTime);
	UpdateLeverTurn(deltaTime);
	UpdateBox(deltaTime);
	UpdatePlayer(deltaTime);
}
void Map4::setBackGround() {
	AddBackGround("BackGround/background", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/bg_2", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
}
void Map4::setButtom() {
	buttoms.push_back(new Buttom(sf::Vector2f(1.5f * _SIZE_, 9.0f * _SIZE_ - 6.25f)));
}
void Map4::setCoins() {
	coins.push_back(new Coin(sf::Vector2f(604.0f, 177.0f)));
	coins.push_back(new Coin(sf::Vector2f(572.0f, 110.0f)));
	coins.push_back(new Coin(sf::Vector2f(533.0f, 71.0f)));
	coins.push_back(new Coin(sf::Vector2f(506.0f, 42.0f)));
	coins.push_back(new Coin(sf::Vector2f(474.0f, 71.0f)));
	coins.push_back(new Coin(sf::Vector2f(428.0f, 119.0f)));
	coins.push_back(new Coin(sf::Vector2f(392.0, 170.0f)));
	coins.push_back(new Coin(sf::Vector2f(370.0f, 224.0f)));
	coins.push_back(new Coin(sf::Vector2f(334.0f, 171.0f)));
	coins.push_back(new Coin(sf::Vector2f(261.0f, 84.0f)));
	coins.push_back(new Coin(sf::Vector2f(299.0f, 116.0f)));
	coins.push_back(new Coin(sf::Vector2f(218.0f, 69.0f)));
}
void Map4::setDoor() {
	door = new Door(sf::Vector2f(16.25f * _SIZE_ , 9.5 * _SIZE_));
}
void Map4::setExitdoor() {
	exitdoor = new ExitDoor(sf::Vector2f(18.0f * _SIZE_, 10.25f * _SIZE_));
}
void Map4::setGround() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map4[i][j] != 0)
				grounds[i][j].setGround("Ground/" + to_string(map4[i][j]), j * _SIZE_, i * _SIZE_, map4[i][j]);
		}
	}
}
void Map4::setMushroom() {
	mushrooms.push_back(new MushRoom(sf::Vector2f(12.5f * _SIZE_, 6.5f * _SIZE_)));
	mushrooms.push_back(new MushRoom(sf::Vector2f(7.5f * _SIZE_, 6.5f * _SIZE_)));
}
void Map4::setSpikes() {
	spikes.push_back(new Spikes(sf::Vector2f(8.5f * _SIZE_, 9.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(9.5f * _SIZE_, 9.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(10.5f * _SIZE_, 9.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(11.5f * _SIZE_, 9.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(9.5f * _SIZE_, 4.5 * _SIZE_), true));
	spikes.push_back(new Spikes(sf::Vector2f(10.5f * _SIZE_, 4.5 * _SIZE_), true));
}
void Map4::setStone() {
	stones.push_back(new Stone(sf::Vector2f(2.5f * _SIZE_, 1.5f * _SIZE_)));
}
void Map4::setAnimation() {
	managerAniamation.Add(new Animation("Animation/tiki_torch_props_strip_12", sf::Vector2u(12, 1), 0.1f), sf::Vector2f(14.5f * _SIZE_, 10.0f * _SIZE_ - 22.0f), sf::Vector2f(32.0f, 72.0f));
}
void Map4::setPlayer() {
	player = new Player(sf::Vector2f(14.5f * _SIZE_, 9.5f * _SIZE_), false);
}
void Map4::setEnemies() {
	enemies.push_back(new Enemies(2, sf::Vector2f(2.5f * _SIZE_, 8.5f * _SIZE_), sf::Vector2f(7.5f * _SIZE_, 8.5 * _SIZE_), sf::Vector2f(2.5f * _SIZE_, 8.5f * _SIZE_)));
} 
void Map4::setLeverTurn() {
	leverturn = new LeverTurn(sf::Vector2f(18.5f * _SIZE_, 1.5f * _SIZE_));
	leverturn->addWall(sf::Vector2f(3.5f * _SIZE_, 8.0f * _SIZE_), 2);
}
void Map4::setBox() {
	boxes.push_back(new Box(sf::Vector2f(0.8f * _SIZE_, 2.0f * _SIZE_ - 15.0f),true));
}


