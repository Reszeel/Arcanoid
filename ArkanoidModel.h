#ifndef ARKANOIDMODEL_H
#define ARKANOIDMODEL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <ctime>
#include <windows.h>


class ArkanoidModel
{
    int a;
    int ballx;
    int bally;
    int movex;
    int movey;
    int HP;
    int score;

    sf::Texture background_texture;
    sf::Texture ball_texture;
    sf::Sprite sprite;
    sf::Texture rightwall;
    sf::Texture leftwall;
    sf::Texture topwall;
    sf::Texture platform_texture;
    sf::Font font;
    sf::Text health;
    sf::Sprite wallSprite;
protected:
    sf::Sprite background;
    sf::Sprite platform;
    sf::Sprite ball;
    std::vector <sf::Sprite> wall;
    std::vector <sf::RectangleShape> bricks;
    public:
        ArkanoidModel();
        void draw (sf::RenderWindow &win);
        void moveBall();
        void movePlatform(int x);
        void boom();
        bool isFinished();
        std::vector<sf::RectangleShape> getBricks();
        std::vector <sf::Sprite> getWall();
        sf::Sprite getBall();
        sf::Sprite getPlatform();
        sf::Sprite getBackground();
        int getHP();
        void reset();
};

#endif // ARKANOIDMODEL_H
