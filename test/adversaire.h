#ifndef ADVERSAIRE_H
#define ADVERSAIRE_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "mario.h"
using namespace std;
using namespace sf;
//Declaration Globale
float gr = 415, gra = 130;
Clock clo;
class adversaire
{
private:
	float dx = 100;
	bool fr = true, isfalling = false, mort = false;
	Vector2f pos;
	Vector2i anim;
	int etat = 0;
	Texture adv;
	Sprite sadv;
public:
	adversaire(float x,float y)
	{
		anim.x = 0; anim.y = 0;
		pos.x = x;
		pos.y = y;
		if (!adv.loadFromFile("./res/adv1.png"))
			cout << "Un probleme lors du chargement du bg" << endl;
		adv.setSmooth(true);
		sadv.setTexture(adv);
		sadv.setTextureRect(IntRect(0, 0, 32, 32));
	}
	//animation
	void animation()
	{
		if ((clo.getElapsedTime().asMilliseconds()%100 >= 80)&&(etat==0))
		{
			anim.x++;
			if (anim.x == 2)
				anim.x = 0;
			sadv.setTextureRect(IntRect(anim.x * 32, anim.y * 32, 32, 32));
		}
	}
	//collision mario et adversaire
	void collision(Mario& mario,int score)
	{
		if (((sadv.getPosition().y - 16) - (mario.getsp().getPosition().y + 24) < 20) && (abs(sadv.getPosition().x-mario.getsp().getPosition().x+16 )<16)&& !mort&& !mario.isdead())
		{
			if ((gr - mario.getsp().getPosition().y ) > 17)
			{
				sadv.setTextureRect(IntRect(2 * 32, 0, 32, 32));
				mort = true;
				mario.addscore();
			}
			else mario.dead();
		}
	}
	//update des mouvements des adversaires
	void update(int level[], float deltatime,Mario& mario,int x0,int x1,bool pause,int score)
	{
		if (!pause)
		{
			collision(mario,score);
			if (!mort)
			{
				if (fr)
				{
					if (sadv.getPosition().x > x1)
					{
						fr = false;
					}
					else
					{
						pos.x += dx * deltatime;
						animation();
					}
				}
				else
				{
					if (sadv.getPosition().x < x0)
					{
						fr = true;
					}
					else
					{
						pos.x -= dx * deltatime;
						animation();
					}
				}
				if (pos.y < gr)
					isfalling = true;
				if (isfalling)
				{
					if (pos.y > gr)
					{
						isfalling = false;
						pos.y = gr;
					}
					else
						pos.y += gra * 1.5f * deltatime;
				}
			}
		}
	}
	//dessiner
	void draw(RenderWindow& window)
	{
		if (etat < 20)
		{
			sadv.setPosition(pos);
			window.draw(sadv);
			if (mort)
			{
				etat++;
			}
		}		
	}
	//supprimer l'adversaire apres son mort
	bool supp()
	{
		if (mort && etat == 2)
			return true;
		else
		{
			etat++;
			return false;
		}
	}
};
#endif
