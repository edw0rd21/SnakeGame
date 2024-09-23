#include <iostream>
#include "AssetManager.hpp"

miniEngine::AssetManager::AssetManager(){}

miniEngine::AssetManager::~AssetManager(){}

void miniEngine::AssetManager::addTexture(int id, const std::string& filePath, bool isRepeated)
{
	auto texture = std::make_unique < sf::Texture>();
	if (texture->loadFromFile(filePath)) 
	{
		texture->setRepeated(isRepeated);
		m_textures[id] = std::move(texture);
	}
}

void miniEngine::AssetManager::addFont(int id, const std::string &filePath)
{
	auto font = std::make_unique<sf::Font>();
	if (font->loadFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& miniEngine::AssetManager::GetTexture(int id) const
{
	return *(m_textures.at(id).get());
}

const sf::Font& miniEngine::AssetManager::GetFont(int id) const
{
	return *(m_fonts.at(id).get());
}