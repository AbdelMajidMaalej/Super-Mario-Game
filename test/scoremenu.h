#ifndef SCOREMENU_H
#define SCOREMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Scoremenu
{
private:
    Text txt;
    Font font;
    float posx=90;
public:
    Scoremenu()
    { 
        if (!font.loadFromFile("./res/Cafe-Matcha.ttf"))
        {
            cout << "un probleme de chargement" << endl;
        }
    }
    void SetText(string ch,Mario& mario)
    {
        posx = mario.getsp().getPosition().x;
        if (posx < 400)
            txt.setPosition(90, 20);
        if (posx>2000)
            txt.setPosition(1677, 20);
        if ((posx<2000)&&(posx>400))
            txt.setPosition(Vector2f(posx - 310, 20.f));
        txt.setFont(font);
        txt.setString(ch);
        txt.setCharacterSize(32);
        txt.setFillColor(Color(50, 50, 50));
        if (paused)
        {
            txt.setFillColor(Color::White);
        }
    }
    void drawit(RenderWindow& window)
    {
        window.draw(txt);
    }
};
#endif
