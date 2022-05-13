#include "GSSetting.h"

GSSetting::GSSetting()
{
	music = nullptr;
	sound = nullptr;
	Gmusic = nullptr;
	Gsound = nullptr;
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	GameButton* button;
// Button close
	button = new GameButton("close_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(80.0f, 80.0f));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_Button.push_back(button);
// Button music
	button = new GameButton();
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8 - 100.0f);
	button->setOnClick([]() {DATA->setAllowMusic(!DATA->getAllowMusic()); });
	Gmusic = button;
	m_Button.push_back(button);
// Button sound
	button = new GameButton();
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100.0f, 100.0f));
	button->setPosition(screenWidth / 2 + screenWidth / 4 - 100.0f, screenHeight - screenHeight / 8 - 100.0f);
	button->setOnClick([]() {DATA->setAllowSound(!DATA->getAllowSound()); });
	Gsound = button;
	m_Button.push_back(button);

//Background
	sf::Texture* texture = DATA->getTexture("Background/background");
	sf::RectangleShape* rectangle = nullptr;
	rectangle = new RectangleShape();
	rectangle->setTexture(texture);
	rectangle->setSize(sf::Vector2f(screenWidth, screenHeight));
	rectangle->setPosition(sf::Vector2f(0.0f, 0.0f));
	m_Background.push_back(rectangle);

	sf::Text* text = nullptr;
// Text music
	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setFillColor(sf::Color::Black);
	text->setPosition(sf::Vector2f(380.0f, 200.0f));
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(40);
	m_Text.push_back(text);
	music = text;
// Text sound
	text = new Text();
	text->setFont(*DATA->getFont("VNCOOP"));
	text->setFillColor(sf::Color::Black);
	text->setPosition(sf::Vector2f(380.0f, 250.0f));
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(40);
	m_Text.push_back(text);
	sound = text;
}

void GSSetting::Update(float deltaTime)
{
	for (auto button : m_Button) {
		button->Update();
	}
	if (DATA->getAllowMusic() == true) {
		music->setString("Music: On");
		Gmusic->setTexture(DATA->getTexture("GState/music_on"));
	}
	else {
		music->setString("Music: Off");
		Gmusic->setTexture(DATA->getTexture("GState/music_off"));
	}

	if (DATA->getAllowSound() == true) {
		sound->setString("Sound: On");
		Gsound->setTexture(DATA->getTexture("GState/sound"));
	}
	else {
		sound->setString("Sound: Off");
		Gsound->setTexture(DATA->getTexture("GState/sound_off"));
	}
}

void GSSetting::Render(sf::RenderWindow* window)
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
