#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <SFML/Audio.hpp>
//#include"Collisions.h"


int main() {

	enum Direction { Down = 0, Left = 48, Right = 96, Up = 144 };
	sf::Vector2i source(32, Up);
	float frameCounter = 0, frameSpeed = 500, switchFrame = 100;

	//creating game window
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 680), "Do u know de way");

	//bool isFullscreen=(false);

	window.setKeyRepeatEnabled(false);

	//loading object textures
	//loading object, sprites shapes and configuration

	sf::Texture doorTexture;
	doorTexture.loadFromFile("TileA.png");
	doorTexture.setSmooth(true);
	sf::Sprite walls;
	walls.setTexture(doorTexture);
	walls.setTextureRect(sf::IntRect(0, 0, 48, 52));//crop
	walls.setPosition(sf::Vector2f(100, 100));
	//walls.setScale(sf::Vector2f(3.f, 3.f));
	

	//loading player sprite and configuration

	sf::RectangleShape player(sf::Vector2f(100.f, 100.0f));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("sprite.png");
	player.setTexture(&playerTexture);
	player.setPosition(240, 320);
	playerTexture.setSmooth(true);

	//framerate
	sf::Clock clock;

	//open music file
	sf::Music music;
	music.openFromFile("glasgowkiss.wav");


	//maps
/*	std::ifstream openfile("Map1.txt");
	std::ifstream openfile1("collmap.txt");

	sf::Texture tileTexture;
	sf::Sprite tiles;

	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);
	if (openfile.is_open()) {

		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof()) {

			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y)) {
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			if (openfile.peek() == '\n') {
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else {
				loadCounter.x++;
			}
		}
		loadCounter.y++;
	}
		int collmap[100][100];
		sf::Vector2i loadCounter1 = sf::Vector2i(0, 0);
		if (openfile.is_open()) {
			while (!openfile1.eof()) {

				std::string str1;
				openfile1 >> str1;
				char x1 = str1[0];
				if (x1 == '0') {
					collmap[loadCounter1.x][loadCounter1.y] = 0;
				}
				else
					collmap[loadCounter1.x][loadCounter1.y] = 1;
				if (openfile.peek() == '\n') {
					loadCounter1.x = 0;
					loadCounter1.y += 32;
				}
				else {
					loadCounter1.x += 32;
				}
			}
			loadCounter1.y += 32;
		}

//	sf::RenderWindow window(sf::VideoMode(480, 320), "Map");
*/

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();

				else if ((event.key.code == sf::Keyboard::Return))
					music.play();

			default:
				break;
			}
		}

		//collisions

		if (player.getGlobalBounds().intersects(walls.getGlobalBounds())) {
			std::cout<<"Collision"<<std::endl;

		}

		else {
			player.move(0, 0);
		}	

		/*
		window.clear();
		for (int i = 0; i < loadCounter.x; i++) {
			for (int j = 0; j < loadCounter.y; j++) {
				if (map[i][j].x != -1 && map[i][j].y != -1) {
					tiles.setPosition(i * 32, j * 32);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
					window.draw(tiles);
				}
				
			}
			
		}
		int pbottom, ptop, pleft, pright;
		pbottom = player.getPosition().y + 32;
		pleft = player.getPosition().x;
		pright = player.getPosition().x + 32;
		ptop = player.getPosition().y;
		
		*/
		//movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			source.y = Up;
			//if (collmap[pleft][ptop] != 0)
				player.move(0, -3);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			source.y = Left;

			player.move(-3, 0);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			source.y = Right;
			player.move(3, 0);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			source.y = Down;
			player.move(0, 3);
		}

		//animation, framerates
		//std::cout<<clock.getElapsedTime().asSeconds()<<std::endl;
		frameCounter += frameSpeed * clock.restart().asSeconds();

		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			source.x += 32;

			if (source.x >= playerTexture.getSize().x) {
				source.x = 0;
			}
		}

		//crop player image(sprite)
		player.setTextureRect(sf::IntRect(source.x, source.y, 32, 48));

		//functions
		//window.draw(door);
		window.clear();
		window.draw(walls);
		window.draw(player);
		window.display();
	}

	return 0;
}

