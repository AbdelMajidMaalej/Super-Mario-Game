#include "adversaire.h"
#include "map.h"
#include "pause.h"
#include "mainmenu.h"
#include "main.h"
//yasmine
//end-yasmine
float deltatime;
Mario mario;
View view;
Texture cube, adv;
Sprite sp1, sp2, sp3, sp4, sp5, sp6;
Clock mongela;
Music music;
int main()
{
    if (!music.openFromFile("./res/uni_music_play.ogg"))
        cout << "Un probleme lors du chargement de la musique" << endl;
    music.setVolume(80);
    RenderWindow window(VideoMode(800, 608, 32), "Super Mario");
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
    Texture backgd;
    Sprite sbackgd;
    if (!backgd.loadFromFile("./res/mario0.png"))
        cout << "Un probleme lors du chargement du bg" << endl;
    else
        cout << "chargement" << endl;
    sbackgd.setTexture(backgd);
    backgd.setSmooth(true);
    for (int i = 0; i < 75 * 19 - 1; i++)
        level[i] -= 1;
    Map map("./res/tem.png");
    if (!adv.loadFromFile("./res/adv1.png"))
        cout << "Un probleme lors du chargement du bg" << endl;
    sp1.setTexture(adv); sp2.setTexture(adv); sp3.setTexture(adv); sp4.setTexture(adv); sp5.setTexture(adv); sp6.setTexture(adv);
    adv.setSmooth(true);
    adversaire ad1(sp1, 400, 400), ad2(sp2, 450, 400), ad3(sp3, 800, 400), ad4(sp4, 850, 400), ad5(sp5, 1030, 400), ad6(sp6, 1000, 400);
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
    //yasmine
    mainmenu menu;
    bool newgame = false, aboutus = false;
    Text txt, tx;
    Font  font;
    int y = 0;
    int life = 5;
    int world = 0;
    int player = 0;
    float heure = 0;
    //end_yasmine
    while (window.isOpen())
    {
        //yasmine
        scoremenu.SetText("MARIO   " + to_string(player) + "          score  " + to_string(score) + "         COIN    " + to_string(coin) + " - " + to_string(5) + "         TIME   " + to_string(int(heure)), mario);
        deltatime = mongela.getElapsedTime().asSeconds();
        mongela.restart();
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
            {
                menu.moveup(newgame, aboutus);
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
            {
                menu.movedown(newgame, aboutus);
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return && menu.getitempressed() == 0 && !(aboutus))
            {
                cout << "new game  is pressed" << endl;
                newgame = true;
                music.play();
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return && menu.getitempressed() == 1)
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
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return && menu.getitempressed() == 2 && !(aboutus))
            {
                window.close();
            }
            //end_yasmine
            if (event.type == Event::Closed)
            {
                window.close();
            }
            pause.update(event, mario, music);
        }
        if (newgame)
        {
            ad1.update(level, deltatime, mario, 0, 525, pause.ispaused()); ad2.update(level, deltatime, mario, 50, 575, pause.ispaused()); ad3.update(level, deltatime, mario, 739, 1068, pause.ispaused()); ad4.update(level, deltatime, mario, 789, 1118, pause.ispaused()); ad6.update(level, deltatime, mario, 1729, 2047, pause.ispaused()); ad5.update(level, deltatime, mario, 2111, 2304, pause.ispaused());
            mario.update(deltatime, level, pause.ispaused());
            map.updatemap(level, deltatime);
            if (mario.getsp().getPosition().x < 1987)
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
            window.display();
        }
        else
        {
            window.clear();
            window.draw(sbackgd);
            menu.drawmenu(window, aboutus);
            window.display();
        }
    }
    return 0;
}
