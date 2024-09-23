#include "SplashScreen.hpp"
#include "MainMenu.hpp"
#include <SFML/Window/Event.hpp>
SplashScreen::SplashScreen(std::shared_ptr<Context>& context)
	:m_context(context), m_tabButtonPressed(false){}


SplashScreen::~SplashScreen(){}

void SplashScreen::Init()
{
	m_context->m_assets->addFont(MAIN_FONT, "AssetFile/fonts/Roboto-Black.ttf");
	m_context->m_assets->addFont(SUB_FONT, "AssetFile/fonts/Roboto-Italic.ttf");

	//Credits
	m_credits.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_credits.setString("edw0rd creations");
	m_credits.setFillColor(sf::Color::Yellow);
	m_credits.setOrigin(m_credits.getLocalBounds().width / 2,
		m_credits.getLocalBounds().height / 2);
	m_credits.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 150.f);
	m_credits.setCharacterSize(30);

	//Tab Button
	m_tabButton.setFont(m_context->m_assets->GetFont(SUB_FONT));
	m_tabButton.setString("Press TAB Button to enter");
	m_tabButton.setOrigin(m_tabButton.getLocalBounds().width / 2,
		m_tabButton.getLocalBounds().height / 2);
	m_tabButton.setPosition(m_context->m_window->getSize().x/2,
		m_context->m_window->getSize().y / 2 - 25.f);
	m_tabButton.setCharacterSize(15);

}

void SplashScreen::ProcessInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_context->m_window->close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Tab)
			{
				m_tabButtonPressed = true;
				break;
			}
		}
	}
}

void SplashScreen::Update(sf::Time deltaTime)
{
	if (m_tabButtonPressed)
	{
		m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
	}

}

void SplashScreen::Draw()
{
	m_context->m_window->clear(sf::Color::Black);
	m_context->m_window->draw(m_credits);
	m_context->m_window->draw(m_tabButton);
	m_context->m_window->display();
}