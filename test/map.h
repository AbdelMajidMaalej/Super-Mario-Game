#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
using namespace sf;
using namespace std;
class Map {
private:
    Texture c;
    Sprite spri;
    Vector2f position;
    float temps = 0;
public:
    Map(string ch)
    {
        load(ch);
    }
    void load(string ch)
    {
        if (!c.loadFromFile(ch))
            cout << "Un probleme lors du chargement du photo" << endl;
        c.setSmooth(true);
        spri.setTexture(c);
    }
    //Construire la map
    void construire(int level[],RenderWindow& window)
    {
            for (int i = 0; i < 1425; i++)
            {
                if (level[i] == 1|| level[i] == 2||level[i] == 3 || level[i] == 4 || level[i] == 5 || level[i] == 6 || level[i] == 7 || level[i] == 8 || level[i] == 9 || level[i] == 10 || level[i] == 11 || level[i] == 12 || level[i] == 13 || level[i] == 14)
                {
                    spri.setTextureRect(IntRect(level[i] * 32, 0, 32, 32));
                    position.y = int(i / 75);
                    position.x = (i - (position.y * 75)) * 32;
                    position.y = position.y * 32;
                    spri.setPosition(position);
                    draw(window);
                }
                if (level[i] == 17 || level[i] == 18 || level[i] == 19 || level[i] == 20 || level[i] == 21 || level[i] == 22 || level[i] == 23 || level[i] == 24 || level[i] == 25)
                {
                    spri.setTextureRect(IntRect((level[i]-17) * 32, 32, 32, 32));
                    position.y = int(i / 75);
                    position.x = (i - (position.y * 75)) * 32;
                    position.y = position.y * 32;
                    spri.setPosition(position);
                    draw(window);
                }   
            }
    }
    //Update map ( chaque fram )
    void updatemap(int* level,float deltatime)
    {
        temps += deltatime;
        if (temps > 0.1)
        {
            temps = 0;
            for (int i = 0; i < 75 * 19 - 1; i++)
            {
                if (level[i] == 17 || level[i] == 18 || level[i] == 19 || level[i] == 20 || level[i] == 21 || level[i] == 22 || level[i] == 23 || level[i] == 24 || level[i] == 25)
                {
                    level[i]++;
                    if (level[i] == 25)
                    {
                        level[i] = 17;
                    }
                }
            }
        }
        
    }
    //Dessiner
    void draw(RenderWindow& window)
    {
        window.draw(spri);
    }
};
#endif
