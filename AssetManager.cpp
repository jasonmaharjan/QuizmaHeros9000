#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.hpp"

namespace Sonar
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	/*void AssetManager::LoadMusic(std::string name, std::string fileName)
	{
		sf::Music music;

		if (music.openFromFile(fileName))
		{
			this->_musics[name] = music;
		}
	}

	sf::Music &AssetManager::GetMusic(std::string name)
	{
		return this->_musics.at(name);
	}*/

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}