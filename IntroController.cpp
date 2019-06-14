#include "IntroController.h"

IntroController::IntroController(IntroView & v): view(v)
{
    finish = false;
}
void IntroController::handleEvent(sf::Event &event){
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) finish = true;
}
bool IntroController::isFinished(){
    return finish;
}
