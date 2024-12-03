#ifndef LEVEL4_H
#define LEVEL4_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "platform.h"

class Level4 : public LevelClass
{
public:
    Level4(QGraphicsScene *scene, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
           QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void update_scene() override;
    void remove_items() override;
    void move(int) override;

    Platform *platform1, *platform2, *platform3, *platform4, *platform5;
    Spikes *spikes1, *spikes2, *spikes3, *spikes4, *spikes5;
    CoinsPack *cpack1, *cpack2, *cpack3, *cpack4, *cpack5, *cpack6;
};

#endif // LEVEL4_H