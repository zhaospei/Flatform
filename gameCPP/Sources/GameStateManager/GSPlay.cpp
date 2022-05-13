#include "GSPlay.h"

GSPlay::GSPlay()
{
	pickcoin = nullptr;
	list_Map.push_back(new Map1());
	list_Map.push_back(new Map2());
	list_Map.push_back(new Map3());
	list_Map.push_back(new Map4());
	list_Map.push_back(new Map5());
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	GameButton* button = nullptr;
// Button pause
	button = new GameButton("pause");
	button->setSize(sf::Vector2f(50.0f, 50.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(screenWidth - 100.0f, 40.0f);
	button->setOnClick([]() 
		{
			GSM->ChangeState(StateTypes::PAUSE);
		}
	);
	m_Button.push_back(button);
// Button close
	button = new GameButton("close");
	button->setSize(sf::Vector2f(50.0f, 50.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(screenWidth - 40, 40.0f);
	button->setOnClick([]()
		{
			WConnect->getWindow()->close();
		}
	);
	m_Button.push_back(button);

// Background
	sf::RectangleShape* rect = nullptr;
// background health
	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/health_hud_left"));
	rect->setSize(sf::Vector2f(40.0f, 40.0f));
	rect->setPosition(60.0f, 05.0f);
	m_Background.push_back(rect);

	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/health_hud_middle"));
	rect->setSize(sf::Vector2f(40.0f, 40.0f));
	rect->setPosition(100.0f, 05.0f);
	m_Background.push_back(rect);

	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/health_hud_right"));
	rect->setSize(sf::Vector2f(40.0f, 40.0f));
	rect->setPosition(140.0f, 05.0f);
	m_Background.push_back(rect);
// background coin
	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/coins_hud"));
	rect->setSize(sf::Vector2f(30.0f, 30.0f));
	rect->setPosition(67.0f, 50.0f);
	m_Background.push_back(rect);

	for (int i = 0; i < 3; i++) {
		health[i].setSize(sf::Vector2f(32.0f, 32.0f));
		health[i].setPosition(sf::Vector2f(40 * i + 65.0f, 8.0f));
	}

// Text
	sf::Text* text = nullptr;
// text coin
	text = new Text();
	text->setFillColor(sf::Color::White);
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(35);
	text->setPosition(sf::Vector2f(105.0f, 40.0f));
	pickcoin = text;
	m_Text.push_back(text);
}

void GSPlay::Update(float deltaTime)
{
	if (OPERATOR->resetMap == true) {
		Map* deleteMap = list_Map.front();
		int map = HS->map;
		HS->pickCoin -= HS->coinReset;
		HS->coinReset = 0;
		switch (map) {
		case 1:
			list_Map.front() = new Map1();
			break;
		case 2:
			list_Map.front() = new Map2();
			break;
		case 3:
			list_Map.front() = new Map3();
			break;
		case 4:
			list_Map.front() = new Map4();
			break;
		case 5:
			list_Map.front() = new Map5();
			break;
		}
		delete deleteMap;
	}
	HS->time += deltaTime;
	if ( list_Map.empty() || list_Map.front()->ExitGame() == 2 ) {
		HS->updateHighScore();
		GSM->ChangeState(StateTypes::END);
		return;
	}
	if (!list_Map.empty()) {
		list_Map.front()->Update(deltaTime);
		if (list_Map.front()->ExitGame() == 1) {
			list_Map.pop_front();
			HS->coinReset = 0;
			HS->map++;
		}
	}
	for (auto button : m_Button) {
		button->Update();
	}
	for (int i = 0; i < 3 ; i++) {
		if (i < HS->heart)
			health[i].setTexture(DATA->getTexture("BackGround/hearts_hud"));
		else
			health[i].setTexture(DATA->getTexture("BackGround/no_hearts_hud"));
	}
	pickcoin->setString(": " + to_string(HS->pickCoin));
	OPERATOR->resetMap = false;
}

void GSPlay::Render(sf::RenderWindow* window)
{
	if (list_Map.empty()) {
		return;
	}
	window->clear();
	if (!list_Map.empty()) {
		list_Map.front()->Render(window);
	}
	for (auto background : m_Background) {
		window->draw(*background);
	}
	for (auto button : m_Button) {
		window->draw(*button);
	}
	for (auto text : m_Text) {
		window->draw(*text);
	}
	for (int i = 0; i < 3; i++) {
		window->draw(health[i]);
	}
}
