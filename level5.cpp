#include "level5.h"
#include "coin.h"
#include <cstdlib>

Level5::Level5(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
               QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level5::update_scene()
{
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();

    platform1 = new Platform(Platform::SHORT);
    platform1->setPos(200, ground_level - platform1->boundingRect().height() - 60);
    this->scene->addItem(platform1);

    coinpack1 = new CoinsPack(3);
    coinpack1->setPos(platform1->x() + 30, platform1->y() - coin_height - 3);
    this->scene->addItem(coinpack1);

    spikes1 = new Spikes();
    spikes1->setPos(platform1->x() + 100, ground_level - spikes1->boundingRect().height() + 5);
    this->scene->addItem(spikes1);

    platform2 = new Platform(Platform::LONG);
    platform2->setPos(platform1->x() + 300, platform1->y() - 100);
    this->scene->addItem(platform2);

    coinpack2 = new CoinsPack(5);
    coinpack2->setPos(platform2->x() + 220, platform2->y() - coin_height - 3);
    this->scene->addItem(coinpack2);

    spikes2 = new Spikes();
    spikes2->setPos(platform2->x() + 100, platform2->y() - spikes2->boundingRect().height() + 5);
    this->scene->addItem(spikes2);

    platform3 = new Platform(Platform::SHORT);
    platform3->setPos(platform2->x() + 400, platform2->y() - 150);
    this->scene->addItem(platform3);

    coinpack3 = new CoinsPack(4);
    coinpack3->setPos(platform3->x() + 120, platform3->y() - coin_height - 3);
    this->scene->addItem(coinpack3);

    spikes3 = new Spikes();
    spikes3->setPos(platform3->x() + 30, platform3->y() - spikes3->boundingRect().height() + 5);
    this->scene->addItem(spikes3);

    platform4 = new Platform(Platform::SHORT);
    platform4->setPos(platform3->x() + 250, platform3->y() + 50);
    this->scene->addItem(platform4);

    coinpack4 = new CoinsPack(3);
    coinpack4->setPos(platform4->x() + 120, platform4->y() - coin_height - 3);
    this->scene->addItem(coinpack4);

    spikes4 = new Spikes();
    spikes4->setPos(platform4->x() + 40, platform4->y() - spikes4->boundingRect().height() + 5);
    this->scene->addItem(spikes4);

    platform5 = new Platform(Platform::SHORT);
    platform5->setPos(platform4->x() + 250, platform4->y() - 50);
    this->scene->addItem(platform5);

    coinpack5 = new CoinsPack(3);
    coinpack5->setPos(platform5->x() + 120, platform5->y() - coin_height - 3);
    this->scene->addItem(coinpack5);

    spikes5 = new Spikes();
    spikes5->setPos(platform5->x() + 40, platform5->y() - spikes5->boundingRect().height() + 5);
    this->scene->addItem(spikes5);

    platform6 = new Platform(Platform::SHORT);
    platform6->setPos(platform5->x() + 250, platform5->y() + 50);
    this->scene->addItem(platform6);

    coinpack6 = new CoinsPack(3);
    coinpack6->setPos(platform6->x() + 120, platform6->y() - coin_height - 3);
    this->scene->addItem(coinpack6);

    spikes6 = new Spikes();
    spikes6->setPos(platform6->x() + 40, platform6->y() - spikes6->boundingRect().height() + 5);
    this->scene->addItem(spikes6);

    platform7 = new Platform(Platform::LONG);
    platform7->setPos(platform6->x() + 300, ground_level - platform7->boundingRect().height() - 100);
    this->scene->addItem(platform7);

    coinpack7 = new CoinsPack(10);
    coinpack7->setPos(platform7->x() + 200, platform7->y() - coin_height - 3);
    this->scene->addItem(coinpack7);

    spikes7 = new Spikes();
    spikes7->setPos(platform7->x() + 50, platform7->y() - spikes7->boundingRect().height() + 5);
    this->scene->addItem(spikes7);

    spikes8 = new Spikes();
    spikes8->setPos(platform7->x() + 100, platform7->y() - spikes8->boundingRect().height() + 5);
    this->scene->addItem(spikes8);

    checkpoint = new CheckPoint();
    checkpoint->setPos(platform7->x() + 600, ground_level - checkpoint->boundingRect().height() + 5);
    this->scene->addItem(checkpoint);
}

void Level5::move(int dx)
{
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < this->scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);
    platform1->setX(platform1->x() + dx);
    platform2->setX(platform2->x() + dx);
    platform3->setX(platform3->x() + dx);
    platform4->setX(platform4->x() + dx);
    platform5->setX(platform5->x() + dx);
    platform6->setX(platform6->x() + dx);
    platform7->setX(platform7->x() + dx);
    spikes1->setX(spikes1->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    spikes3->setX(spikes3->x() + dx);
    spikes4->setX(spikes4->x() + dx);
    spikes5->setX(spikes5->x() + dx);
    spikes6->setX(spikes6->x() + dx);
    spikes7->setX(spikes7->x() + dx);
    spikes8->setX(spikes8->x() + dx);
    coinpack1->setX(coinpack1->x() + dx);
    coinpack2->setX(coinpack2->x() + dx);
    coinpack3->setX(coinpack3->x() + dx);
    coinpack4->setX(coinpack4->x() + dx);
    coinpack5->setX(coinpack5->x() + dx);
    coinpack6->setX(coinpack6->x() + dx);
    coinpack7->setX(coinpack7->x() + dx);
    checkpoint->setX(checkpoint->x() + dx);
}

void Level5::remove_items()
{
    this->scene->removeItem(platform1);
    delete platform1;
    this->scene->removeItem(platform2);
    delete platform2;
    this->scene->removeItem(platform3);
    delete platform3;
    this->scene->removeItem(platform4);
    delete platform4;
    this->scene->removeItem(platform5);
    delete platform5;
    this->scene->removeItem(platform6);
    delete platform6;
    this->scene->removeItem(platform7);
    delete platform7;
    this->scene->removeItem(spikes1);
    delete spikes1;
    this->scene->removeItem(spikes2);
    delete spikes2;
    this->scene->removeItem(spikes3);
    delete spikes3;
    this->scene->removeItem(spikes4);
    delete spikes4;
    this->scene->removeItem(spikes5);
    delete spikes5;
    this->scene->removeItem(spikes6);
    delete spikes6;
    this->scene->removeItem(spikes7);
    delete spikes7;
    this->scene->removeItem(spikes8);
    delete spikes8;
    this->scene->removeItem(coinpack1);
    delete coinpack1;
    this->scene->removeItem(coinpack2);
    delete coinpack2;
    this->scene->removeItem(coinpack3);
    delete coinpack3;
    this->scene->removeItem(coinpack4);
    delete coinpack4;
    this->scene->removeItem(coinpack5);
    delete coinpack5;
    this->scene->removeItem(coinpack6);
    delete coinpack6;
    this->scene->removeItem(coinpack7);
    delete coinpack7;
    this->scene->removeItem(checkpoint);
    delete checkpoint;
}
