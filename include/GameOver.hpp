#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"

class GameOver : public miniEngine::State
{
public:
	GameOver(std::shared_ptr<Context>& context);
	~GameOver();

	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override;

private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameOverTitle;
	sf::Text m_retryButton;
	sf::Text m_exitButton;

	bool m_retryButtonSelected;
	bool m_retryButtonPressed;

	bool m_exitButtonSelected;
	bool m_exitButtonPressed;

};

