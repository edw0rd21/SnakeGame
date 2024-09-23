#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"

class SplashScreen : public miniEngine::State
{
public:
	SplashScreen(std::shared_ptr<Context>& context);
	~SplashScreen();

	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override;

private:
	std::shared_ptr<Context> m_context;
	sf::Text m_credits;
	sf::Text m_tabButton;

	bool m_tabButtonPressed;
};

