#pragma once
#include<map>
#include<memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace miniEngine
{

	class AssetManager
	{
	private:
		std::map<int, std::unique_ptr <sf::Texture>> m_textures;
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;
	public:
		AssetManager();
		~AssetManager();

		void addTexture(int id, const std::string& filePath, bool isRepeated = false);
		void addFont(int id, const std::string& filePath);

		const sf::Texture& GetTexture(int id) const;
		const sf::Font& GetFont(int id) const;
	};
}

