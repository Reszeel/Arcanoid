#include "IntroView.h"

IntroView::IntroView(ArkanoidModel &m):model(m)
{
    if (!font.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\arial.ttf")) abort();
    //int i = model.getHP
    //std::string tmp;
    //sprintf((char*)tmp.c_str(), "%d", i);
    //std::string str = tmp.c_str(); // fragment z zamian¹ int na string zaczerpniêty z: https://4programmers.net/C/Konwersje_int_na_string_i_string_na_int#c-ostringstream

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


