#pragma once
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.hpp"
#include "StateManager.hpp"

enum AssetID
{
    MAIN_FONT = 0,
    SUB_FONT,
    GRASS,
    FOOD,
    WALL,
    SNAKE
};

struct Context
{
    std::unique_ptr<miniEngine::AssetManager> m_assets;
    std::unique_ptr<miniEngine::StateManager> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<miniEngine::AssetManager>();
        m_states = std::make_unique<miniEngine::StateManager>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
};

