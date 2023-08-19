#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include<iostream>
#include<cstdlib>
#include <string>
#include<SFML/Graphics.hpp>

#include"level_menu.h"
#include"tutorial.h"

using namespace sf;

class main_menu
{
private:
    sf::Sprite sprite_main_menu_bg;
    sf::Texture texture_main_menu_bg;

    sf::RenderWindow mainmenu;

    sf::RectangleShape rect[3];

    sf::Font main_menu_font;

    sf::Text title;

    sf::Text main_menu_option_text[3];

    int selected_item_no = 0;
    int prev_selected_item_no;
public:

    main_menu();

    ~main_menu() {};
};


#endif
