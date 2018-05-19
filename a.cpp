#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main(){	
	enum Direction { Down=0, Left=48, Right=96, Up=144};

	sf::Vector2i source(32,Down);
	float frameCounter =0, frameSpeed=500, switchFrame=100;

	sf::RenderWindow window;
	window.create(sf::VideoMode(700,700),"Pirate of the Quizma");

	


	sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("spritewalk.png");
	player.setTexture(&playerTexture);
	player.setPosition(275,550);

	sf::Music music;
	music.openFromFile("GOT.wav");

	
	window.setKeyRepeatEnabled(false);

	while (window.isOpen()){
		
		sf::Event event;

		while (window.pollEvent(event)){

				
			switch(event.type){

				case sf::Event::Closed:
						window.close();
						break;

				case sf::Event::KeyPressed:
				
						if(event.key.code ==sf::Keyboard::Escape)
							window.close();

						else if((event.key.code == sf::Keyboard::Return))
							music.play();		
							
				/*case sf::Event::ButtonPressed:
						if()													*/
						
			
						
				default:
						break;

			
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			source.y=Up;
			player.move(0,-1);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			source.y=Left;
			player.move(-1,0);
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			source.y=Right;
			player.move(1,0);
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			source.y=Down;
			player.move(0,1);
		}

		source.x +=32;
		if (source.x >=playerTexture.getSize().x){
			source.x=0;
		}

		player.setTextureRect(sf::IntRect(source.x,source.y,32,48));

	
	window.draw(player);
	window.display();
	window.clear();

}
return 0;


}
