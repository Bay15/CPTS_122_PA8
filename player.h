#include <iostream>
#define using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player 
{
    public:
   
        sf::Sprite player_entity;
        sf::Texture player_texture;

        bool alive;

        player() 
        {
            player_texture.loadFromFile("BlopSheet.png");
            player_entity.setTexture(player_texture);
            player_entity.setTextureRect(sf::IntRect(0, 0, 32, 32));
            player_entity.setPosition(64 * 7 + 16, 64 * 1 + 16);
        }

        void move() 
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player_entity.move(0, .25);
                player_entity.setTextureRect(sf::IntRect(0, 0, 32, 32));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player_entity.move(0, -.25);
                player_entity.setTextureRect(sf::IntRect(32, 0, 32, 32));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player_entity.move(-.25, .25);
                player_entity.setTextureRect(sf::IntRect(64, 0, 32, 32));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player_entity.move(.25, 0);
                player_entity.setTextureRect(sf::IntRect(96, 0, 32, 32));
            }
        }
};


#endif

