#include "Menu.h"
#include<iostream>

Menu::Menu(float width, float height)
{
	font.loadFromFile("CENTAUR.ttf");
	/*
	if (!font.loadFromFile("OLDENGL.ttf"));
	{
		//handle error
		std::cout << "Couldn't load the font, not even close to sorry tho" << std::endl;

	}*/

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Yellow);
	menu[0].setScale(1.5,1.5);
	menu[0].setString("New Game ");
	menu[0].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setScale(1.5,1.5);
	menu[1].setString("Load Game ");
	menu[1].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setScale(1.5, 1.5);
	menu[2].setString("Options ");
	menu[2].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.5));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setScale(1.5, 1.5);
	menu[3].setString("Exit ");
	menu[3].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	

	selectedItemIndex = 0;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++ )
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex -1  >= 0)
	{
		menu[selectedItemIndex-1].setFillColor(sf::Color::Yellow);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex +1  < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex+1].setFillColor(sf::Color::Yellow);
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
	}
}

