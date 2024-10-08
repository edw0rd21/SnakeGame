#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.hpp"
#include "Game.hpp"

class MainMenu : public miniEngine::State
{
public:

	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltaTime) override;
	void Draw() override;

private:

	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle;
	sf::Text m_playButton;
	sf::Text m_exitButton;

	bool m_playButtonSelected;
	bool m_playButtonPressed;
	bool m_exitButtonSelected;
	bool m_exitButtonPressed;

};		

