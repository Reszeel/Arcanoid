#include "ArkanoidController.h"

ArkanoidController::ArkanoidController(ArkanoidModel &m)/*, ArkanoidView&v)*/: model(m)//, view(v)
{

}
void ArkanoidController::handleEvent(sf::Event & event){
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
        model.movePlatform(1);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
        model.movePlatform(2);
    }

}
void ArkanoidController::mov(){
    model.moveBall();
    model.boom();
}
bool ArkanoidController::isFinished(){
    if (model.getHP() == 0) return true;
    return false;
}
void ArkanoidController::resetgame(){
    model.reset();
}
