#ifndef LEVEL3_H
#define LEVEL3_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "platform.h"

class Level3 : public LevelClass
{
public:
    Level3(QGraphicsScene *scene, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
           QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void update_scene() override;
    void remove_items() override;
    void move(int) override;

    Platform *platform1, *platform2, *platform3, *platform4;
    Spikes *spikes1, *spikes2, *spikes3, *spikes4;
    CoinsPack *cpack1, *cpack2, *cpack3, *cpack4, *cpack5, *cpack6;
};

#endif // LEVEL3_H
