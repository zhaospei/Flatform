#pragma once

#include"Collider.h"
#include"../GameConfig.h"
#include<SFML/Graphics.hpp>
#include<vector>
using namespace std;

class LeverTurn
{
public:
	// 0 is close. 1 is open
	bool status;
	float timeSetStatus;
	sf::RectangleShape _switch;
	Collider* colliderSwitch;
	LeverTurn(sf::Vector2f position) {
		_switch.setSize(sf::Vector2f(_SIZE_, _SIZE_));
		_switch.setOrigin(_switch.getSize() / 2.0f);
		_switch.setPosition(position);
		status = false;
		timeSetStatus = 0.0f;
		colliderSwitch = new Collider(_switch);
	}
	~LeverTurn() {
		if (colliderSwitch != nullptr) {
			delete colliderSwitch;
		}
		for (auto& i : wall) {
			if (i.first.first != nullptr) delete i.first.first;
			if (i.first.second != nullptr) delete i.first.second;
		}
	}
public :
	vector < pair<pair<sf::RectangleShape*, Collider*>, int>>wall;
	void addWall(sf::Vector2f position,int type) {	
		sf::RectangleShape* rect = new sf::RectangleShape();
		Collider* collider = new Collider(rect);
		wall.push_back(make_pair(make_pair(rect, collider), type));
		if (type == 1) {
			rect->setSize(sf::Vector2f(2 * _SIZE_, _SIZE_));
		}
		else {
			rect->setSize(sf::Vector2f(_SIZE_, 2 * _SIZE_));
		}
		rect->setOrigin(rect->getSize() / 2.0f);
		rect->setPosition(position);
	}
public:
	void Render(sf::RenderWindow* window) {
		window->draw(_switch);
		for (auto& i : wall) {
			window->draw(*i.first.first);
		}
	}
	void update(float deltaTime) {
		if (status == false)
			_switch.setTexture(DATA->getTexture("LeverTurn/lever_turned_left"));
		else
			_switch.setTexture(DATA->getTexture("LeverTurn/lever_turned_right"));
		if (timeSetStatus > 0.0f) {
			timeSetStatus -= deltaTime;
		}
		for (auto& i : wall) {
			if (status) // on 
				i.first.first->setTexture(DATA->getTexture("LeverTurn/wood_slab" + to_string(i.second) + "_on"));
			else {
				// off 
				i.first.first->setTexture(DATA->getTexture("LeverTurn/wood_slab" + to_string(i.second) + "_off"));
			}	
		}
	}
	bool startReStatus() {
		return timeSetStatus <= 0.0f;
	}
};

