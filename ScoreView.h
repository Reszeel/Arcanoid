#ifndef SCOREVIEW_H
#define SCOREVIEW_H
#include "ArkanoidController.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>


class ScoreView
{
    ArkanoidController &arkanoid;
    sf::Font font;
    sf::Text again;
    sf::Text ending;
    public:
        ScoreView(ArkanoidController &a);
        void draw(sf::RenderWindow &win);
};

#endif // SCOREVIEW_H
