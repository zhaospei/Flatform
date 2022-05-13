#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button = nullptr;
// Menu Button
	button = new GameButton("exit");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setPosition(screenWidth / 2 + screenWidth / 12 + 50.0f, screenHeight - screenHeight / 8 - 70.0f);
	button->setOnClick([]() {
		WConnect->getWindow()->close();
	});
	m_Button.push_back(button);

// Replay Button
	button = new GameButton("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setPosition(screenWidth / 2 - screenWidth / 12 - 50.0f, screenHeight - screenHeight / 8 - 70.0f);
	button->setOnClick([]() {
		HS->Init();
		GSM->PopState();
		GSM->PopState();
		GSM->PopState();
		});
	m_Button.push_back(button);

// Background
	sf::RectangleShape* rect = nullptr;
	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/background"));
	rect->setPosition(sf::Vector2f(0.0f, 0.0f));
	rect->setSize(sf::Vector2f(screenWidth, screenHeight));
	m_Background.push_back(rect);

	sf::Text* text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(40);
	text->setString("END GAME!");
	text->setFillColor(sf::Color::Black);
	text->setPosition(screenWidth / 2 - 130.0f, screenHeight / 4);
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(30);
	text->setString("Go Home");
	text->setFillColor(sf::Color::Black);
	text->setPosition(290.0f, screenHeight - screenHeight / 8 - 20.0f);
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(30);
	text->setString("Quit Game!");
	text->setFillColor(sf::Color::Black);
	text->setPosition(550.0f, screenHeight - screenHeight / 8 - 20.0f);
	m_Text.push_back(text);
}

void GSEnd::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->clear();
	for (auto background : m_Background) {
		window->draw(*background);
	}
	for (auto button : m_Button) {
		window->draw(*button);
	}
	for (auto text : m_Text) {
		window->draw(*text);
	}
}
