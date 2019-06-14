#ifndef INTROVIEW_H
#define INTROVIEW_H
#include "ArkanoidModel.h"


class IntroView
{
    ArkanoidModel & model;
    sf::Font font;
    sf::Text opening;

    public:
        IntroView(ArkanoidModel &m);
        void draw(sf::RenderWindow &win);
        bool isFinished(sf::Event &event);
};

#endif // INTROVIEW_H
