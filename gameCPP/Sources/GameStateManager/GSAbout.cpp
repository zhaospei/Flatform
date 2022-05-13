#include "GSAbout.h"

GSAbout::GSAbout()
{
	click.setSize(sf::Vector2f(400.0f, 25.0f));
	click.setPosition(sf::Vector2f(581.0f, 508.0f));
	link = nullptr;
}

GSAbout::~GSAbout()
{

}

void GSAbout::Exit()
{

}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button = nullptr;
// Button
	button = new GameButton("close_2");
	button->setOrigin(button->getSize() / 2.0f);
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_Button.push_back(button);

// Background
	RectangleShape* background = nullptr;

	background = new RectangleShape();
	background->setTexture(DATA->getTexture("BackGround/background"));
	background->setSize(Vector2f(screenWidth, screenHeight));
	background->setPosition(Vector2f(0.0f, 0.0f));
	m_Background.push_back(background);

	background = new RectangleShape();
	background->setTexture(DATA->getTexture("BackGround/HuongDan"));
	background->setSize(Vector2f(992.0f, 251.0f));
	background->setPosition(Vector2f(0.0f, 100.0f));
	m_Background.push_back(background);
// Text
	sf::Font* font = DATA->getFont("VNCOOP");
	sf::Text* text = new Text();
	text->setFont(*font);
	text->setString("FB.com/NgDucAnh2k2/");
	text->setFillColor(sf::Color::Black);
	text->setPosition(sf::Vector2f(580.0f, 500.0f));
	m_Text.push_back(text);
	link = text;
}

void GSAbout::Update(float deltaTime)
{
	if (time > 0.0f) {
		time -= deltaTime;
	}
	for (auto button : m_Button) {
		button->Update();
	}
	if (click.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*WConnect->getWindow()))))
	{
		link->setFillColor(sf::Color::Red);
		if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) && time <= 0.0f ) {
			ShellExecute(0, 0, L"https://www.facebook.com/NgDucAnh2k2/", 0, 0, SW_SHOW);
		}
	}
	else {
		link->setFillColor(sf::Color::Black);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
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
