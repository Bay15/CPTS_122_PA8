#include <SFML/Graphics.hpp>
#include "mainScreen.h"
#include "pauseScreen.h"
#include "player.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Maze Game Xtreme");
    mainScreen main(0);
    pauseScreen pause(2);
    player player1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (!main.checkIfStart(window)) //Shows the mainscreen
        {
            main.makeMainScreen(window);
            main.makeActive(window);
        }
        else if (main.checkIfStart(window))
        {
            //Playgame
            window.clear();

            window.draw(player1.player_entity);
            if (!pause.checkIfPaused())
            {
                player1.move();
            }


            if (pause.pauseScreenGame(window))
            {
                pause.makePauseScreen(window);
            }
            else if (pause.checkIfExit())
            {
                pause.setExit(false);
                pause.setPause(false);
                main.setStart(false);
                window.clear();
            }
        }
        if(main.checkIfHowTo(window)) //redirects user to How To Play PAge
        {
            //show how to page
            window.clear();
            main.setBG(1);
            main.makeBackground(window);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                main.setHowTo(false);
                window.clear();
            }
        }
        if (main.checkIfExit(window)) //Exits the game
        {
            window.close();
        }
        

        window.display();
    }

    return 0;
}