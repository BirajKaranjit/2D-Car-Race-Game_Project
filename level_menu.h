#ifndef LEVEL_MENU_H
#define LEVEL_MENU_H


#include<iostream>

#include "game.h"

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "sounds.h"

using namespace sf;



class level_menu
{
private:
    RenderWindow level_window;
    Text t1, t2, t3, t4, t5;
    Font font_level;


public:
    static int level;

    sounds s2;
    level_menu();

    ~level_menu() {};

};



#endif // LEVEL_MENU_H

