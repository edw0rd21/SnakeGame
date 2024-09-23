#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include "SplashScreen.hpp"

Game::Game() : m_context(std::make_shared<Context>())
{
	m_context->m_window->create(sf::VideoMode(920, 540), "snake game :)", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<SplashScreen>(m_context));
}
Game:: ~Game() {}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSincelastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSincelastFrame += clock.restart();

        while (timeSincelastFrame > TIME_PER_FRAME)
        {
            timeSincelastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}
