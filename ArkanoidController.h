#ifndef ARKANOIDCONTROLLER_H
#define ARKANOIDCONTROLLER_H
#include "ArkanoidModel.h"
#include "ArkanoidView.h"
#include <SFML/Window/Keyboard.hpp>
#include <windows.h>
#include <SFML/Graphics.hpp>


class ArkanoidController
{
    ArkanoidModel & model;
    //ArkanoidView & view;
    public:
        ArkanoidController(ArkanoidModel &m);//, ArkanoidView &v);
        void mov();
        void handleEvent(sf::Event &event);
        //void draw(sf::RenderWindow &win){view.draw(win);}

};

#endif // ARKANOIDCONTROLLER_H
