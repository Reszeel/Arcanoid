#ifndef ARKANOIDCONTROLLER_H
#define ARKANOIDCONTROLLER_H
#include "ArkanoidModel.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>


class ArkanoidController
{
    ArkanoidModel & model;
    public:
        ArkanoidController(ArkanoidModel &m);
        void mov();
        void handleEvent(sf::Event &event);
        void draw(sf::RenderWindow &win){model.draw(win);}
        bool isFinished();
        void resetgame();

};

#endif // ARKANOIDCONTROLLER_H
