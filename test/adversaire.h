#ifndef ADVERSAIRE_H
#define ADVERSAIRE_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
using namespace std;
using namespace sf;
float gr = 415, gra = 130;
Clock clo;
class adversaire
{
private:
	float dx = 100;
	bool facingright = false,isfalling=false;
	Sprite adsp;
	Vector2f pos;
	Vector2i anim;

public:
	adversaire(Sprite sp,float x,float y)
	{
		anim.x = 0; anim.y = 0;
		pos.x = x;
		pos.y = y;
		adsp = sp;
		adsp.setTextureRect(IntRect(0, 0, 32, 32));
	}
	Sprite getsp()
	{
		return adsp;
	}
	void animation()
	{
		if (clo.getElapsedTime().asMilliseconds() >= 100)
		{
			anim.x++;
			if (anim.x == 2)
				anim.x = 0;
			adsp.setTextureRect(IntRect(anim.x * 32, anim.y * 32, 32, 32));
			clo.restart();
		}
	}
	void update(int level[],float deltatime)
	{
		float b = adsp.getGlobalBounds().top + 32, t = adsp.getGlobalBounds().top, l = adsp.getGlobalBounds().left, r = adsp.getGlobalBounds().left + 32;
		if (facingright)
		{
			if (level[int(((b - 16) / 32) * 75) + int(r / 32)] == 7)
			{
				facingright = false;
			}
			else
			{
				pos.x += dx * deltatime;
				animation();
			}

		}
		else
		{
			if (level[int(((b - 16) / 32) * 75) + int(l / 32)] == 7)
			{
				facingright = true;
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
	void draw(RenderWindow& window)
	{
		adsp.setPosition(pos);
		window.draw(adsp);
	}
};
#endif
