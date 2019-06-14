#include "GameManager.h"

GameManager::GameManager(ArkanoidController &a, IntroController &i, ScoreController &s): ac(a), ic(i), sc(s)
{
    state =  INTRO;
}
void GameManager::handle(sf::Event &event){
    if (state == INTRO) ic.handleEvent(event);
    if (state == ARKANOID) ac.handleEvent(event);
    if (state == SCORE) sc.handleEvent(event);
}
void GameManager::updateState(){
    if (ic.isFinished() == true) state = ARKANOID;
    if (ac.isFinished() == true) state = SCORE;
    if (sc.isFinished() == 1) {
        ic.resetIntro();
        ac.resetgame();
        sc.resetScore();
        state = INTRO;
    }
}
void GameManager::draw(sf::RenderWindow &win){
    if(state == INTRO) ic.draw(win);
    if (state == ARKANOID) {
        ac.draw(win);
        ac.mov();
    }
    if (state == SCORE){
        sc.draw(win);
        if (sc.isFinished() == 0) win.close();
    }
}
