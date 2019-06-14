#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "IntroController.h"
#include "ArkanoidController.h"
#include "ScoreController.h"

enum GameState {INTRO, ARKANOID, SCORE};
class GameManager
{
    GameState state;
    ArkanoidController &ac;
    IntroController &ic;
    ScoreController &sc;
    public:
        GameManager(ArkanoidController &a, IntroController &i, ScoreController &s);
        void handle (sf::Event &event);
        void draw(sf::RenderWindow &win);
        void updateState();


    protected:

    private:
};

#endif // GAMEMANAGER_H
