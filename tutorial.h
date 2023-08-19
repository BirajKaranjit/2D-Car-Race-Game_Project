#ifndef TUTORIAL_H
#define TUTORIAL_H


#include<SFML/Graphics.hpp>
#include"main_menu.h"

using namespace sf;

class tutorial
{
private:
    RenderWindow tutorial_window;
    Text t1, t2, t3, t4, t5, t6, t7, t8;
    Font font_tutorial;

public:
    tutorial();

    ~tutorial() {};

};

#endif // TUTORIAL_H