#include "level_menu.h"


level_menu::level_menu()
{
    level_window.create(VideoMode(800, 600), "Level");
    font_level.loadFromFile("font/xirod.ttf");
    t1.setFont(font_level);
    t2.setFont(font_level);
    t1.setPosition(Vector2f(300.f, 0.f));
    t1.setStyle(sf::Text::Bold);

    level++;

    t1.setString("Level " + std::to_string(level));
    t2.setPosition(Vector2f(300.f, 500.f));
    t2.setCharacterSize(20);
    t2.setString("Press Enter to proceed");

    t5.setFont(font_level);
    t5.setPosition(270.f, 70.f);
    t5.setCharacterSize(25);
    t5.setFillColor(sf::Color::White);
    t5.setString("INSTRUCTION");

    t3.setFont(font_level);

    t3.setCharacterSize(20);
    t3.setFillColor(sf::Color::White);

    t4.setFont(font_level);

    t4.setCharacterSize(20);
    t4.setFillColor(sf::Color::White);

    if (level == 1)
    {
        t3.setPosition(250.f, 200.f);
        t4.setPosition(50.f, 250.f);
        t3.setString("This level is easy .");
        t4.setString("Sit tight & drive through the traffic .");


    }

    if (level == 2)
    {
        t3.setPosition(170.f, 200.f);
        t4.setPosition(170.f, 250.f);
        t3.setString("There is a Fuel Shortage !!!");
        t4.setString("Do not shoot bullet too much");


    }

    if (level == 3)
    {
        t3.setPosition(180.f, 200.f);
        t4.setPosition(50.f, 250.f);
        t3.setString("Oh no , The Engine is broken .");
        t4.setString("Press 'A' to move left and 'D' to move right.");


    }


    while (level_window.isOpen())
    {
        sf::Event e;
        while (level_window.pollEvent(e))
        {

            if (e.type == sf::Event::Closed)
            {
                level_window.close();
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::Enter)
                {

                    level_window.close();

                    s2.play_start_sound();

                    game g;



                }

            }
        }


        level_window.clear();
        level_window.draw(t1);
        level_window.draw(t2);
        level_window.draw(t5);
        level_window.draw(t3);
        level_window.draw(t4);
        level_window.display();
    }
}
int level_menu::level=0;
