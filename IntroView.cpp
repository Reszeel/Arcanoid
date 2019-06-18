#include "IntroView.h"

IntroView::IntroView(ArkanoidModel &m):model(m)
{
    if (!font.loadFromFile("/home/c/Downloads/Arkanoid/bin/Debug/arial.ttf")) abort();


}
void IntroView::draw(sf::RenderWindow &win){
    model.draw(win);
    opening.setFont(font);
    opening.setPosition(150,600);
    opening.setString("PRESS SPACE TO START");
    opening.setFillColor(sf::Color::White);
    opening.setCharacterSize(50);
    win.draw(opening);
}


