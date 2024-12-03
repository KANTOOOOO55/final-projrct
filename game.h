#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "health.h"
#include "score.h"
#include "levelclass.h"
#include "levelcompletedwindow.h"

class Game: public QGraphicsView {
public:
    Game(QWidget *parent = nullptr);
private slots:
    void advance_level();
private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *ground;
    QGraphicsPixmapItem *clouds, *clouds2, *clouds3;
    Player *player;
    Health *health;
    Score *score;
    LevelCompletedWindow *level_completed_window;
    GameCompletedWindow *game_completed_window;
    QGraphicsTextItem *lvl_text;
    int lvl_no;
    LevelClass *lvl;
};

#endif // GAME_H
