#include "Application.h"
#include "GameStateManager/GameStateBase.h"
#include "GameStateManager/GSInput.h"

void Application::Run() 
{
	Init();
	sf::Clock clock;
	float deltaTime = 0.0f;
	while (WConnect->getWindow()->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (WConnect->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				WConnect->getWindow()->close();
			}
			if (event.type == sf::Event::TextEntered && HS->allowGetName )
			{
				if (event.text.unicode < 128)
				{
					HS->setNamePlayer(event.text.unicode);
				}
			}
		}
		Update(deltaTime);
		Render();
	}
}

void Application::Init() 
{
	WConnect->setWindow(new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close));
	WConnect->getWindow()->setFramerateLimit(60);
	WConnect->getWindow()->setVerticalSyncEnabled(false);
	GSM->ChangeState(StateTypes::INTRO);
	music = DATA->getMusic("ES_Ninja-Training-Camp-Christoffer-Moe-Ditlevsen");
	music->setLoop(true);
	music->play();
}

void Application::Update(const float& deltaTime) 
{
	OPERATOR->update(deltaTime);
	if (GSM->NeedToChangeState())
	{
		GSM->PerformStateChange();
	}
	GSM->currentState()->Update(deltaTime);
	if (DATA->getAllowMusic() == false) {
		music->setVolume(0.0f);
	}
	else music->setVolume(30.0f);
}

void Application::Render() 
{
	GSM->currentState()->Render(WConnect->getWindow());
	WConnect->getWindow()->display();
}