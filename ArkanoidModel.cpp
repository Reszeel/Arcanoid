#include "ArkanoidModel.h"

ArkanoidModel::ArkanoidModel()
{
    if (!rightwall.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\rightwall.png")) abort();
    if (!ball_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\ball.png")) abort();
    if (!leftwall.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\leftwall.png")) abort();
    if (!platform_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\platform.png")) abort();
    if (!background_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\background.png")) abort();
    sf::RectangleShape brick(sf::Vector2f(35, 20));
    for (int i = 0; i < 22; ++i){
        for (int j = 0; j < 15; ++j){
            brick.setPosition (35*i + 15, 20*j);
            brick.setOutlineThickness(1);
            brick.setOutlineColor(sf::Color::Black);
            brick.setFillColor(sf::Color::Red);
            bricks.push_back(brick);
        }
    }
    platform.setTexture(platform_texture);
    platform.setPosition(300, 760);
    background.setTexture(background_texture);
    ball.setTexture(ball_texture);
    ball.setPosition(500, 500);
    movex = 3;
    movey = 3;
}
void ArkanoidModel::draw(sf::RenderWindow &win){
    win.draw(background);

    for (int i = 0; i < bricks.size(); ++i){
        win.draw(bricks[i]);
    }
    win.draw(platform);
    win.draw(ball);
}
void ArkanoidModel::moveBall(){
    ballx =  ball.getPosition().x;
    bally = ball.getPosition().y;
    if (ballx > 785 || ballx < 15) movex = -movex;
    if (bally >799 || bally < 15) movey= -movey;

    ball.move(movex, movey);
    Sleep(5);
}
void ArkanoidModel::movePlatform(){


}
