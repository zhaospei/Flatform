#include "Map.h"
Map::Map()  {
	grounds = nullptr;
	player = nullptr;
	exitdoor = nullptr;
	door = nullptr;
	leverturn = nullptr;
	wingame = false;
	exitgame = false;
	width = 12, height = 20;
	grounds = new Ground * [width];
	for (int i = 0; i < width; i++) {
		grounds[i] = new Ground[height];
	}
}
Map::~Map()  {
	for (int i = 0; i < width; i++) {
		delete[] grounds[i];
	}
	if (grounds != nullptr) {
		delete grounds;
	}
	for (auto& _background : background) {
		delete _background;
	}
	for (auto& buttom : buttoms) {
		delete buttom;
	}
	for (auto& coin : coins) {
		delete coin;
	}
	for (auto& spike : spikes) {
		delete spike;
	}
	for (auto& stone : stones) {
		delete stone;
	}
	for (auto& enemi : enemies) {
		delete enemi;
	}
	for (auto& water : waters) {
		delete water;
	}
	for (auto& mushroom : mushrooms) {
		delete mushroom;
	}
	if (door != nullptr) {
		delete door;
	}
	if (exitdoor != nullptr) {
		delete exitdoor;
	}
	if (player != nullptr) {
		delete player;
	}
	if (leverturn != nullptr) {
		delete leverturn;
	}
}
void Map::Update(const float& deltaTime) {
	MapManager::Ground_and_Player(grounds, player, width, height);
	MapManager::Ground_and_Spikes(grounds, spikes, width, height);
	MapManager::Ground_and_Stone(grounds, stones, width, height);
	MapManager::Spikes_and_Stone(spikes, stones);
	MapManager::Water_and_Player(waters, player);
	MapManager::Coin_and_Player(coins, player);
	MapManager::Door_and_Player(door, player);
	MapManager::ExitDoor_and_Player(exitdoor, player, wingame);
	MapManager::Stone_and_Player(stones, player);
	MapManager::Water_and_Player(waters, player);
	MapManager::Enemies_and_Player(enemies, player);
	MapManager::MushRoom_and_Player(mushrooms, player);
	MapManager::LeverTurn_and_Player(leverturn, player);
	MapManager::LeverTurn_and_Stone(leverturn, stones);
	MapManager::LeverTurn_and_Enemies(leverturn, enemies, deltaTime);
	MapManager::Boxes_and_Player(boxes, player);
	MapManager::Stones(stones);
}
void Map::AddBackGround(const string& name, const Vector2f& size, const Vector2f& position) {
	sf::RectangleShape* rect = new RectangleShape();
	rect->setTexture(DATA->getTexture(name));
	rect->setSize(size);
	rect->setPosition(position);
	background.push_back(rect);
}
void Map::RenderBackGround(sf::RenderWindow* window) {
	for (int i = 0; i < int(background.size()) ; i++) {
		if (background[i]->getSize() == sf::Vector2f(screenWidth, screenHeight)) {
			window->draw(*background[i]);
		}
		else break;
	}
	for (auto& i : boxes) {
		window->draw(*i);
	}
	for (int i = 0; i < int(background.size()) ; i++) {
		if (background[i]->getSize() != sf::Vector2f(screenWidth, screenHeight)) {
			window->draw(*background[i]);
		}
	}
}
void Map::RenderGround(sf::RenderWindow* window) {
	for (int i = 0; i < width; i++) 
	{
		for (int j = 0; j < height; j++) 
		{
			grounds[i][j].Render(window);
		}
	}
}
void Map::UpdateButtom(const float& deltaTime) {
	door->setOpen(false);
	for (auto& buttom : buttoms) {
		buttom->setPressed(false);
	}
	MapManager::Buttom_and_Stone(buttoms, stones, deltaTime);
	MapManager::Buttom_and_Player(buttoms, player, deltaTime);
	door->setOpen(true);
	for (auto& buttom : buttoms) {
		buttom->Update();
		if (buttom->getPressed() == false) {
			door->setOpen(false);
		}
	}
}
void Map::RenderButtom(sf::RenderWindow* window) {
	for (auto& buttom : buttoms)
		buttom->Render(window);
}
void Map::UpdateCoins(const float& deltaTime) {
	for (int i = 0; i < (int)(coins.size()) ; i++) {
		if (coins[i]->delete_Coin) {
			delete coins[i];
			coins.erase(coins.begin() + i); 
			i--;
		}
		else {
			coins[i]->Update(deltaTime);
		}
	}
}
void Map::RenderCoins(sf::RenderWindow* window) {
	for (auto& coin : coins) {
		coin->Render(window);
	}
}
void Map::UpdateDoor(const float& deltaTime) {
	door->Update(deltaTime);
}
void Map::RenderDoor(sf::RenderWindow* window) {
	door->Render(window);
}
void Map::RenderExitdoor(sf::RenderWindow* window) {
	exitdoor->Render(window);
}
void Map::UpdateSpikes(const float& deltaTime) {
	for (auto& spike : spikes) {
		if (spike->checkPlayer(player)) {
			player->end = true;
		}
		spike->Update(deltaTime);
	}
}
void Map::RenderSpikes(sf::RenderWindow* window) {
	for (auto& spike : spikes) {
		spike->Render(window);
	}
}
void Map::UpdateStone(const float& deltaTime) {
	for (auto& stone : stones) {
		stone->Update(deltaTime);
	}
}
void Map::RenderStone(sf::RenderWindow* window) {
	for (auto& stone : stones) {
		stone->Render(window);
	}
}
void Map::RenderWater(sf::RenderWindow* window) {
	for (auto& water : waters) {
		water->Render(window);
	}
}
void Map::UpdateAnimation(const float& deltaTime) {
	managerAniamation.Update(deltaTime);
}
void Map::RenderAnimation(sf::RenderWindow* window) {

	managerAniamation.Render(window);
}	
void Map::UpdatePlayer(const float& deltaTime) {
	if (player->deletePlayer == true )
	{
		if (player->wingame) exitgame = 1;
		else exitgame = 2;
		return;
	}
	player->Update(deltaTime);
}
void Map::RenderPlayer(sf::RenderWindow* window) {
	if( player->deletePlayer == false )
		player->Render(window);
}
void Map::UpdateEnemies(const float& deltaTime) {
	for (int i = 0; i < (int)(enemies.size()) ; i++) {
		if (enemies[i]->delete_Bot) {
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			i--;
		}
		else {
			enemies[i]->Update(deltaTime);
		}
	}
}
void Map::RenderEnemies(sf::RenderWindow* window) {
	for (auto& enemi : enemies) {
		if (enemi->delete_Bot == false)
		{
			enemi->Render(window);
		}
	}
}
void Map::UpdateMushroom(const float& deltaTime) {
	for (auto& mushroom : mushrooms) {
		mushroom->Update(deltaTime);
	}
}
void Map::RenderMushroom(sf::RenderWindow* window) {
	for (auto& mushroom : mushrooms) {
		mushroom->Render(window);
	}
}
void Map::UpdateLeverTurn(const float& deltaTime) {
	leverturn->update(deltaTime);
}
void Map::RenderLeverTurn(sf::RenderWindow* window) {
	leverturn->Render(window);
}
void Map::UpdateBox(float deltaTime) {
	for (auto& box : boxes) {
		box->Update(deltaTime);
	}
}
void Map::RenderBox(sf::RenderWindow* window) {
	for (auto& box : boxes) {
		box->Render(window);
	}
}
int Map::ExitGame() {
	return exitgame;
}
