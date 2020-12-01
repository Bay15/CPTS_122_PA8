#include <SFML/Graphics.hpp>
#include "mainScreen.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Maze Game Xtreme");
    mainScreen main;

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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //makes them leave the game
            {
                main.setStart(false);
                window.clear();
            }
        }
        if(main.checkIfHowTo(window)) //redirects user to How To Play PAge
        {
            //show how to page
            window.clear();


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