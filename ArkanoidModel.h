#ifndef ARKANOIDMODEL_H
#define ARKANOIDMODEL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <ctime>
#include <windows.h>


class ArkanoidModel
{
    int ballx;
    int bally;
    int movex;
    int movey;
    std::vector <sf::RectangleShape> bricks;
    sf::Texture background_texture;
    sf::Texture ball_texture;
    sf::Sprite sprite;
    sf::Texture rightwall;
    sf::Texture leftwall;
    sf::Texture topwall;
    sf::Texture platform_texture;
    sf::Sprite platform;
    sf::Sprite ball;
    sf::Sprite background;
    std::vector <sf::Sprite> wall;
    public:
        ArkanoidModel();
        void draw (sf::RenderWindow &win);
        void moveBall();

};

#endif // ARKANOIDMODEL_H
