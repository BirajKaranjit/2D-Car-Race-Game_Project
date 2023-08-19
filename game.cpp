#pragma once

#include "game.h"
#include"sounds.h"
#include"main_menu.h"
game::game()
{
    int beep_sound = 1;
    app.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Car Racing");
    app.setFramerateLimit(500);

    /*Text level;
            level.setString("Level 1");
    level.setCharacterSize(50);*/


    Obs1aX = getRandomNumber(borderLeft, borderRight);
    Obs2aX = getRandomNumber(borderLeft, borderRight);
    Obs1bX = getRandomNumber(borderLeft, borderRight);
    Obs2bX = getRandomNumber(borderLeft, borderRight);
    Obs3X = getRandomNumber(borderLeft, borderRight);
    Obs4X = getRandomNumber(borderLeft, borderRight);
    Obs1aY = 0, Obs2aY = -100, Obs1bY = -50, Obs2bY = -150, Obs3Y = -200, Obs4Y = -250;
    GasX = getRandomNumber(borderLeft, borderRight);
    GasY = 0;

    //Load all images
    background.loadFromFile("cars/background.png");
    racer.loadFromFile("cars/racer.png");

    obs1.loadFromFile("cars/obs1.png");
    obs2.loadFromFile("cars/obs2.png");
    obs3.loadFromFile("cars/obs3.png");;
    obs4.loadFromFile("cars/obs4.png");
    obs5.loadFromFile("cars/obs5.png");

    bullet.loadFromFile("cars/bullet.png");
    gascan.loadFromFile("cars/gascan.png");

    checkerboard.loadFromFile("cars/checkerboard.png");


    Sprite Background(background), lap(checkerboard), Background1(background), Gameover(gameover), Gas(gascan);

    Racer.setTexture(racer);

    Obsa1.setTexture(obs1);
    Obsa2.setTexture(obs2);

    Obsb1.setTexture(obs5);
    Obsb2.setTexture(obs2);

    Obs3.setTexture(obs3);
    Obs4.setTexture(obs4);

    projectile1.setTexture(bullet);
    projectile2.setTexture(bullet);



    Gas.setScale(Vector2f(0.25, 0.25));

    std::vector<Sprite>projectiles;
    projectiles.push_back(Sprite(projectile1));
    projectiles.push_back(Sprite(projectile2));



    //Set racer and Obs pos
    RacerX = SCREEN_WIDTH / 2;
    RacerY = SCREEN_HEIGH - racerHeight;
    Obs1aX = getRandomNumber(borderLeft, borderRight);
    Obs1bX = getRandomNumber(borderLeft, borderRight);
    Obs2aX = getRandomNumber(borderLeft, borderRight);
    Obs2bX = getRandomNumber(borderLeft, borderRight);
    Obs3X = getRandomNumber(borderLeft, borderRight);
    Obs4X = getRandomNumber(borderLeft, borderRight);
    Obs1aY = 0, Obs1bY = -50, Obs2aY = -100, Obs2bY = -150, Obs3Y = -200, Obs4Y = -300;
    GasX = getRandomNumber(borderLeft, borderRight);
    GasY = 0;




    //Set Fuel bar
    RectangleShape fuelBar, Border;

    fuelBar.setFillColor(Color::Red);
    fuelBar.setPosition(sf::Vector2f(10, 10));
    Border.setPosition(sf::Vector2f(10, 10));
    Border.setOutlineColor(Color::Black);
    Border.setOutlineThickness(5);
    Border.setFillColor(Color::Transparent);
    Border.setSize(sf::Vector2f(200, 50));

    Racer.setPosition(RacerX, RacerY);
    int traffic_sound = 1500;
    //GAME LOOP
    sounds s1;
    while (app.isOpen())
    {
        if (traffic_sound == 1500)
        {
            s1.play_traffic_sound();
            traffic_sound = 0;
        }
        traffic_sound++;
        some_value_of_score = (level_menu::level - 1) * 50 + score;


        projectile1.setScale(Vector2f(0.07, 0.07));
        projectile1.setPosition(Vector2f(5, 0));
        projectile2.setScale(Vector2f(0.07, 0.07));
        projectile2.setPosition(Vector2f(0, 0));
        //Init and count score
        stringscore = "SCORE:" + std::to_string(score);

        //Set car position

        Obsa1.setPosition(Obs1aX, Obs1aY);
        Obsa2.setPosition(Obs2aX, Obs2aY);
        Obsb1.setPosition(Obs1bX, Obs1bY);
        Obsb2.setPosition(Obs2bX, Obs2bY);
        Obs3.setPosition(Obs3X, Obs3Y);
        Obs4.setPosition(Obs4X, Obs4Y);

        //Set Gas position
        Gas.setPosition(GasX, GasY);


        //Create scrolling background
        Background.setPosition(0, BackgroundY1);
        Background1.setPosition(0, BackgroundY2);
        if (BackgroundY2 > 0)
        {
            BackgroundY1 = 0;
            BackgroundY2 = BackgroundY1 - 500;
        }
        BackgroundY1 += val;
        BackgroundY2 += val;



        //create moving fuel bar
        fuelamount > 0 ? fuelamount -= 0.005 : fuelamount = 0;
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {

            if (level_menu::level == 2)
            {
                fuelamount = fuelamount - 0.2;
            }
            else
                fuelamount -= 0.05;
        }

        ////ALARM FOR FUEL AMOUNT//////////////////////////

        if (fuelamount <= 20 && beep_sound == 1)
        {
            beep_sound = 0;
            s1.play_beep_sound();
            std::cout << "BEEP SOUND !!!!!!" << std::endl;

        }




        //Set Obs LOOP
        if (Obs1aY > SCREEN_HEIGH)
        {
            Obs1aY = -10; Obs1aX = getRandomNumber(borderLeft, borderRight); score++;
            if (Obsa1.getGlobalBounds().intersects(Obsa2.getGlobalBounds()) || Obsa1.getGlobalBounds().intersects(Obs3.getGlobalBounds()) || Obsa1.getGlobalBounds().intersects(Obs4.getGlobalBounds()) || Obsa1.getGlobalBounds().intersects(Obsb1.getGlobalBounds()) || Obsa1.getGlobalBounds().intersects(Obsb2.getGlobalBounds()))
            {
                Obs1aY -= 40;
            };
        }
        else { Obs1aY = Obs1aY + gameSpeed; }

        if (Obs2aY > SCREEN_HEIGH)
        {
            Obs2aY = -10; Obs2aX = getRandomNumber(borderLeft, borderRight); score++;

            if (Obsa1.getGlobalBounds().intersects(Obsa2.getGlobalBounds()) || Obsa2.getGlobalBounds().intersects(Obs3.getGlobalBounds()) || Obsa2.getGlobalBounds().intersects(Obs4.getGlobalBounds()) || Obsa2.getGlobalBounds().intersects(Obsb1.getGlobalBounds()) || Obsa2.getGlobalBounds().intersects(Obsb2.getGlobalBounds()))
            {
                Obs2aY -= 40;
            };
        }
        else { Obs2aY = Obs2aY + gameSpeed; }
        if (Obs1bY > SCREEN_HEIGH)
        {
            Obs1bY = -10; Obs1bX = getRandomNumber(borderLeft, borderRight); score++;
            if (Obsa1.getGlobalBounds().intersects(Obsb1.getGlobalBounds()) || Obsb1.getGlobalBounds().intersects(Obs3.getGlobalBounds()) || Obsb1.getGlobalBounds().intersects(Obs4.getGlobalBounds()) || Obsb1.getGlobalBounds().intersects(Obsb2.getGlobalBounds()) || Obsb1.getGlobalBounds().intersects(Obsa2.getGlobalBounds()))
            {
                Obs1bY -= 40;
            };
        }
        else { Obs1bY = Obs1bY + gameSpeed; }
        if (Obs2bY > SCREEN_HEIGH)
        {
            Obs2bY = -10; Obs2bX = getRandomNumber(borderLeft, borderRight); score++;
            if (Obsb2.getGlobalBounds().intersects(Obs3.getGlobalBounds()) || Obsb2.getGlobalBounds().intersects(Obsa1.getGlobalBounds()) || Obsb2.getGlobalBounds().intersects(Obs4.getGlobalBounds()) || Obsb2.getGlobalBounds().intersects(Obsa2.getGlobalBounds()) || Obsb2.getGlobalBounds().intersects(Obsa1.getGlobalBounds()))
            {
                Obs2bY -= 40;
            };
        }
        else { Obs2bY = Obs2bY + gameSpeed; }
        if (Obs3Y > SCREEN_HEIGH)
        {
            Obs3Y = -10; Obs3X = getRandomNumber(borderLeft, borderRight); score++;
            if (Obs3.getGlobalBounds().intersects(Obsa1.getGlobalBounds()) || Obs3.getGlobalBounds().intersects(Obsa2.getGlobalBounds()) || Obs3.getGlobalBounds().intersects(Obsb1.getGlobalBounds()) || Obs3.getGlobalBounds().intersects(Obsb2.getGlobalBounds()) || Obs3.getGlobalBounds().intersects(Obs4.getGlobalBounds()))
            {
                Obs3Y -= 40;
            };
        }
        else { Obs3Y = Obs3Y + gameSpeed; }
        if (Obs4Y > SCREEN_HEIGH)
        {
            Obs4Y = -10; Obs4X = getRandomNumber(borderLeft, borderRight); score++;
            if (Obs4.getGlobalBounds().intersects(Obsa1.getGlobalBounds()) || Obs4.getGlobalBounds().intersects(Obsa2.getGlobalBounds()) || Obs4.getGlobalBounds().intersects(Obsb1.getGlobalBounds()) || Obs4.getGlobalBounds().intersects(Obsb2.getGlobalBounds()) || Obs4.getGlobalBounds().intersects(Obs3.getGlobalBounds()))
            {
                Obs4Y -= 40;
            };
        }
        else { Obs4Y = Obs4Y + gameSpeed; }
        if (GasY > SCREEN_HEIGH)
        {
            GasY = -10; GasX = getRandomNumber(borderLeft, borderRight);
        }
        else if (level_menu::level == 2)
        {
            GasY = -200;
        }
        else
        {
            GasY = GasY + gameSpeed * 0.8;
        }




        //Create event to handle input from keyboard
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            /*if (score > 250)
            {
                Font myfont;
                myfont.loadFromFile("font/xirod.ttf");
                engine = "Engine fail";
                Text text(engine, myfont, 20);
                text.setPosition(0,50);
            }*/


        }

        //////////////////////////////////////////////////////////////////Check if accident happen/////////////////////////////////////////////////////////////////////////////////////////////////////
        if (Racer.getGlobalBounds().intersects(Obsa1.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };
        if (Racer.getGlobalBounds().intersects(Obsa2.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };
        if (Racer.getGlobalBounds().intersects(Obsb1.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };
        if (Racer.getGlobalBounds().intersects(Obsb2.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };
        if (Racer.getGlobalBounds().intersects(Obs3.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };
        if (Racer.getGlobalBounds().intersects(Obs4.getGlobalBounds()))
        {
            s1.play_crash_sound();
            gameOver(app);
        };



        if (Racer.getPosition().x < 130)
        {
            Racer.setPosition(sf::Vector2f(130.0f, Racer.getPosition().y));
        }

        if (Racer.getPosition().x > 660)
        {
            Racer.setPosition(sf::Vector2f(660.0f, Racer.getPosition().y));
        }




        if (Racer.getGlobalBounds().intersects(Gas.getGlobalBounds()))
        {
            s1.play_petrol_sound();
            if (fuelamount < 185)
            {
                fuelamount += 15;
            }
            else
            {
                fuelamount = 200;
            }
            GasY = SCREEN_HEIGH + 5;
        };


        fuelBar.setSize(sf::Vector2f(fuelamount, 50));


        if (fuelamount == 0)
        {
            s1.stop_beep_sound();
            gameOver(app);
        }
        /*if (Timer < 200)
        {
            Timer += 1;
        }*/


        if (level_menu::level != 3)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                Racer.move(-0.25f, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                Racer.move(0.25f, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && RacerY > 0.25)
            {
                Racer.move(0.f, -0.25f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && RacerY < 500)
            {
                Racer.move(0.f, 0.25f);
            }
        }
        else
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                Racer.move(0.25f, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                Racer.move(-0.25f, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && RacerY > 0.25)
            {
                Racer.move(0.f, 0.25f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && RacerY < 500)
            {
                Racer.move(0.f, -0.25f);
            }
        }

        RacerX = Racer.getPosition().x;
        RacerY = Racer.getPosition().y;

        Timer += 1;

        /*if (level == 1)
        {
            level = 0;
            score = 10;
        }
        if (level == 2)
        {
            level = 0;
            score = 18;
        }
        if (level == 3)
        {
            level = 0;
            score = 30;
        }
        if (level == 4)
        {
            level = 0;
            score = 50;
        }
        if (level == 5)
        {
            level = 0;
            score = 80;
        }

    //Create a lap

        if (score > 10)
        {

            lapY += val;
        }
        if (score >  17 )
        {
            lapY += val;
        }
        if (score >  29)
        {
            lapY += val;
        }
        if (score >  49)
        {
            lapY += val;
        }
        if (score >  79)
        {
            lapY += val;
        }

        //Game level
        if (score >= 10 && score < 18)
        {

            gameSpeed = 0.3;
            val = 0.8;
        }
        if (score >= 18 && score < 30)
        {
            val = 1.2;
            gameSpeed = 0.35;
        }
        if (score >= 30 && score < 50)
        {

            val = 2;
            gameSpeed = 0.55;
        }
        if (score >= 50 && score < 80)
        {
            val = 2.75;
            gameSpeed = 1;
        }
        if (score >= 80)
        {
            val = 1;
            gameSpeed = 0.4;
        }


        //check end of lap
        if (RacerY <= lapY-5)
        {

            app.close();
            level_menu l1;
        }*/





        if (level_menu::level == 1)
        {
            if (score > 10 && score < 17)
            {
                gameSpeed = 0.3;
                val = 0.8;
            }
            if (score > 18 && score < 30)
            {
                gameSpeed = 0.35;
                val = 1.2;
            }
            if (score > 30 && score < 50)
            {
                gameSpeed = 0.55;
                val = 2;
            }
            if (score > 50 && score < 80)
            {
                gameSpeed = 0.65;
                val = 2.2;
            }

        }
        if (level_menu::level == 2)
        {
            gameSpeed = 0.55;
            val = 2;
            if (score > 10 && score < 17)
            {
                gameSpeed = 0.65;
                val = 2.2;
            }
            if (score > 18 && score < 30)
            {
                gameSpeed = 0.7;
                val = 2.4;
            }
            if (score > 30 && score < 50)
            {
                gameSpeed = 0.75;
                val = 2.6;
            }
            if (score > 50 && score < 80)
            {
                gameSpeed = 0.65;
                val = 2.2;
            }
        }


        if (level_menu::level == 3)
        {
            gameSpeed = 0.55;
            val = 2;
            if (score > 10 && score < 17)
            {
                gameSpeed = 0.6;
                val = 2.2;
            }
            if (score > 18 && score < 30)
            {
                gameSpeed = 0.65;
                val = 2.3;
            }
            if (score > 30 && score < 50)
            {
                gameSpeed = 0.75;
                val = 2.4;
            }
            if (score > 50 && score < 80)
            {
                gameSpeed = 0.85;
                val = 2.5;
            }
        }
        lap.setPosition(145, lapY);
        if (score >= 150)
        {
            lapY += val;
        }

        if (RacerY <= lapY - 80)
        {

            app.close();

            level_menu l1;
        }



        //update bullet position
        if (Keyboard::isKeyPressed(Keyboard::Space) && Timer >= 500)
        {
            s1.play_bullet_sound();
            projectile1.setPosition(Vector2f(RacerX - 8, RacerY - 8));
            projectile2.setPosition(Vector2f(RacerX + 20, RacerY - 8));
            projectiles.push_back(Sprite(projectile1));
            projectiles.push_back(Sprite(projectile2));
            Timer = 0;


            bullet_fired_count++;

            std::cout << "BUllet fired count : " << bullet_fired_count << std::endl;

            if (fuelamount <= 0)
            {
                gameOver(app);
            }
        }



        for (int i = 0; i < projectiles.size(); i++)
        {
            projectiles[i].move(0.f, -5.0f);



            //Check if projectile hit enemies
            if (((projectiles[i].getPosition().x >= (Obs1aX - 40)) && (projectiles[i].getPosition().x <= (Obs1aX + 40))) && ((projectiles[i].getPosition().y >= (Obs1aY - 40)) && projectiles[i].getPosition().y <= (Obs1aY + 40)))
            {
                Obs1aY = SCREEN_HEIGH + 50;
            };
            if (((projectiles[i].getPosition().x >= (Obs2aX - 40)) && (projectiles[i].getPosition().x <= (Obs2aX + 40))) && ((projectiles[i].getPosition().y >= (Obs2aY - 40)) && projectiles[i].getPosition().y <= (Obs2aY + 40)))
            {
                Obs2aY = SCREEN_HEIGH + 50;
            };
            if (((projectiles[i].getPosition().x >= (Obs1bX - 40)) && (projectiles[i].getPosition().x <= (Obs1bX + 40))) && ((projectiles[i].getPosition().y >= (Obs1bY - 35)) && projectiles[i].getPosition().y <= (Obs1bY + 35)))
            {
                Obs1bY = SCREEN_HEIGH + 50;
            };
            if (((projectiles[i].getPosition().x >= (Obs2bX - 40)) && (projectiles[i].getPosition().x <= (Obs2bX + 40))) && ((projectiles[i].getPosition().y >= (Obs2bY - 40)) && projectiles[i].getPosition().y <= (Obs2bY + 40)))
            {
                Obs2bY = SCREEN_HEIGH + 50;
            };
            if (((projectiles[i].getPosition().x >= (Obs3X - 40)) && (projectiles[i].getPosition().x <= (Obs3X + 40))) && ((projectiles[i].getPosition().y >= (Obs3Y - 40)) && projectiles[i].getPosition().y <= (Obs3Y + 40)))
            {
                Obs3Y = SCREEN_HEIGH + 50;
            };
            if (((projectiles[i].getPosition().x >= (Obs4X - 40)) && (projectiles[i].getPosition().x <= (Obs4X + 40))) && ((projectiles[i].getPosition().y >= (Obs4Y - 40)) && projectiles[i].getPosition().y <= (Obs4Y + 40)))
            {
                Obs4Y = SCREEN_HEIGH + 50;
            };

            if (projectiles[i].getPosition().y < 0)
            {
                projectiles.erase(projectiles.begin() + i);
            }
        }
        //Clear and redraw position


        app.clear();

        app.draw(Background);
        app.draw(Background1);
        app.draw(lap);
        app.draw(Racer);
        app.draw(Obsa1);
        app.draw(Obsa2);
        app.draw(Obsb1);
        app.draw(Obsb2);
        app.draw(Obs3);
        app.draw(Obs4);
        app.draw(fuelBar);
        app.draw(Border);
        app.draw(Gas);
        for (int i = 0; i < projectiles.size(); i++)
        {
            app.draw(projectiles[i]);
        }
        app.display();
    }
}


int game::gameOver(sf::RenderWindow& app)
{
    Texture gameover;
    if (!gameover.loadFromFile("cars/over.png")) return EXIT_FAILURE;

    Sprite Gameover(gameover);

    Font myfont;
    myfont.loadFromFile("font/xirod.ttf");
    stringscore = "YOUR SCORE:" + std::to_string(score);
    Text text(stringscore, myfont, 30);
    text.setPosition(210, 400);
    text.setFillColor(Color::White);
    Text play_again;
    play_again.setFont(myfont);
    play_again.setString("Press Enter");
    play_again.setPosition(220, 480);
    play_again.setCharacterSize(30);
    play_again.setFillColor(Color::White);

    while (app.isOpen())
    {

        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Enter)
                {
                    level_menu::level = 0;
                    app.close();
                    main_menu m;
                }
            }

        }
        app.clear();
        app.draw(Gameover);
        app.draw(text);
        app.draw(play_again);
        app.display();
    }

}
int game::getRandomNumber(int a, int b)
{
    static bool first = true; if (first) { srand(time(NULL)); first = false; }
    int result = a + rand() % ((b + 1) - a);
    result = (result / 10) * 10;
    return result;
}
