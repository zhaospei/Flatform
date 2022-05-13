#include "GSInput.h"

GSInput::GSInput()
{
}

GSInput::~GSInput()
{
}

void GSInput::Exit()
{
}

void GSInput::Pause()
{
}

void GSInput::Resume()
{
}

void GSInput::Init()
{
// Button
	GameButton* button = nullptr;

	button = new GameButton("ok");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		if ( HS->namePlayer.size() != 0) {
			HS->allowGetName = false;
			HS->map++;
			GSM->ChangeState(StateTypes::PLAY);
		}
	});
	m_Button.push_back(button);

	button = new GameButton("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() 
		{
		GSM->PopState(); 
		HS->allowGetName = false;
		HS->Init();
		});
	m_Button.push_back(button);

// Background
	sf::RectangleShape* rectangle = nullptr;
	rectangle = new RectangleShape();
	rectangle->setTexture(DATA->getTexture("Background/background"));
	rectangle->setSize(sf::Vector2f(screenWidth, screenHeight));
	rectangle->setPosition(sf::Vector2f(0.0f, 0.0f));
	m_Background.push_back(rectangle);
	
// Text
	sf::Text* text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(30);
	text->setString("Nhap Ten Nguoi Choi.");
	text->setPosition(sf::Vector2f(310.0f, 200.0f));
	text->setStyle(sf::Text::Style::Bold);
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(37);
	m_Text.push_back(text);
	namePlayer = text;
}

void GSInput::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}
	if (HS->namePlayer.empty()) {
		namePlayer->setString(". . . . . . .");
		namePlayer->setFillColor(sf::Color::White);
		namePlayer->setStyle(sf::Text::Style::Bold);
		namePlayer->setPosition(400.0f, 300.0f);
	}
	else {
		namePlayer->setString(HS->namePlayer);
		namePlayer->setFillColor(sf::Color::Black);
		namePlayer->setStyle(sf::Text::Style::Bold);
		namePlayer->setPosition(480.0f - (HS->namePlayer.size() * namePlayer->getCharacterSize() / 3.0f), 300.0f);
	}
}

void GSInput::Render(sf::RenderWindow* window)
{
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
