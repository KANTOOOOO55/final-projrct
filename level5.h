#ifndef LEVEL5_H
#define LEVEL5_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "platform.h"

class Level5 : public LevelClass
{
public:
    Level5(QGraphicsScene *scene, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
           QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void update_scene() override;
    void remove_items() override;
    void move(int) override;

    Platform *platform1, *platform2, *platform3, *platform4,
             *platform5, *platform6, *platform7, *platform8;

    Spikes *spikes1, *spikes2, *spikes3, *spikes4,
           *spikes5, *spikes6, *spikes7, *spikes8, *spikes9, *spikes10;

    CoinsPack *coinpack1, *coinpack2, *coinpack3, *coinpack4,
              *coinpack5, *coinpack6, *coinpack7, *coinpack8;

};

#endif // LEVEL5_H
