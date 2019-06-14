#include "ArkanoidModel.h"

ArkanoidModel::ArkanoidModel()
{

}
void ArkanoidModel::reset(){
    score = 0;
    a = 50;
    HP = 3;
    if (!font.loadFromFile("C:\\Users\\Jarek\\Desktop\\c++\\Arkanoid\\bin\\Debug\\arial.ttf")) abort();
    health.setFont(font);
    health.setCharacterSize(30);
    health.setPosition(20, 760);
    health.setFillColor(sf::Color::White);
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
    movey = -1;
}
void ArkanoidModel::draw(sf::RenderWindow &win){
    int i = HP;
    std::string tmp;
    sprintf((char*)tmp.c_str(), "%d", i);
    std::string str = tmp.c_str(); // fragment z zamian¹ int na string zaczerpniêty z: https://4programmers.net/C/Konwersje_int_na_string_i_string_na_int#c-ostringstream
    health.setString("HP: " + str);
    win.draw(background);
    for (int i = 0; i < wall.size(); ++i){
        win.draw(wall[i]);
    }
    for (int i = 0; i < bricks.size(); ++i){
        win.draw(bricks[i]);
    }
    win.draw(platform);
    win.draw(ball);
    win.draw(health);
}
void ArkanoidModel::moveBall(){
    ballx =  ball.getPosition().x;
    bally = ball.getPosition().y;
    if (ballx > 785 || ballx < 15) movex = -movex;
    if (bally >799 || bally < 15) movey= -movey;
    if (ballx < 1) movey = -movey;
    ball.move(movex, movey);
    Sleep(1);
}
void ArkanoidModel::movePlatform(int x){
    if (x == 1 && platform.getPosition().x > 15) platform.move(-a , 0);
    if (x == 2 && platform.getPosition().x < 700) platform.move (a, 0);
}
void ArkanoidModel::boom(){
    int x;
    int y;
    if (ball.getGlobalBounds().intersects(platform.getGlobalBounds())){
        int platHit;
        platHit = ball.getPosition().x - platform.getPosition().x;
        if (platHit > 0 && platHit < 46){
          movey = -movey;
          movex = -movex;
          ball.move(movex, movey);
        }
        if (platHit > 45 && platHit < 90){
          movey = -movey;
          ball.move(movex, movey);
        }
    }
    for (int i = 0; i < bricks.size(); ++i){
        if (ball.getGlobalBounds().intersects(bricks[i].getGlobalBounds())){
            x = ball.getPosition().x;
            y = ball.getPosition().y;
            if (x % 35 == 0) movex= - movex;
            if (y % 20 == 0) movey = - movey;
            if ((x+10)%35 == 0) movex = -movex;
            if ((y+10)%20 == 0) movey = -movey;
            bricks.erase(bricks.begin() + i);
            score++;
            ball.move(movex, movey);
        }
    }
    if (ball.getPosition().y > 798){
        ball.setPosition(600,600);
        Sleep(1000);
        movex = 1;
        movey = -1;
        HP--;
    }
}
bool ArkanoidModel::isFinished(){
    if (HP == 0) abort();//return true;
    return false;
}
std::vector<sf::RectangleShape> ArkanoidModel::getBricks(){
    return bricks;
}
std::vector <sf::Sprite> ArkanoidModel::getWall(){
    return wall;
}
sf::Sprite ArkanoidModel::getBall(){
    return ball;
}
sf::Sprite ArkanoidModel::getPlatform(){
    return platform;
}
sf::Sprite ArkanoidModel::getBackground(){
    return background;
}
int ArkanoidModel::getHP(){
    return HP;
}
