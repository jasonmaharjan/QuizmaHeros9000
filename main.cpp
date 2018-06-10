#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"Menu.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1280 , 960), "DARK PIRATES OF QUIZMA THAT'LL HUNT U DOWN AND SELL YOUR SOUL TO THE FARMER WITH A SHOTGUN");
	window.setKeyRepeatEnabled(false);

	
	//For Cursor
	window.setMouseCursorVisible(false);	
	/*sf::View fixed = window.getView();
	sf::Texture Cursor;
	Cursor.loadFromFile("real_cursor.png");
	sf::Sprite Cursor_sprite;
	Cursor_sprite.setTexture(Cursor);
	//Cursor_sprite.setTextureRect(sf::IntRect(0, 150, 150, 153));
	Cursor_sprite.setPosition(150,175);
	Cursor_sprite.setScale(0.45,0.35);*/


	//For Background image
	sf::Texture b_texture;
	b_texture.loadFromFile("background.jpg");
	b_texture.setSmooth(true);
	sf::Sprite background;
	background.setTexture(b_texture);

	//For Cursor image
	/*sf::Texture cursor_texture;
	cursor_texture.loadFromFile("point.png");
	cursor_texture.setSmooth(true);
	sf::Sprite cursor_sprite;
	cursor_sprite.setColor(sf::Color::Yellow);
	cursor_sprite.setTexture(cursor_texture);
	cursor_sprite.setPosition(230, 300);
	cursor_sprite.setScale(0.1, 0.1);*/

	sf::RectangleShape pointer(sf::Vector2f(120.f, 50.0f));
	sf::Texture pointerTexture;
	pointerTexture.loadFromFile("arrow.png");
	pointer.setTexture(&pointerTexture);
	pointer.setFillColor(sf::Color::White);
	pointer.setPosition(250, 300);
	pointerTexture.setSmooth(true);

	//For Menu
	Menu menu(window.getSize().x, window.getSize().y);

	//Font
	sf::Font font;
	font.loadFromFile("CENTAUR.ttf");

	sf::Text game_title;
	game_title.setScale(3, 3);
	game_title.setString("Quizma Heroes");
	game_title.setPosition(400,50);

	sf::Text rights1;
	rights1.setFont(font);
	rights1.setScale(0.75, 0.75);
	rights1.setString("All rights not reserved!!");
	rights1.setPosition(550, 850);

	sf::Text rights2;
	rights2.setFont(font);
	rights2.setScale(0.75, 0.75);
	rights2.setString("Quizma Productions(2018-)");
	rights2.setPosition(525, 875);

	

	// Set the font to our message
	game_title.setFont(font);
		

	//open music file
	sf::Music music;
	music.openFromFile("pirates.wav");
	music.play();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.MoveUp();
						pointer.move(0, -95);
						break;
					}

					else if (event.key.code == sf::Keyboard::Down)
					{
						menu.MoveDown();
						pointer.move(0, 95);

						break;				
					}

				case sf::Event::KeyPressed:

					if (event.key.code == sf::Keyboard::Escape)
						window.close();

					else if ((event.key.code == sf::Keyboard::M))
					{
						music.play();
					}

				default:
					break;
			}
		}

		// Set position of the mouse
		//Cursor_sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		
	    		

		//Render Cycle

		window.clear();
		window.draw(background);
		menu.draw(window);
		window.draw(game_title);
		window.draw(rights1);
		window.draw(rights2);
		//window.draw(cursor_sprite);
		window.draw(pointer);
		//window.setView(fixed);		

		//Render Objects
		window.display();
	}

	return 0;
}