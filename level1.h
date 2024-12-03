#ifndef LEVEL1_H
#define LEVEL1_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "platform.h"

class Level1 : public LevelClass
{
public:
    Level1(QGraphicsScene *scene, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
                                  QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void update_scene() override;
    void remove_items() override;
    void move(int) override;

    Platform *platform1, *platform2, *platform3;
    Spikes *spikes1, *spikes2, *spikes3;
    CoinsPack *cpack1, *cpack2, *cpack3, *cpack4,
              *cpack5, *cpack6, *cpack7, *cpack8;
};

#endif // LEVEL1_H
