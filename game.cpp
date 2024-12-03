#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QImage>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"

Game::Game(QWidget *parent):
    QGraphicsView(parent), lvl_no(1)
{
    const int WIDTH  = 1000;
    const int HEIGHT =  650;
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    setBackgroundBrush(QBrush(QImage(":/imgs/sky.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH, HEIGHT);

    ground = new QGraphicsPixmapItem(QPixmap(":/imgs/full-ground.png"));
    ground->setPos(0, HEIGHT - ground->boundingRect().height());
    scene->addItem(ground);

    clouds = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds.png"));
    clouds->setPos(130, 50);
    scene->addItem(clouds);

    clouds2 = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds2.png"));
    clouds2->setPos(200, 0);
    scene->addItem(clouds2);

    clouds3 = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds3.png"));
    clouds3->setPos(600, 150);
    scene->addItem(clouds3);

    int ground_level = ground->y();

    player = new Player();
    player->setPos(0, ground_level - player->boundingRect().height() + 5);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    health = new Health(5);
    health->setPos(2, 2);
    scene->addItem(health);
    player->set_health(health);

    score = new Score();
    scene->addItem(score);
    score->setPos(5, health->sceneBoundingRect().y() + health->sceneBoundingRect().height() + 5);
    player->set_score(score);

    level_completed_window = new LevelCompletedWindow();
    player->set_level_completed_window(level_completed_window);
    connect(level_completed_window, &LevelCompletedWindow::wants_to_continue, this, &Game::advance_level);

    game_completed_window = new GameCompletedWindow();

    lvl_text = new QGraphicsTextItem("Level: 1");
    lvl_text->setFont(QFont("Calibri", 24));
    lvl_text->setPos(0, score->y() + score->boundingRect().height());
    scene->addItem(lvl_text);

    lvl = new Level1(scene, ground, clouds, clouds2, clouds3);
    lvl->update_scene();
    player->set_level(lvl);

}

void Game::advance_level(){
    ++lvl_no;
    lvl_text->setPlainText("Level: " + QString::number(lvl_no));
    lvl->remove_items();
    const int HEIGHT =  650;
    ground->setPos(0, HEIGHT - ground->boundingRect().height());
    clouds->setPos(130, 50);
    clouds2->setPos(200, 0);
    clouds3->setPos(600, 150);
    player->setPos(0, ground->y() - player->boundingRect().height() + 5);
    player->setFocus();

    delete lvl;
    if(lvl_no == 2)
        lvl = new Level2(scene, ground, clouds, clouds2, clouds3);
    else if(lvl_no == 3)
        lvl = new Level3(scene, ground, clouds, clouds2, clouds3);
    else if(lvl_no == 4)
        lvl = new Level4(scene, ground, clouds, clouds2, clouds3);
    else{
        player->set_game_completed_window(game_completed_window);
        lvl = new Level5(scene, ground, clouds, clouds2, clouds3);
    }

    lvl->update_scene();
    player->set_level(lvl);
    delete level_completed_window;
    level_completed_window = new LevelCompletedWindow();
    player->set_level_completed_window(level_completed_window);
    connect(level_completed_window, &LevelCompletedWindow::wants_to_continue, this, &Game::advance_level);
}
