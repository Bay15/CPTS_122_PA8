#include <SFML/Graphics.hpp>
#include "mainScreen.h"
#include "pauseScreen.h"
#include "endGameScreen.h"
#include "player.h"
#include "MapLoad.h"
#include "player.h"
#include <stack>
#include <vector>
#define pixel_length 64
//https://www.youtube.com/watch?v=bx3--22D4E4

int main()
{
    // create the window
    // define the level with an array of tile indices
    std::vector<int> level = {};
    std::vector<int> temp = {};

    std::stack<int> X;
    std::stack<int> Y;
    int height = 14, width=18;

    std::vector<std::vector<bool>> move(height, std::vector<bool>(width));
    std::vector<std::vector<int>> it_is(height, std::vector<int>(width));

    
    //ray is a pre made map it is a 12 by 16 map the 14,18 are used for built in boarders(win and spawn are also built in
    int ray[1000] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,
        0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
        1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,
        1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,
        1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,
        1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,
        1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,
        1,1,0,1,0,1,0,1,0,1,1,3,1,1,1,1,1,1,
        1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,1,
        1,1,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,
        1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,

    };
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            move[i][j] = true;
            it_is[i][j] = ray[j + width * i];//feeds from pre-set into it_is
        }
    }

    for (int i = 0; i < height; i++)//itterate through height
    {
        for (int j = 0; j < width; j++)//itterate through width
        {
            if (i == 1 && j == 1)//place start
                level.push_back(4);
            else if (i == (height - 2) && j == (width - 2))//place win
                level.push_back(2);
            else if (0 == i || 0 == j || i == (height - 1) || j == (width - 1))//place the edge walls
                level.push_back(0);
            else
            {
                level.push_back(it_is[i][j]);//filling in level from it_is
            }
        }
    }

    sf::RenderWindow window(sf::VideoMode((width)*pixel_length, (height)*pixel_length), "Maze Game Xtreme");
    mainScreen main(0);
    pauseScreen pause(2);
    endGameScreen endGame(3);
    player player1;
    std::vector<wall> wallArray;
    std::vector<wall> winArray;
    std::vector<wall> lavaArray;
    TileMap map;
    sf::View view1, view2; //views for the game
    view1.setCenter(sf::Vector2f(512, 384)); //screen
    view1.setSize(sf::Vector2f(1024, 768));
    view2.setCenter(sf::Vector2f(80, 80)); //player
    view2.setSize(sf::Vector2f(200, 200));
    

    //making sure the texture loads properly for the tileset
    if (!map.load("Resources/tileset.png", sf::Vector2u(pixel_length, pixel_length), level, width, height, wallArray, winArray, lavaArray)) 
        return -1;
    //while the window is open, the game runs
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) //if the window is said to be closed
        {
            if (event.type == sf::Event::Closed)
                window.close(); //window is closed and game stops 
        }

        window.clear();

        if (!main.checkIfStart(window)) //Shows the mainscreen if it isn't startGame
        {
            window.setView(view1);
            main.makeMainScreen(window); //makes the mainscreen
            main.makeActive(window); //shows which button the user is hovering over
        }
        else if (main.checkIfStart(window)) //Clicked on Playgame
        {
            window.clear(); //clears any of the mainscreen//updates game screen
 
            //player can only move as long as the game isn't paused, they're alive, and they hadn't won
            if (!pause.checkIfPaused() && player1.getAlive() && !player1.getWin()) 
            {
                window.setView(view2); //sets the view to be close to player
                player1.move(wallArray, winArray, lavaArray, view2); //player moves
            }
            window.draw(map);//draws map
            window.draw(player1.sprite);//draws sprite
            
            //checks to see if the player won or died
            if (endGame.checkIfEnd(window, player1.getAlive(), player1.getWin()))
            {
                window.setView(view1); //sets to an end screen
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //redirects user back to Main Menu
                {
                    //resetting everything
                    pause.setExit(false);
                    pause.setPause(false);
                    main.setStart(false);
                    player1.resetPlayer();
                    view2.setCenter(sf::Vector2f(80, 80));
                    window.clear();
                }
            }
            
            if (pause.pauseScreenGame(window)) //if the game is paused
            {
                pause.makeBackground(window); //make paused BG
                window.setView(view1); //sets it to screen view
            }
            
            else if (pause.checkIfExit()) //Exits to main menu
            {
                //resetting everything
                pause.setExit(false);
                pause.setPause(false);
                main.setStart(false);
                player1.resetPlayer();
                view2.setCenter(sf::Vector2f(80, 80));
                window.clear();
            }

            
        }
        if(main.checkIfHowTo(window)) //redirects user to How To Play PAge
        {
            //show how to page
            window.clear();
            main.makeBackground(window, 1); //sets BG to how to play page
         
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //redirects user back to Main Menu
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
