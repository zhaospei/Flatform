#include "GameButton.h"

GameButton::GameButton() {
	m_btnClickFunc = nullptr;
	m_isHandling = false;
}

GameButton::GameButton(const string& name) {
	m_btnClickFunc = nullptr;
	m_isHandling = false;
	setTexture(DATA->getTexture("GState/" + name));
	setSize(sf::Vector2f(100, 100));
}

void GameButton::Update() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && OPERATOR->allowClickMouse() == true) {
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window) {
	window->draw(*this);
}

void GameButton::HandleTouchEvent() {
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
	{
		m_btnClickFunc();
		m_isHandling = true;
		OPERATOR->setClick();
	}
}

bool GameButton::isHandle() {
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)()) {
	m_btnClickFunc = Func;
}
