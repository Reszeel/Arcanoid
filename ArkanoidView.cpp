#include "ArkanoidView.h"
#include "ArkanoidModel.h"
ArkanoidView::ArkanoidView(ArkanoidModel &m):model(m){}
void ArkanoidView::draw(sf::RenderWindow &win){
    win.draw(ArkanoidModel::background);

    for (int i = 0; i < ArkanoidModel::wall.size(); ++i){
        win.draw(ArkanoidModel::wall[i]);
    }
    for (int i = 0; i < ArkanoidModel::bricks.size(); ++i){
        win.draw(ArkanoidModel::bricks[i]);
    }
    win.draw(ArkanoidModel::platform);
    win.draw(ArkanoidModel::ball);
}


