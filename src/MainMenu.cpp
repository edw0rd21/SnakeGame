#include <SFML/Window/Event.hpp>
#include "GamePlay.hpp"
#include "MainMenu.hpp"
MainMenu::MainMenu(std::shared_ptr<Context>& context)
	:m_context(context), m_playButtonSelected(true), m_playButtonPressed(false), m_exitButtonSelected(false), m_exitButtonPressed(false){}


MainMenu::~MainMenu() {}


void MainMenu::Init()
{
	//Title
	m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameTitle.setString("Snake Game");
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
						  m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
							m_context->m_window->getSize().y / 2 - 150.f);
	m_gameTitle.setCharacterSize(35);

	//Play Button
	m_playButton.setFont(m_context->m_assets->GetFont(SUB_FONT));
	m_playButton.setString("Play");
	m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
		m_playButton.getLocalBounds().height / 2);
	m_playButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 25.f);
	m_playButton.setCharacterSize(20);

	//Exit Button
	m_exitButton.setFont(m_context->m_assets->GetFont(SUB_FONT));
	m_exitButton.setString("Exit");
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
		m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 25.f);
	m_exitButton.setCharacterSize(20);
}

void MainMenu::ProcessInput()
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
			switch (event.key.code)
			{
			case sf::Keyboard::W:
			case sf::Keyboard::Up:
			{
				if (!m_playButtonSelected)
				{
					m_playButtonSelected = true;
					m_exitButtonSelected = false;
				}
				break;
			}
			case sf::Keyboard::S:
			case sf::Keyboard::Down:
			{
				if (!m_exitButtonSelected)
				{
					m_playButtonSelected = false;
					m_exitButtonSelected = true;
				}
				break;
			}
			case sf::Keyboard::Return:
			{
				m_playButtonPressed = false;
				m_exitButtonPressed = false;
				if (m_playButtonSelected)
				{
					m_playButtonPressed = true;
				}
				else
				{
					m_exitButtonPressed = true;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

void MainMenu::Update(sf::Time deltaTime)
{
	if(m_playButtonSelected)
	{
		m_playButton.setFillColor(sf::Color::Yellow);
		m_exitButton.setFillColor(sf::Color::White);
	}
	else
	{
		m_playButton.setFillColor(sf::Color::White);
		m_exitButton.setFillColor(sf::Color::Yellow);
	}
	if (m_playButtonPressed)
	{
		m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
	}
	else if (m_exitButtonPressed)
	{
		m_context->m_window->close();
	}
}

void MainMenu::Draw()
{
	m_context->m_window->clear(sf::Color::Cyan);
	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->draw(m_playButton);
	m_context->m_window->draw(m_exitButton);
	m_context->m_window->display();
}