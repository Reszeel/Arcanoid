#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v): view(v)
{
    again = 2;
}
void ScoreController::handleEvent(sf::Event &event){
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) again = 1;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) again = 0;
}
int ScoreController::isFinished(){
    return again;
}
void ScoreController::resetScore(){
    again = 2;
}
