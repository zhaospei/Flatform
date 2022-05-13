#include "GSPause.h"

GSPause::GSPause()
{
}

GSPause::~GSPause()
{
}

void GSPause::Exit()
{
}

void GSPause::Pause()
{
}

void GSPause::Resume()
{
}

void GSPause::Init()
{
	GameButton* button = nullptr;
// Button play
	button = new GameButton("play");
	button->setSize(sf::Vector2f(50.0f, 50.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(screenWidth - 100.0f, 40.0f);
	button->setOnClick([]()
		{
			GSM->PopState();
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
// Button sound
	button = new GameButton();
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(600.0f, 200.0f);
	button->setOnClick([]()
		{
			DATA->setAllowSound(!DATA->getAllowSound());
		}
	);
	m_Button.push_back(button);
	sound = button;
// Button music 
	button = new GameButton();
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(400.0f, 200.0f);
	button->setOnClick([]()
		{
			DATA->setAllowMusic(!DATA->getAllowMusic());
		}
	);
	m_Button.push_back(button);
	music = button;
// Button go home
	button = new GameButton("home");
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(350.0f, 400.0f);
	button->setOnClick([]()
		{
			GSM->PopState();
			GSM->PopState();
			GSM->PopState();
			HS->Init();
		}
	);
	m_Button.push_back(button);
// Button restart
	button = new GameButton("restart");
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(500.0f, 400.0f);
	button->setOnClick([]()
		{
			OPERATOR->resetMap = true;
			GSM->PopState();
		}
	);
	m_Button.push_back(button);
// Button exit
	button = new GameButton("exit");
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setOrigin(button->getSize() / 2.0f);
	button->setPosition(650.0f, 400.0f);
	button->setOnClick([]()
		{
			GSM->PopState();
		}
	);
	m_Button.push_back(button);

// BackGround
	sf::RectangleShape* rect = nullptr;
	rect = new RectangleShape();
	rect->setTexture(DATA->getTexture("BackGround/pause"));
	rect->setSize(sf::Vector2f(550.0f, 550.0f));
	rect->setOrigin(rect->getSize() / 2.0f);
	rect->setPosition(screenWidth / 2.0f, screenHeight / 2.0f);
	m_Background.push_back(rect);

// Text
	sf::Text* text = nullptr;
	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(28);
	text->setFillColor(sf::Color::Black);
	text->setPosition(420.0f, 265.0f);
	m_Text.push_back(text);
	text_Music = text;

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(28);
	text->setFillColor(sf::Color::Black);
	text->setPosition(420.0f, 305.0f);
	m_Text.push_back(text);
	text_Sound = text;

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(28);
	text->setFillColor(sf::Color::Black);
	text->setPosition(310.0f, 430.0f);
	text->setString("Home");
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(28);
	text->setFillColor(sf::Color::Black);
	text->setPosition(440.0f, 430.0f);
	text->setString("Restart");
	m_Text.push_back(text);

	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setCharacterSize(28);
	text->setFillColor(sf::Color::Black);
	text->setPosition(610.0f, 430.0f);
	text->setString("Close");
	m_Text.push_back(text);
}

void GSPause::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}

	if (DATA->getAllowSound()) {
		sound->setTexture(DATA->getTexture("GState/sound"));
		text_Sound->setString("Sound: On.");
	}
	else {
		sound->setTexture(DATA->getTexture("GState/sound_off"));
		text_Sound->setString("Sound: Off.");
	}
	if (DATA->getAllowMusic()) {
		music->setTexture(DATA->getTexture("GState/music_on"));
		text_Music->setString("Music: On.");
	}
	else {
		music->setTexture(DATA->getTexture("GState/music_off"));
		text_Music->setString("Music: Off.");
	}
}

void GSPause::Render(sf::RenderWindow* window)
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
