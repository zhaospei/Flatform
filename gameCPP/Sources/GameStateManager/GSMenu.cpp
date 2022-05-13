#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button = nullptr;
// Button
	button = new GameButton("play");
	button->setOnClick([]() 
	{
		GSM->ChangeState(StateTypes::_INPUT);
		HS->allowGetName = true;
	});
	button->setSize(sf::Vector2f(130.0f, 130.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(500.0f, 360.0f);
	m_Button.push_back(button);

	button = new GameButton("close");
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	m_Button.push_back(button);

	button = new GameButton("settings");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	m_Button.push_back(button);

	button = new GameButton("prize");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	m_Button.push_back(button);

	button = new GameButton("about");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	m_Button.push_back(button);

// Background
	sf::Texture* texture = DATA->getTexture("Background/background");
	sf::RectangleShape* rectangle = nullptr;
	rectangle = new RectangleShape();
	rectangle->setTexture(texture);
	rectangle->setSize(sf::Vector2f(screenWidth, screenHeight));
	rectangle->setPosition(sf::Vector2f(0.0f, 0.0f));
	m_Background.push_back(rectangle);

// Text 
	sf::Text* text = nullptr;

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setFillColor(sf::Color::Black);
	text->setString("@DucAnh DepZai@");
	text->setPosition(sf::Vector2f(290.0f, 200.0f));
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(40);
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setFillColor(sf::Color::Black);
	text->setString("Game C++");
	text->setPosition(sf::Vector2f(380.0f, 150.0f));
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(40);
	m_Text.push_back(text);
}

void GSMenu::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}
}

void GSMenu::Render(sf::RenderWindow* window)
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

