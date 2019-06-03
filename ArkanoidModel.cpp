#include "ArkanoidModel.h"

ArkanoidModel::ArkanoidModel()
{
    a = 4;
    if (!rightwall.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\rightwall.png")) abort();
    if (!ball_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\ball.png")) abort();
    if (!leftwall.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\leftwall.png")) abort();
    if (!platform_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\platform.png")) abort();
    if (!background_texture.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\background.png")) abort();
    sf::RectangleShape brick(sf::Vector2f(35, 20));
    for (int i = 0; i < 22; ++i){
        for (int j = 0; j < 15; ++j){
            brick.setPosition (15 + 35*i, 20*j);
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
    ball.setPosition(550, 560);
    wallSprite.setTexture(leftwall);
    for (int i = 0; i < 9; ++i){
        wallSprite.setPosition(0, 98*i);
        wall.push_back(wallSprite);
    }
    wallSprite.setTexture(rightwall);
    for (int i = 0; i < 9; ++i){
        wallSprite.setPosition(785, 98*i);
        wall.push_back(wallSprite);
    }
    movex = 1;
    movey = 1;
    firstTouch = false;
}
void ArkanoidModel::draw(sf::RenderWindow &win){
    win.draw(background);

    for (int i = 0; i < wall.size(); ++i){
        win.draw(wall[i]);
    }
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
}
void ArkanoidModel::movePlatform(){
    if (platform.getPosition().x > 799 || platform.getPosition().x < 1) a = -a;
        platform.move(a, 0);
}
void ArkanoidModel::boom(){
    int x;
    int y;
    for (int i = 0; i < bricks.size(); ++i){
        if (ball.getGlobalBounds().intersects(bricks[i].getGlobalBounds())){
            x = ball.getPosition().x;
            y = ball.getPosition().y;
            if (x % 35 == 0) movex= - movex;
            if (y % 20 == 0) movey = - movey;
            if ((x+10)%35 == 0) movex = -movex;
            if ((y+10)%20 == 0) movey = -movey;
            bricks.erase(bricks.begin() + i);
            ball.move(movex, movey);
        }
    }
}
