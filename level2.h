#ifndef LEVEL2_H
#define LEVEL2_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "platform.h"

class Level2 : public LevelClass
{
public:
    Level2(QGraphicsScene *scene, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
           QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void update_scene() override;
    void remove_items() override;
    void move(int) override;

    Platform *platform1;
    Spikes *spikes1, *spikes2, *spikes3, *spikes4, *spikes5;
    CoinsPack *cpack1, *cpack2, *cpack3, *cpack4,
              *cpack5, *cpack6, *cpack7, *cpack8;
};

#endif // LEVEL2_H