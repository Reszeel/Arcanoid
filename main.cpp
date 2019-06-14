#include <SFML/Graphics.hpp>
#include "ArkanoidModel.h"
#include "ArkanoidController.h"
#include "ArkanoidView.h"
#include <iostream>
#include "IntroView.h"
#include "IntroController.h"
#include "GameManager.h"
#include "ScoreController.h"


int main()
{

    sf::RenderWindow app(sf::VideoMode(800, 800), "SFML window");
    ArkanoidModel ap;
    ap.reset();
    IntroView iv(ap);
    IntroController ic(iv);

    ArkanoidController ac(ap);
    ScoreView sv(ac);
    ScoreController sc(sv);
    GameManager game(ac, ic, sc);
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            game.handle(event);
        }

        // Clear screen
        app.clear();
        game.draw(app);
        game.updateState();
        // Draw the sprite
        //ac.draw(app);
        //ac.mov();
        //ap.isFinished();
        //ap.moveBall();
        //ap.movePlatform();
        //ap.boom();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
