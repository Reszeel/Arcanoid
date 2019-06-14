#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H
#include <IntroView.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>


class IntroController
{
    IntroView &view;
    bool finish;

    public:
    IntroController(IntroView &v);
    void draw(sf::RenderWindow &win){view.draw(win);};
    void handleEvent (sf::Event &event);
    bool isFinished();
    void resetIntro();

};

#endif // INTROCONTROLLER_H
