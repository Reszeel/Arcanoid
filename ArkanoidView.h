#ifndef ARKANOIDVIEW_H
#define ARKANOIDVIEW_H
#include <vector>
#include "ArkanoidModel.h"


class ArkanoidView :public ArkanoidModel
{
    ArkanoidModel &model;

    public:
        ArkanoidView(ArkanoidModel &m);
        void draw(sf::RenderWindow &win);

};

#endif // ARKANOIDVIEW_H
