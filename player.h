#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include "health.h"
#include "score.h"
#include "levelclass.h"
#include "levelcompletedwindow.h"
#include "gamecompletedwindow.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void move_left(int);
    void move_right(int);
    void keyPressEvent(QKeyEvent *event);
    void set_health(Health *);
    void set_score(Score *);
    void set_level(LevelClass *);
    void set_level_completed_window(LevelCompletedWindow *);
    void set_game_completed_window(GameCompletedWindow *);
private:
    bool is_reversed;
    bool is_upgraded;
    bool is_jumping;
    bool is_on_platform;
    QTimer* gravity_timer;
    QTimer* upgrade_timer;
    int vertical_velocity;
    Health *health;
    Score *score;
    LevelClass *lvl;
    LevelCompletedWindow *level_completed_window;
    GameCompletedWindow *game_completed_window;

    void check_spikes_collision();
    void check_coin_collision();
    void check_checkpoint_collision();
    void check_platform_collision();
    void ckeck_collisions();
    void upgrade();
public slots:
    void apply_gravity();
    void reverse_upgrade();
};

#endif // PLAYER_H
