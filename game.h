#ifndef GAME_H
#define GAME_H
#include"sounds.h"

#include<SFML/Graphics.hpp>

#include"level_menu.h"

#include<string>
#include<vector>
#include<iostream>
using namespace sf;

class game : public sounds
{
private:


    const double SCREEN_WIDTH = 800;
    const double SCREEN_HEIGH = 600;
    const int borderLeft = 140;
    const int borderRight = 660;
    const int racerWidth = 40;
    const int racerHeight = 70;


    sf::RenderWindow app;

    Texture background, gascan, checkerboard, gameover;

    sf::Texture bullet;
    sf::Sprite projectile1, projectile2;

    sf::Texture racer;
    sf::Sprite Racer;

    sf::Texture obs1, obs2, obs3, obs4, obs5;
    sf::Sprite Obsa1, Obsa2, Obsb1, Obsb2, Obs3, Obs4;
    float Obs1aX, Obs1aY, Obs1bX, Obs1bY, Obs2aX, Obs2aY, Obs2bX, Obs2bY, Obs3X, Obs3Y, Obs4X, Obs4Y, GasX, GasY;

    int score = 0;

    double gameSpeed = 0.1;

    double RacerX, RacerY;

    double BackgroundY1 = 0;
    double BackgroundY2 = -600;

    double lapY = -200.0f;  // sprite of the checker board

    std::string stringscore = "";
    std::string engine = "";

    //Set Bullet Timer
    float Timer = 0.f;

    //Set Gas Timer
    int GasTimer = 0.f;

    float val = 0.75;

    int some_value_of_score;

    int bullet_fired_count = 0;

    float fuelamount = 200;
public:
    game();



    int getRandomNumber(int a, int b);

    int gameOver(sf::RenderWindow&);

    ~game() {};


};






#endif // GAME_H
