#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "player.h"
#include "spikes.h"
#include "coin.h"
#include "checkpoint.h"
#include <QDebug>
#include "levelcompletedwindow.h"
#include "platform.h"

Player::Player(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent),
    is_reversed(false),
    is_upgraded(false),
    is_jumping(false),
    is_on_platform(false),
    gravity_timer(new QTimer(this)),
    upgrade_timer(new QTimer(this)),
    vertical_velocity(0),
    level_completed_window(nullptr),
    game_completed_window(nullptr)
{
    setPixmap(QPixmap(":/imgs/player.png"));
    connect(gravity_timer, &QTimer::timeout, this, &Player::apply_gravity);
    gravity_timer->start(30);
}

void Player::set_health(Health *new_health){
    health = new_health;
}
void Player::set_score(Score *new_score){
    score = new_score;
}
void Player::set_level(LevelClass *level){
    lvl = level;
}
void Player::set_level_completed_window(LevelCompletedWindow *window){
    level_completed_window = window;
}
void Player::set_game_completed_window(GameCompletedWindow *window){
    game_completed_window = window;
}

void Player::check_spikes_collision(){
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions) {
        Spikes *spike = dynamic_cast<Spikes *>(item);
        if (spike) {
            int dx = spike->boundingRect().width() + boundingRect().width() + 1;
            if(is_upgraded){    // don't decrease health
                move_right(dx);
                break;
            }
            health->decrease_health();
            if(is_reversed)
                move_left(dx);
            else
                move_right(dx);
            break;
        }
    }
}

void Player::check_coin_collision(){
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions) {
        Coin *coin = dynamic_cast<Coin *>(item);
        if (coin) {
            score->increase_score();
            scene()->removeItem(coin);
            delete coin;
            int coins_no = score->get_current_score();
            if(coins_no == 100)
                upgrade();
            break;
        }
    }
}

void Player::check_checkpoint_collision(){
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions) {
        CheckPoint *checkpoint = dynamic_cast<CheckPoint *>(item);
        if (checkpoint){
            if(game_completed_window)
                game_completed_window->exec();
            else
                level_completed_window->exec();
            break;
        }
    }
}

void Player::check_platform_collision() {
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions) {
        Platform *platform = dynamic_cast<Platform *>(item);
        if (platform) {
            if (y() + boundingRect().height() >= platform->y() + 5 && vertical_velocity > 0) {
                vertical_velocity = 0;
                is_jumping = false;
                is_on_platform = true;
                setY(platform->y() - boundingRect().height());
            }
            return;
        }
    }
    is_on_platform = false;
}

void Player::ckeck_collisions(){
    check_spikes_collision();
    check_coin_collision();
    check_checkpoint_collision();
    check_platform_collision();
}
void Player::move_left(int dx){
    if(x() <= 0)
        return;
    if(!is_upgraded && !is_reversed){
        setPixmap(QPixmap(":/imgs/reversed-player.png"));
        is_reversed = true;
    }
    if(x() + boundingRect().width() < scene()->width() / 2 || lvl->ground->x() == 0)
        setX(x() - dx);
    else
        lvl->move(dx);
    if(!is_jumping && !is_on_platform)
        setY(y()-2);
}
void Player::move_right(int dx){
    if(x() + boundingRect().width() >= scene()->width())
        return;
    if(!is_upgraded && is_reversed){
        setPixmap(QPixmap(":/imgs/player.png"));
        is_reversed = false;
    }
    if(x() + boundingRect().width() < scene()->width() / 2)
        setX(x() + dx);
    else
        lvl->move(-dx);
    if(!is_jumping && !is_on_platform)
        setY(y()-2);
}
void Player::keyPressEvent(QKeyEvent *event){
    int dx = 20;    // speed
    if (event->key() == Qt::Key_Left){
        move_left(dx);
        ckeck_collisions();
    }
    else if (event->key() == Qt::Key_Right){
        move_right(dx);
        ckeck_collisions();
    }
    else if (event->key() == Qt::Key_Space && !is_jumping) {
        vertical_velocity = -20;
        is_jumping = true;
        check_platform_collision();
    }
}

void Player::apply_gravity() {
    if (is_on_platform) {
        vertical_velocity = 0;
        return;
    }
    vertical_velocity += 1;
    int new_y = y() + vertical_velocity;
    int ground_level = 590;
    if (new_y >= ground_level - this->boundingRect().height() + 5) {
        new_y = ground_level - this->boundingRect().height() + 5;
        vertical_velocity = 0;
        is_jumping = false;
    }
    setPos(x(), new_y);
    ckeck_collisions();
}

void Player::upgrade() {
    int SECONDS_NO = 30;
    int MILLISECONDS_NO_IN_ONE_SECOND = 1000;
    int UPGRADE_DURATION = SECONDS_NO * MILLISECONDS_NO_IN_ONE_SECOND; // 30000 ms = 30 seconds
    setPixmap(QPixmap(":/imgs/upgraded.png"));
    is_upgraded = true;
    connect(upgrade_timer, &QTimer::timeout, this, &Player::reverse_upgrade);
    upgrade_timer->start(UPGRADE_DURATION);
}

void Player::reverse_upgrade() {
    is_upgraded = false;
    setPixmap(QPixmap(":/imgs/player.png"));
    is_reversed = false;
}
