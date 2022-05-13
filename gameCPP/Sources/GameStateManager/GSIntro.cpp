#include "GSIntro.h"
#include "GameStateMachine.h"

GSIntro::GSIntro()
{
	m_currentTime = 0.0f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("Logo");
	m_Logo.setTexture(texture);
	m_Logo.setSize(sf::Vector2f(screenHeight, screenHeight));
	m_Logo.setOrigin(m_Logo.getSize() / 2.0f);
	m_Logo.setPosition(screenWidth / 2, screenHeight / 2);
	DATA->getTexture("Logo")->setRepeated(true);
}

void GSIntro::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 1.0f) {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->clear();
	window->draw(m_Logo);
}
