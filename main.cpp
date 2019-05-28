#include <SFML/Graphics.hpp>
#include "ArkanoidModel.h"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 800), "SFML window");


    // Load a sprite to display
    ArkanoidModel ap;
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        ap.draw(app);
        ap.moveBall();
        //ap.movePlatform();
        ap.boom();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
