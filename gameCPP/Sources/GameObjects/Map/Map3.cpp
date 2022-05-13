#include"Map3.h"
Map3::Map3() {
	setButtom();
	setCoins();
	setDoor();
	setExitdoor();
	setGround();
	setSpikes();
	setStone();
	setWater();
	setEnemies();
	setPlayer();
	setBackGround();
	setAnimation();
	setBox();
}
Map3::~Map3() {
}
void Map3::Render(sf::RenderWindow* window) {
	RenderBackGround(window);
	RenderButtom(window);
	RenderCoins(window);
	RenderDoor(window);
	RenderGround(window);
	RenderExitdoor(window);
	RenderSpikes(window);
	RenderStone(window);
	RenderWater(window);
	RenderEnemies(window);
	RenderPlayer(window);
	RenderAnimation(window);
}
void Map3::Update(const float& deltaTime) {
	Map::Update(deltaTime);
	UpdateButtom(deltaTime);
	UpdateCoins(deltaTime);
	UpdateDoor(deltaTime);
	UpdateSpikes(deltaTime);
	UpdateStone(deltaTime);
	UpdateEnemies(deltaTime);
	UpdatePlayer(deltaTime);
	UpdateAnimation(deltaTime);
	UpdateBox(deltaTime);
}
void Map3::setBackGround() {
	AddBackGround("BackGround/background", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/bg_1", sf::Vector2f(screenWidth, screenHeight), sf::Vector2f(0.0f, 0.0f));
	AddBackGround("BackGround/arrow_plate_left", sf::Vector2f(_SIZE_, _SIZE_), sf::Vector2f(6.0f * _SIZE_, 5.0f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(7.0f * _SIZE_, 6.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(19.0f * _SIZE_, 1.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(18.0f * _SIZE_, 9.5f * _SIZE_));
	AddBackGround("BackGround/grass_props", sf::Vector2f(_SIZE_, _SIZE_ * 0.5f), sf::Vector2f(19.0f * _SIZE_, 9.5f * _SIZE_));
}
void Map3::setButtom() {
	buttoms.push_back(new Buttom(sf::Vector2f(0.5f * _SIZE_, 7.0f * _SIZE_ - 6.25f)));
}
void Map3::setCoins() {
	coins.push_back(new Coin(sf::Vector2f(125.0f, 215.0f)));
	coins.push_back(new Coin(sf::Vector2f(372.0f, 301.0f)));
	coins.push_back(new Coin(sf::Vector2f(524.0f, 473.0f)));
	coins.push_back(new Coin(sf::Vector2f(576.0f, 324.0f)));
	coins.push_back(new Coin(sf::Vector2f(773.0f, 475.0f)));
	coins.push_back(new Coin(sf::Vector2f(874.0f, 279.0f)));
	coins.push_back(new Coin(sf::Vector2f(969.0f, 183.0f)));
	coins.push_back(new Coin(sf::Vector2f(614.0f, 74.0f)));
}
void Map3::setDoor() {
	door = new Door(sf::Vector2f(9.5f * _SIZE_, 2.5f * _SIZE_));
}
void Map3::setExitdoor() {
	exitdoor = new ExitDoor(sf::Vector2f(19.0f * _SIZE_ , 1.25f * _SIZE_));
}
void Map3::setGround() {	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map3[i][j] != 0 ) {
				grounds[i][j].setGround("Ground/" + to_string(map3[i][j]), j * _SIZE_, i * _SIZE_, map3[i][j]);
			}
		}
	}
}
void Map3::setSpikes() {
	spikes.push_back(new Spikes(sf::Vector2f(1.5f * _SIZE_, 3.5f * _SIZE_), false));
	spikes.push_back(new Spikes(sf::Vector2f(2.5f * _SIZE_, 3.5f * _SIZE_), false));
	spikes.push_back(new Spikes(sf::Vector2f(7.5f * _SIZE_, 0.5f * _SIZE_), false));
	spikes.push_back(new Spikes(sf::Vector2f(8.5f * _SIZE_, 0.5f * _SIZE_), false));
}
void Map3::setStone() {
	stones.push_back(new Stone(sf::Vector2f(2.5f * _SIZE_, 2.5f * _SIZE_)));
	stones.push_back(new Stone(sf::Vector2f(1.5f * _SIZE_, 9.5f * _SIZE_)));
}
void Map3::setWater() {
	waters.push_back(new Water(sf::Vector2f(4.5f * _SIZE_, 10.75f * _SIZE_)));
	waters.push_back(new Water(sf::Vector2f(5.5f * _SIZE_, 10.75f * _SIZE_)));
}
void Map3::setAnimation() {
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 0.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 1.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 2.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 3.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 4.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 5.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 6.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 7.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 8.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 9.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 9.5f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_));
	managerAniamation.Add(new Animation("Animation/waterfall_bottom_anim_strip_4", sf::Vector2u(4, 1), 0.1f), sf::Vector2f(4.5f * _SIZE_, 10.0f * _SIZE_), sf::Vector2f(_SIZE_, _SIZE_ * 0.5f));

}
void Map3::setPlayer() {
	player = new Player(sf::Vector2f(0.5f * _SIZE_, 9.5f * _SIZE_),true);
}
void Map3::setEnemies() {
	enemies.push_back(new Enemies(2, sf::Vector2f(3.5f * _SIZE_, 5.5f * _SIZE_), sf::Vector2f(6.5 * _SIZE_, 5.5f * _SIZE_), sf::Vector2f(6.5f * _SIZE_, 5.5f * _SIZE_)));
	enemies.push_back(new Enemies(1, sf::Vector2f(6.5f * _SIZE_, 9.75f * _SIZE_), sf::Vector2f(8.5 * _SIZE_, 9.75f * _SIZE_), sf::Vector2f(6.5f * _SIZE_, 9.75f * _SIZE_)));
}
void Map3::setBox() {
	boxes.push_back(new Box(sf::Vector2f(19.0f * _SIZE_, 10.0f * _SIZE_ - 15.0f), false));
}
