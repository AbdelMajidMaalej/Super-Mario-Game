﻿#ifndef MAIN_H
#define MATH_H
#include "adversaire.h"
#include "map.h"
#include "pause.h"
#include "mainmenu.h"
#include "scoremenu.h"
#include "quiz.h"
#include "gameover.h"
#include "winmenu.h"
class Game
{
private:
    int vrai[10] = {4,2,3,3,5,2,2,3,2,4 };
    String indice[5] = { "\n\nVotre indice : Dominée par les Perses\n        en 616.","Votre indice : Il parcourt 290 km \n      en Suisse." ,"Votre indice : Inférieur à 200 000 km2.","\nVotre indice : Multiple de 2.","Votre indice : Il est de nationalité britannique." };
    String ch[10][7] = { {"\n", "\n          Question : Quel est l'âge de l'Univers?", "\n1- 6 000 ans", "\n2- 4,6 milliards d'années", "\n3- 13,7 milliards d'années", "\n4- L'Univers est éternel et existe\n        depuis toujours."," "},//4 3- 13,7 milliards d'années
{"\n", "\n          Question : Toutes les espèces vivantes sur \n Terre possèdent :", "\n\n 1- de l ADN", "\n\n 2- les mêmes gènes (le même génome)", "\n\n3- un animal de compagnie", "\n\n4- Toutes ces réponses."},//2 de l ADN
{"\n", "\n        Question : Lequel des langages informatiques \nsuivants est utilisé pour l intelligence artificielle?", "\n\n1- PROLOG", "\n\n2- C", "\n\n3- FORTRAN", "\n\n4- COBOL"},//3  C
{"\n", "\n        Question : Le microprocesseur a été introduit \ndans quelle génération d'ordinateur?", "\n\n1- Deuxième génération", "\n\n2- Troisième génération", "\n\n3- en 1942", "\n\n4- Quatrième génération"},//3 Troisième génération
{"\n", "\n          Complèter : GUI signifie _______?", "\n1- Graph Use Interface", "\n2- Graphical Universal Interface", "\n3- Graphical User Interface", "\n4-Graphical Unique Interface",},//5 4-Graphical Unique Interface
{"\n             1ère question :","\n          Quelle ville est surnommée la Fiancée de\n      la Méditerranée ?", "\n\n1- Alexandrie", "\n\n2- Tunis", "\n\n3- Marrakech", "\n\n4- Mauritanie",""},
{"\n             2éme question :", "\n          Quel fleuve traverse la ville de Lyon ?", "\n1- Le Rhône", "\n2- La seine", "\n3- Le Rhin", "\n",""},
{"\n             3éme question :", "\n          Quelle est la superficie approximative de \n                           la Tunisie ?", "\n1- 563 000 km2", "\n2- 163 000 km2", "\n3- 63 000 km2", "\n",""},
{"\n             4éme question :", "\n          Combien de planètes existent dans le\n      système solaire ?", "\n\n1- 8", "\n\n2- 9", "\n\n3- 10", "",""},
{"\n             5éme question :", "\n          Quel acteur a le plus d'oscar ?", "\n1- Woody Allen", "\n2- Walt Disney", "\n3- Daniel Day-Lewis","" }
    };

    //Declaration Globale
    float mariox;
	float deltatime;
	Mario mario;
	View view;
	Texture cube, adv;
	Sprite sp1, sp2, sp3, sp4, sp5, sp6;
	Clock mongela;
	Music music;
    bool repeat = true, work = false, youwon = false;
    int quizcoin;
    float camerax;
    //fin declaration
public:
    void lancerjeu()
    {
        RenderWindow window(VideoMode(800, 608, 32), "Super Mario");
        while (repeat)
        {
            //Déclaration chaque game
            mario.mariorestart(window);
            bool canclick = true;
            view.reset((FloatRect(0, 0, 800, 608)));
            float quizheure = 0;
            bool repeat = false;
            mongela.restart();
            Quiz qind(800, 604, ch);
            if (!music.openFromFile("./res/uni_music_play.ogg"))
                cout << "Un probleme lors du chargement de la musique" << endl;
            music.setVolume(80);
            GAMEOVER overgame(window);
            Winmenu winmenu(window);
            float deathtime = 0;
            int level[] =
            {
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,8,8,8,4,8,8,8,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,12,13,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,12,13,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,14,15,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,14,15,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,14,15,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,14,15,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
            };
            for (int i = 0; i < 75 * 19 - 1; i++)
                level[i] -= 1;
            Map map("./res/tem.png");
            adversaire ad1(400, 400), ad2(450, 400), ad3(800, 400), ad4(850, 400), ad5(1300, 400), ad6(1000, 400);
            window.setVerticalSyncEnabled(true);
            window.setFramerateLimit(60);
            Event event;
            Vector2f camera;
            Texture bg, backgroundtexture;
            Sprite sbg;
            Scoremenu scoremenu;
            view.reset(FloatRect(0, 0, 800, 608));
            if (!bg.loadFromFile("./res/bg.png"))
                cout << "Un probleme lors du chargement du bg" << endl;
            sbg.setTexture(bg);
            bg.setSmooth(true);
            Pausegame pause(window);
            mainmenu menu;
            bool newgame = false, aboutus = false;
            Text txt, tx;
            Font  font;
            int y = 0;
            int life = 5;
            int world = 0;
            int player = 0;
            float heure = 0;
            //end Declaration chaque game
            while (window.isOpen())
            {
                mariox = mario.getsp().getPosition().x;
                scoremenu.SetText("MARIO   " + to_string(player) + "          score  " + to_string(mario.getscore()) + "         COIN    " + to_string(mario.getcoin()) + " - " + to_string(5) + "         TIME   " + to_string(int(heure)), mario);
                deltatime = mongela.getElapsedTime().asSeconds();
                mongela.restart();
                if ((!paused)&&(newgame))
                    heure += deltatime;
                if ((mario.death)||(menudeath))
                    deathtime += deltatime;
                while (window.pollEvent(event))
                {
                    //Events
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
                    {
                        if ((quiz) || (finalquiz))
                            qind.moveup();
                        else
                            menu.moveup(newgame, aboutus);
                    }
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
                    {
                        if ((quiz) || (finalquiz))
                            qind.movedown();
                        else
                            menu.movedown(newgame, aboutus);
                    }
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return && menu.getitempressed() == 0 && !(aboutus))
                    {
                        if (!quiz && !newgame)
                        {
                            cout << "new game  is pressed" << endl;
                            newgame = true;
                            music.play();
                        }
                    }
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return &&(( overgame.getitempressed() == 0)||(winmenu.getitempressed() == 0)) && work)
                    {
                            cout << "main menu si pressed" << endl;
                            work = false;
                            repeat = true;
                            deathjumping = false;
                            mario.death = false;
                            camerax = mario.getsp().getPosition().x;
                            aboutus = false;
                            win = false;
                            menudeath = false;
                    }
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return)
                    {
                        if ((!quiz) && (!finalquiz))
                        {
                            if (menu.getitempressed() == 1)
                            {
                                if (!aboutus)
                                {
                                    cout << "aboutus is pressed" << endl;
                                    aboutus = true;
                                }
                                else
                                {
                                    aboutus = false;
                                }
                            }
                        }
                        else
                        {
                            if (finalquiz)
                            {
                                if (indvrai < 5)
                                    indvrai = 5;
                            }
                            qind.repondre(vrai[indvrai], window, finalquiz,canclick);
                            if (canclick)
                            {
                                indvrai++;
                                canclick = false;
                            }
                            
                            
                                

                        }
                    }
                    if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return && menu.getitempressed() == 2 && !(aboutus))
                    {
                        window.close();
                        exit(1);
                        repeat = false;
                    }
                    if (event.type == Event::Closed)
                    {
                        window.close();
                    }  
                    pause.update(event, mario, music);
                    overgame.update(mario, music);
                    winmenu.update(mario, music, win);
                    //end Events
                }
                if (newgame)
                {
                    if ((quiz) || (finalquiz)||(win))
                    {
                        if ((quiz))
                            //Question box
                        {
                            quizheure += deltatime;
                            window.clear();
                            qind.Settext(ch, mariox);
                            qind.drawit(window, quizheure, mario);
                            qind.arreter(quizheure,canclick);
                        }
                        if (finalquiz)
                            //Quiz final
                        {
                            quizheure += deltatime;
                            qind.setindice(mario.getcoin(), ch, indice);
                            qind.Finalquiz(ch, mariox, window, quizheure, mario,finalquiz,canclick);
                        }
                    }
                    else
                    {
                        //Super Mario
                        if (deathtime < 2)
                        {
                            ad1.update(level, deltatime, mario, 0, 525, pause.ispaused(), mario.getscore()); ad2.update(level, deltatime, mario, 50, 575, pause.ispaused(), mario.getscore()); ad3.update(level, deltatime, mario, 739, 1068, pause.ispaused(), mario.getscore()); ad4.update(level, deltatime, mario, 789, 1118, pause.ispaused(), mario.getscore()); ad6.update(level, deltatime, mario, 1729, 2047, pause.ispaused(), mario.getscore()); ad5.update(level, deltatime, mario, 2111, 2304, pause.ispaused(), mario.getscore());
                            mario.update(deltatime, level, pause.ispaused(), reponsetrue);
                            map.updatemap(level, deltatime);
                            if ((mario.getsp().getPosition().x < 1987))
                            {
                                camera.x = mario.getsp().getPosition().x + 16 - 400;
                                if (camera.x < 0)
                                    camera.x = 0;
                            }
                            view.reset(FloatRect(camera.x, camera.y, 800, 608));
                            window.setView(view);
                            window.clear();
                            window.draw(sbg);
                            map.construire(level, window);
                            mario.draw(window);
                            ad2.draw(window); ad1.draw(window); ad3.draw(window); ad4.draw(window); ad5.draw(window); ad6.draw(window);
                            pause.drawit(window);
                            scoremenu.drawit(window);
                        }
                    }
                    window.display();
                }
                else
                {
                    //Main Menu
                    menu.update(mario, music, camerax);
                    window.clear();
                    menu.drawmenu(window, aboutus);
                    window.display();
                }
                if (((mario.death)&&(!finalquiz)&&(!youwon))||(menudeath))
                {
                    //GameOver
                    if (deathtime > 2)
                    {
                        overgame.drawover(window);
                        window.display();
                        work = true;
                        cout << "met" << endl;
                    }
                }
                if (win)
                {
                    //GameWon
                    winmenu.drawover(window);
                    window.display();
                    cout << "rbah" << endl;
                    youwon = true;
                    work = true;

                }
                //Repeter le jeu
                if (repeat)
                    break;
                //Temps
                if (heure > 120)
                    mario.death = true;
            }
        }
    }
};
#endif;
