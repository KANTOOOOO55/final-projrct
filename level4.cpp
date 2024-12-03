#include "level4.h"
#include "coin.h"
#include <cstdlib>

Level4::Level4(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
               QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level4::update_scene(){
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();

    cpack1 = new CoinsPack(5);
    this->scene->addItem(cpack1);
    cpack1->setPos(150, ground_level - coin_height - 3);

    platform1 = new Platform(Platform::SHORT);
    platform1->setPos(400, ground_level - platform1->boundingRect().height() - 80);
    this->scene->addItem(platform1);

    cpack2 = new CoinsPack(3);
    cpack2->setPos(platform1->x() + 40, platform1->y() - coin_height - 3);
    this->scene->addItem(cpack2);

    spikes1 = new Spikes();
    spikes1->setPos(700, ground_level - spikes1->boundingRect().height() + 5);
    this->scene->addItem(spikes1);

    platform2 = new Platform(Platform::LONG);
    platform2->setPos(1000, ground_level - platform2->boundingRect().height() - 120);
    this->scene->addItem(platform2);

    cpack3 = new CoinsPack(7);
    cpack3->setPos(platform2->x() + 50, platform2->y() - coin_height - 3);
    this->scene->addItem(cpack3);

    spikes2 = new Spikes();
    spikes2->setPos(platform2->x() + platform2->boundingRect().width() - 100,
                    platform2->y() - spikes2->boundingRect().height() + 5);
    this->scene->addItem(spikes2);

    platform3 = new Platform(Platform::SHORT);
    platform3->setPos(1600, platform2->y() - platform3->boundingRect().height() - 90);
    this->scene->addItem(platform3);

    spikes3 = new Spikes();
    spikes3->setPos(platform3->x() + platform3->boundingRect().width() / 2,
                    platform3->y() - spikes3->boundingRect().height() + 5);
    this->scene->addItem(spikes3);

    cpack4 = new CoinsPack(3);
    cpack4->setPos(platform3->x() + 10, platform3->y() - coin_height - 5);
    this->scene->addItem(cpack4);

    platform4 = new Platform(Platform::LONG);
    platform4->setPos(platform3->x() + 400, ground_level - platform4->boundingRect().height() - 70);
    this->scene->addItem(platform4);

    spikes4 = new Spikes();
    spikes4->setPos(platform4->x() + 60, platform4->y() - spikes4->boundingRect().height() + 5);
    this->scene->addItem(spikes4);

    cpack5 = new CoinsPack(5);
    cpack5->setPos(platform4->x() + 150, platform4->y() - coin_height - 3);
    this->scene->addItem(cpack5);

    spikes5 = new Spikes();
    spikes5->setPos(platform4->x() + platform4->boundingRect().width() - 100,
                    ground_level - spikes5->boundingRect().height() + 5);
    this->scene->addItem(spikes5);

    checkpoint = new CheckPoint();
    checkpoint->setPos(2500, ground_level - checkpoint->boundingRect().height() + 5);
    this->scene->addItem(checkpoint);
}

void Level4::move(int dx){
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < this->scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);
    cpack1->setX(cpack1->x() + dx);
    platform1->setX(platform1->x() + dx);
    cpack2->setX(cpack2->x() + dx);
    spikes1->setX(spikes1->x() + dx);
    platform2->setX(platform2->x() + dx);
    cpack3->setX(cpack3->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    platform3->setX(platform3->x() + dx);
    spikes3->setX(spikes3->x() + dx);
    cpack4->setX(cpack4->x() + dx);
    platform4->setX(platform4->x() + dx);
    spikes4->setX(spikes4->x() + dx);
    cpack5->setX(cpack5->x() + dx);
    spikes5->setX(spikes5->x() + dx);
    checkpoint->setX(checkpoint->x() + dx);
}

void Level4::remove_items(){
    scene->removeItem(cpack1);
    delete cpack1;
    scene->removeItem(platform1);
    delete platform1;
    scene->removeItem(cpack2);
    delete cpack2;
    scene->removeItem(spikes1);
    delete spikes1;
    scene->removeItem(platform2);
    delete platform2;
    scene->removeItem(cpack3);
    delete cpack3;
    scene->removeItem(spikes2);
    delete spikes2;
    scene->removeItem(platform3);
    delete platform3;
    scene->removeItem(spikes3);
    delete spikes3;
    scene->removeItem(cpack4);
    delete cpack4;
    scene->removeItem(platform4);
    delete platform4;
    scene->removeItem(spikes4);
    delete spikes4;
    scene->removeItem(cpack5);
    delete cpack5;
    scene->removeItem(spikes5);
    delete spikes5;
    scene->removeItem(checkpoint);
    delete checkpoint;
}
