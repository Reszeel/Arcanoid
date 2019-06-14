#include <SFML/Graphics.hpp>
#include "ArkanoidModel.h"
#include "ArkanoidController.h"
#include "ArkanoidView.h"
#include <iostream>
#include <IntroView.h>

int main()
{

    sf::RenderWindow app(sf::VideoMode(800, 800), "SFML window");
    ArkanoidModel ap;
    IntroView iv(ap);
    ArkanoidController ac(ap);
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            ac.handleEvent(event);// Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        ac.draw(app);
        ac.mov();
        ap.isFinished();
        //ap.moveBall();
        //ap.movePlatform();
        //ap.boom();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
