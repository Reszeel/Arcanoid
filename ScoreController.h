#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H
#include "ScoreView.h"


class ScoreController
{
    int again;
        ScoreView &view;
    public:
        ScoreController(ScoreView &v);
        void draw(sf::RenderWindow &win){view.draw(win);};
        void handleEvent (sf::Event &event);
        int isFinished();
        void resetScore();
};

#endif // SCORECONTROLLER_H
