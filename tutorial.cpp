#include "tutorial.h"

tutorial::tutorial()
{
    tutorial_window.create(VideoMode(800, 600), "Tutorial");

    font_tutorial.loadFromFile("font/xirod.ttf");

    t1.setFont(font_tutorial);
    t2.setFont(font_tutorial);
    t3.setFont(font_tutorial);
    t4.setFont(font_tutorial);
    t5.setFont(font_tutorial);
    t6.setFont(font_tutorial);
    t7.setFont(font_tutorial);
    t8.setFont(font_tutorial);


    t1.setCharacterSize(20);
    t1.setPosition(Vector2f(300.f, 0.f));
    t1.setString("TUTORIAL");
    t1.setStyle(sf::Text::Bold);
    t1.setFillColor(sf::Color::White);



    t2.setCharacterSize(20);
    t2.setPosition(Vector2f(100.f, 100.f));
    t2.setString("PRESS 'A' TO MOVE THE CAR TO THE LEFT .");
    t2.setFillColor(sf::Color(102, 0, 0));


    t3.setCharacterSize(20);
    t3.setPosition(sf::Vector2f(100.f, 200.f));
    t3.setString("PRESS 'D' TO MOVE THE CAR TO THE RIGHT .");
    t3.setFillColor(sf::Color(102, 0, 0));

    t4.setCharacterSize(20);
    t4.setPosition(Vector2f(100.f, 300.f));
    t4.setString("PRESS 'W' TO MOVE THE CAR FORWARD .");
    t4.setFillColor(sf::Color(102, 0, 0));


    t5.setCharacterSize(20);
    t5.setPosition(Vector2f(100.f, 400.f));
    t5.setString("PRESS 'S' TO MOVE THE CAR BACKWARD .");
    t5.setFillColor(sf::Color(102, 0, 0));



    while (tutorial_window.isOpen())
    {
        sf::Event e_tutorial;
        while (tutorial_window.pollEvent(e_tutorial))
        {
            if (e_tutorial.type == sf::Event::Closed)
            {
                tutorial_window.close();
            }
            if (e_tutorial.type == sf::Event::KeyPressed)
            {
                if (e_tutorial.key.code == sf::Keyboard::Enter)
                {
                    tutorial_window.close();
                    main_menu m1;

                }

            }
        }


        tutorial_window.clear();
        tutorial_window.draw(t1);
        tutorial_window.draw(t2);
        tutorial_window.draw(t3);
        tutorial_window.draw(t4);
        tutorial_window.draw(t5);
        tutorial_window.display();
    }
}