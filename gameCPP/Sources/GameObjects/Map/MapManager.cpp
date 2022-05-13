#include "MapManager.h"

void MapManager::Buttom_and_Stone(list<Buttom*>& buttoms, list<Stone*>& stones, const float& deltaTime) {
	for (auto& buttom : buttoms) {
		for (auto& stone : stones) {
			int Check = buttom->checkCollider(stone->getCollider(), deltaTime);
			if (Check == collider::top || Check == collider::_top) {
				stone->can_Drop = false;
			}
		}
	}
}
void MapManager::Buttom_and_Player(list<Buttom*>& buttoms, Player* player, const float& deltaTime) {
	if (player == nullptr) {
		return;
	}
	for (auto& buttom : buttoms) {
		int Check = buttom->checkCollider(player->getCollider(), deltaTime);
		if (Check == collider::top || Check == collider::_top) {
			player->canJump = true;
		}
	}
}
void MapManager::Ground_and_Player(Ground** ground, Player* player, int& width, int& height) {
	if (player == nullptr) {
		return;
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (ground[i][j].getCollider() == nullptr) continue;
			else { 
				int Check = ground[i][j].getCollider()->checkCollision(player->getCollider(), 1.0f);
				if (Check == collider::top || Check == collider::_top) {
					player->canJump = true;
				}
				if (Check == collider::down || Check == collider::_down) {
					player->velocity.y *= 0.8f;
				}
			}
		}
	}
}
void MapManager::Ground_and_Stone(Ground** ground, list<Stone*>& stones, int& width, int& height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (ground[i][j].getCollider() == nullptr) continue;
			else {
				for (auto& stone : stones) {
					int Check = ground[i][j].getCollider()->checkCollision(stone->getCollider(), 1.0f);
					if (Check == collider::top || Check == collider::_top) {
						stone->can_Drop = false;
					}
				}
			}
		}
	}
}
void MapManager::Ground_and_Spikes(Ground** ground, list<Spikes*>& spikes, int& width, int& height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (ground[i][j].getCollider() == nullptr) continue;
			else {
				for (auto& spike : spikes) {
					int Check = ground[i][j].getCollider()->checkCollision(spike->getCollider(), 1.0f);
					if (Check == collider::top || Check == collider::_top) {
						spike->can_Drop = false;
						spike->touch_Gound = true;
					}
				}
			}
		}
	}
}
void MapManager::Water_and_Player(list<Water*>& waters, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& water : waters) {
		if (water->getCollider()->checkCollision(player->getCollider()) != 0) {
			player->end = true;
		}
	}
}
void MapManager::Spikes_and_Stone(list<Spikes*>& spikes, list<Stone*>& stones) {
	for (auto& spike : spikes) {
		for (auto& stone : stones) {
			int Check = spike->getCollider()->checkCollision(stone->getCollider(), 1.0f);
			if (Check == collider::top || Check == collider::_top) {
				stone->can_Drop = false;
			}
		}
	}
}
void MapManager::Coin_and_Player(vector<Coin*>& coins, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& coin : coins) {
		if (coin->getCollider()->checkCollision(player->getCollider())) {
			coin->eat_Coin++;
		}
	}
}
void MapManager::Door_and_Player(Door* door, Player* player) {
	if (door == nullptr || player == nullptr) {
		return;
	}
	if (door->checkOpen() == false) {
		door->getCollider()->checkCollision(player->getCollider(), 1.0f);
	}
}
void MapManager::ExitDoor_and_Player(ExitDoor* exitdoor, Player* player,bool& wingame) {
	if (exitdoor->getCollider()->checkCollision(player->getCollider())) {
		player->setPosition(exitdoor->getPosition());
		player->wingame = true;
	}
}
void MapManager::Stone_and_Player(list<Stone*>& stones, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& stone : stones) {
		int Check = stone->getCollider()->checkCollision(player->getCollider(), 0.5f);
		if (Check == collider::_top || Check == collider::top) {
			player->canJump = true;
		}
		if (Check == collider::left || Check == collider::_left || Check == collider::right || Check == collider::_right) {
			player->pushStone = true;
		}
	}
}
void MapManager::Enemies_and_Player(vector<Enemies*>& enemies, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& enemi : enemies) {
		if (player->_Attack.Check && enemi->check_Die == 0) {
			int Check = enemi->getCollider()->checkCollision(player->getColliderAttack());
			if (Check != 0 && Check != collider::_top && Check != collider::_down ) {
				enemi->check_Die++;
			}
		}
		else if (player->end == false && enemi->check_Die == 0 && enemi->getCollider()->checkCollision(player->getCollider()) == collider::top) {
			enemi->check_Die++;
		}
		else if (enemi->check_Die == 0 ) {
			int Check = enemi->getCollider()->checkCollision(player->getCollider());
			if (Check == collider::right || Check == collider::left) {
				player->end = true;
			}
		}
	}
}
void MapManager::MushRoom_and_Player(list<MushRoom*>& mushrooms, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& mushroom : mushrooms) {
		int Check = mushroom->getCollider()->checkCollision(player->getCollider(), 1.0f);
		if ( Check != 0 && Check != collider::down && Check != collider::_down) {
			player->velocity.y = -sqrt(2.0f * 981.0f * player->jumpHeight * 1.7f);
			player->canJump = false;
		}
	}
}
void MapManager::LeverTurn_and_Player(LeverTurn* leverturn, Player* player) {
	if (player == nullptr || leverturn == nullptr)
		return;
	if (player->_Attack.Check == true && leverturn->startReStatus() )
	{
		if (leverturn->colliderSwitch->checkCollision(player->_Attack.collider ) != 0 )
		{
			leverturn->status = !(leverturn->status);
			leverturn->timeSetStatus = 0.5f;
		}
	}
	if (leverturn->status == false ) // Off
	{
		for (auto &i : leverturn->wall)
		{
			int Check = i.first.second->checkCollision(player->getCollider(), 1.0f);
			if ( Check == collider::top || Check == collider::_top)
			{
				player->canJump = true;
			}
		}
	}
}
void MapManager::LeverTurn_and_Stone(LeverTurn* leverturn, list<Stone*>& stones) {
	if (leverturn == nullptr) {
		return;
	}
	for (auto& stone : stones)
	{
		for (auto i : leverturn->wall)
		{
			if (leverturn->status == false) 
			{
				int Check = i.first.second->checkCollision(stone->getCollider(), 1.0f);
				if (Check == collider::top || Check == collider::_top) {
					stone->can_Drop = false;
				}
			}
		}
	}
}
void MapManager::LeverTurn_and_Enemies(LeverTurn* leverturn, vector<Enemies*>& enemies,const float& deltaTime) {
	if (leverturn == nullptr) {
		return;
	}
	for (auto& enemie : enemies) {
		for (auto& i : leverturn->wall) {
			if (i.second == 1) {
				if (abs(enemie->getPosition().y - i.first.first->getPosition().y) <= 100.0f) {
					if (leverturn->status == true) {
						float x1 = enemie->getPosition().x;
						float x2 = i.first.first->getPosition().x;
						if (x1 + enemie->getSize().x / 2.0f <= x2) {
							float x = x1 + deltaTime * enemie->speed * enemie->_Move;
							if (x + enemie->getSize().x / 2.0f > x2) {
								enemie->_Move = (-enemie->_Move);
							}
						}
						else if (x1 - enemie->getSize().x / 2.0f >= x2) {
							float x = x1 + deltaTime * enemie->speed * enemie->_Move;
							if (x - enemie->getSize().x / 2.0f < x2) {
								enemie->_Move = (-enemie->_Move);
							}
						}
					}
				}	
			}
			else if( i.second == 2 ) {
				if (abs(enemie->getPosition().y - i.first.first->getPosition().y) <= 100.0f) {
					if (leverturn->status == false) {
						float x1 = enemie->getPosition().x;
						float x2 = i.first.first->getPosition().x + 25.0f;
						if (x1 + enemie->getSize().x / 2.0f <= x2) {
							float x = x1 + deltaTime * enemie->speed * enemie->_Move;
							if (x + enemie->getSize().x / 2.0f > x2) {
								enemie->_Move = (-enemie->_Move);
							}
						}
						else if (x1 - enemie->getSize().x / 2.0f >= x2) {
							float x = x1 + deltaTime * enemie->speed * enemie->_Move;
							if (x - enemie->getSize().x / 2.0f < x2) {
								enemie->_Move = (-enemie->_Move);
							}
						}
					}
				}
			}
		}
	}
}
void MapManager::Stones(list<Stone*>& stones) {
	for (auto& stone1 : stones) {
		for (auto& stone2 : stones) {
			if (stone1 == stone2) {
				continue;
			}
			int Check = stone1->getCollider()->checkCollision(stone2->getCollider());
			int Check1 = stone2->getCollider()->checkCollision(stone1->getCollider());
			if (Check == collider::top || Check == collider::_top ) {
				stone2->body.setPosition(stone1->body.getPosition() - sf::Vector2f(0.0f, stone1->body.getSize().y));
				stone2->can_Drop = false;
			}
			else if ( Check1 == collider::top || Check1 == collider::_top) {
				stone1->body.setPosition(stone2->body.getPosition() - sf::Vector2f(0.0f, stone1->body.getSize().y));
				stone1->can_Drop = false;
			}
			else {
				stone2->getCollider()->checkCollision(stone1->getCollider(), 0.6f);
				stone1->getCollider()->checkCollision(stone2->getCollider(), 0.6f);
			}
		}
	}
}
void MapManager::Boxes_and_Player(list<Box*>& boxes, Player* player) {
	if (player == nullptr) {
		return;
	}
	for (auto& box : boxes) {
		if (player->_Attack.Check == true)
		{
			if (box->loot == 0 && player->_Attack.collider->checkCollision(box->collider)) {
				box->loot++;
			}
		}
	}
}