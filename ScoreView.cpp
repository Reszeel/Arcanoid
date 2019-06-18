#include "ScoreView.h"

ScoreView::ScoreView(ArkanoidController &a):arkanoid(a)
{
    if (!font.loadFromFile("/home/c/Downloads/Arkanoid/bin/Debug/arial.ttf")) abort();
}
void ScoreView::draw(sf::RenderWindow &win){
    arkanoid.draw(win);
    again.setFont(font);
    again.setPosition(100,400);
    again.setString("PRESS SPACE TO PLAY AGAIN");
    again.setFillColor(sf::Color::White);
    again.setCharacterSize(50);
    ending.setFont(font);
    ending.setPosition(200, 500);
    ending.setString("PRESS ESC TO EXIT");
    ending.setFillColor(sf::Color::White);
    ending.setCharacterSize(50);
    win.draw(again);
    win.draw(ending);
}
