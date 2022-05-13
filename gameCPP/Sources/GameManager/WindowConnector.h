#pragma once
#include "SFML/Graphics.hpp"
#include "../GameManager/Singleton.h"

#define WConnect WindowConnector::GetInstance()

class WindowConnector :public CSingleton<WindowConnector>{
public:
	WindowConnector()
	{
		m_Window = nullptr;
	}

	~WindowConnector()
	{
		if (m_Window != nullptr)
		{
			delete m_Window;
		}
	}

	void setWindow(sf::RenderWindow* window)
	{
		m_Window = window;
	}

	sf::RenderWindow* getWindow()
	{
		return m_Window;
	}

private:
	sf::RenderWindow* m_Window;
};