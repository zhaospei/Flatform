#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
	HS->readFile();
	arrHightScore = &HS->listHightSroce[0];
}

GSHighScore::~GSHighScore()
{
	
}

void GSHighScore::Exit()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Init()
{
	GameButton* button;
// Button
	button = new GameButton("close_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_Button.push_back(button);

// Background
	sf::RectangleShape* rectangle = nullptr;
	rectangle = new RectangleShape();
	rectangle->setTexture(DATA->getTexture("Background/background"));
	rectangle->setSize(sf::Vector2f(screenWidth, screenHeight));
	rectangle->setPosition(sf::Vector2f(0.0f, 0.0f));
	m_Background.push_back(rectangle);

	rectangle = new RectangleShape();
	rectangle->setTexture(DATA->getTexture("Background/coins_hud"));
	rectangle->setSize(sf::Vector2f(40.0f, 40.0f));
	rectangle->setPosition(sf::Vector2f(500.0f, 100.0f));
	m_Background.push_back(rectangle);

	rectangle = new RectangleShape();
	rectangle->setTexture(DATA->getTexture("Background/coins_hud"));
	rectangle->setSize(sf::Vector2f(40.0f, 40.0f));
	rectangle->setPosition(sf::Vector2f(450.0f, 100.0f));
	m_Background.push_back(rectangle);

	rectangle = new RectangleShape();
	rectangle->setTexture(DATA->getTexture("Background/coins_hud"));
	rectangle->setSize(sf::Vector2f(40.0f, 40.0f));
	rectangle->setPosition(sf::Vector2f(550.0f, 100.0f));
	m_Background.push_back(rectangle);
	
// Font
	sf::Font* font = DATA->getFont("VNCOOP");
	sf::Text* text = new Text();
	text->setFont(*font);
	text->setCharacterSize(30);
	text->setString("Name Player");
	text->setFillColor(sf::Color::Black);
	text->setPosition(100.0f, 100.0f);
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*font);
	text->setCharacterSize(30);
	text->setString("Time");
	text->setFillColor(sf::Color::Black);
	text->setPosition(750.0f, 100.0f);
	m_Text.push_back(text);

	for (int i = 1; i <= 5; i++) {
		text = new Text();
		text->setFont(*font);
		text->setCharacterSize(30);
		text->setString(to_string(i));
		text->setFillColor(sf::Color::Black);
		text->setPosition(20.0f, 100.0f + i * 70.0f);
		m_Text.push_back(text);
	}
	for (int i = 0; i < 5; i++) {

	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			textHightScore[i][j].setFillColor(sf::Color::Black);
			textHightScore[i][j].setCharacterSize(30);
			textHightScore[i][j].setFont(*DATA->getFont("VNCOOP"));
		}
		textHightScore[i][0].setPosition(130.0f, 100.0f + (i + 1) * 70.0f);
		textHightScore[i][1].setPosition(470.0f, 100.0f + (i + 1) * 70.0f);
		textHightScore[i][2].setPosition(750.0f, 100.0f + (i + 1) * 70.0f);

		textHightScore[i][0].setString(arrHightScore[i].name);
		textHightScore[i][1].setString(to_string(arrHightScore[i].pickCoin));
		textHightScore[i][2].setString(to_string(arrHightScore[i].timeEnd) + "s");
	}
}

void GSHighScore::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}
}

void GSHighScore::Render(sf::RenderWindow* window)
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
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			window->draw(textHightScore[i][j]);
		}
	}
}
