#pragma once
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"
#include "../GameManager/OperationsManager.h"

#include<Windows.h>
#include<shellapi.h>

class GameButton :public sf::RectangleShape{
public:
	GameButton();
	GameButton(const string& name);

	void Update();
	void Render(sf::RenderWindow* window);

	void HandleTouchEvent();
	bool isHandle();

	void setOnClick(void (*Func)());
private:
	void (*m_btnClickFunc)();
	bool m_isHandling;
};