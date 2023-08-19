#include"main_menu.h"

main_menu::main_menu()
{
    texture_main_menu_bg.loadFromFile("cars/home.jpg");
    sprite_main_menu_bg.setTexture(texture_main_menu_bg);


    main_menu_font.loadFromFile("font/xirod.ttf");
    title.setFont(main_menu_font);
    title.setCharacterSize(50);
    title.setFillColor(Color::Red);
    title.setStyle(Text::Bold);
    title.setString("2D Car Game");
    title.setPosition(Vector2f(170.f, 30.f));   //from top left position 170 right and 30 units down

    sprite_main_menu_bg.setPosition(170.f, 80.f);

    mainmenu.create(VideoMode(800, 600), "Main Menu");


    for (int i = 0; i < 3; i++)
    {
        main_menu_option_text[i].setFont(main_menu_font);
        rect[i].setSize(Vector2f(270, 50));
        rect[i].setFillColor(Color::Transparent);
        rect[i].setPosition(Vector2f(300, 50));
        rect[i].setOutlineColor(Color(102, 0, 0));
        rect[i].setOutlineThickness(5);
    }

    main_menu_option_text[0].setFillColor(Color(102,0,0));
    rect[0].setFillColor(Color::Black);
    main_menu_option_text[1].setFillColor(Color::White);
    main_menu_option_text[2].setFillColor(Color::White);

    main_menu_option_text[0].setString("PLAY");
    main_menu_option_text[1].setString("TUTORIAL");
    main_menu_option_text[2].setString("QUIT");

    main_menu_option_text[0].setPosition(Vector2f(170.f, 437.f));
    rect[0].setPosition(Vector2f(100.f, 430.f));
    main_menu_option_text[1].setPosition(Vector2f(430.f, 437.f));
    rect[1].setPosition(Vector2f(420.f, 430.f));
    rect[1].setOutlineColor(Color::White);
    main_menu_option_text[2].setPosition(Vector2f(335.f, 517.f));
    rect[2].setPosition(Vector2f(250.f, 510.f));
    rect[2].setOutlineColor(Color::White);
    ////////////////////////////////////////////////Loop for checking if the main menu window is Open//////////////////////////////////////
    while (mainmenu.isOpen())
    {

        sf::Event e_mainmenu;

        while (mainmenu.pollEvent(e_mainmenu))
        {
            ///////////event closed///////////////////////
            if (e_mainmenu.type == sf::Event::Closed)
            {
                mainmenu.close();
            }


            if (e_mainmenu.type == sf::Event::KeyReleased)
            {
                switch (e_mainmenu.key.code)
                {

                case sf::Keyboard::Down:
                {
                    prev_selected_item_no = selected_item_no;
                    selected_item_no = selected_item_no + 1;

                    if (selected_item_no > 2)
                    {
                        selected_item_no = 0;
                        prev_selected_item_no = 2;

                    }

                    main_menu_option_text[selected_item_no].setFillColor(Color(102, 0, 0));
                    rect[selected_item_no].setFillColor(Color::Black);
                    rect[selected_item_no].setOutlineColor(Color(102, 0, 0));
                    main_menu_option_text[prev_selected_item_no].setFillColor(sf::Color::White);
                    rect[prev_selected_item_no].setFillColor(Color::Transparent);
                    rect[prev_selected_item_no].setOutlineColor(sf::Color::White);

                    break;
                }
                }
            }

            if (e_mainmenu.type == Event::KeyPressed)
            {
                if (e_mainmenu.key.code == Keyboard::Enter)
                {
                    if (selected_item_no == 0)
                    {
                        mainmenu.close();
                        level_menu l1;
                    }
                    if (selected_item_no == 1)
                    {
                        mainmenu.close();
                        tutorial t1;
                    }
                    if (selected_item_no == 2)
                    {
                        mainmenu.close();
                    }
                }
            }

        }

        mainmenu.clear(sf::Color::Black);
        mainmenu.draw(title);
        mainmenu.draw(sprite_main_menu_bg);
        mainmenu.draw(rect[0]);
        mainmenu.draw(rect[1]);
        mainmenu.draw(rect[2]);
        mainmenu.draw(main_menu_option_text[0]);
        mainmenu.draw(main_menu_option_text[1]);
        mainmenu.draw(main_menu_option_text[2]);
        mainmenu.display();
    }

}
