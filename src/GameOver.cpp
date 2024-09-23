#include "GameOver.hpp"
#include "GamePlay.hpp"
#include <SFML/Window/Event.hpp>


GameOver::GameOver(std::shared_ptr<Context>& context)
	:m_context(context), m_retryButtonSelected(true), m_retryButtonPressed(false), 
	 m_exitButtonSelected(false), m_exitButtonPressed(false){}

GameOver::~GameOver(){}

void GameOver::Init()
{
	//Title
	m_gameOverTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameOverTitle.setString("Game Over :'(");
	m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2,
		m_gameOverTitle.getLocalBounds().height / 2);
	m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 150.f);
	m_gameOverTitle.setCharacterSize(37);

	//Retry Button
	m_retryButton.setFont(m_context->m_assets->GetFont(SUB_FONT));
	m_retryButton.setString("Retry");
	m_retryButton.setOrigin(m_retryButton.getLocalBounds().width / 2,
		m_retryButton.getLocalBounds().height / 2);
	m_retryButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 25.f);
	m_retryButton.setCharacterSize(20);

	//Exit Button
	m_exitButton.setFont(m_context->m_assets->GetFont(SUB_FONT));
	m_exitButton.setString("Exit");
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
		m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 25.f);
	m_exitButton.setCharacterSize(20);
}

void GameOver::ProcessInput()
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
				if (!m_retryButtonSelected)
				{
					m_retryButtonSelected = true;
					m_exitButtonSelected = false;
				}
				break;
			}
			case sf::Keyboard::S:
			case sf::Keyboard::Down:
			{
				if (!m_exitButtonSelected)
				{
					m_retryButtonSelected = false;
					m_exitButtonSelected = true;
				}
				break;
			}
			case sf::Keyboard::Return:
			{
				m_retryButtonPressed = false;
				m_exitButtonPressed = false;
				if (m_retryButtonSelected)
				{
					m_retryButtonPressed = true;
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

void GameOver::Update(sf::Time deltaTime)
{
	if (m_retryButtonSelected)
	{
		m_retryButton.setFillColor(sf::Color::Yellow);
		m_exitButton.setFillColor(sf::Color::White);
	}
	else
	{
		m_retryButton.setFillColor(sf::Color::White);
		m_exitButton.setFillColor(sf::Color::Yellow);
	}
	if (m_retryButtonPressed)
	{
		m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
	}
	else if (m_exitButtonPressed)
	{
		m_context->m_window->close();
	}
}

void GameOver::Draw()
{
	m_context->m_window->clear(sf::Color::Red);
	m_context->m_window->draw(m_gameOverTitle);
	m_context->m_window->draw(m_retryButton);
	m_context->m_window->draw(m_exitButton);
	m_context->m_window->display();
}