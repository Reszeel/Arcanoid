#include <SFML/Graphics.hpp>
#include "ArkanoidModel.h"
#include "ArkanoidController.h"
#include <iostream>

int main()
{

    sf::RenderWindow app(sf::VideoMode(800, 800), "SFML window");
    ArkanoidModel ap;
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
        ap.draw(app);
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
