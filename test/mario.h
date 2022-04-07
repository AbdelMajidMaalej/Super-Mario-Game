#ifndef MARIO_H
#define MARIO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "adversaire.h"
using namespace std;
using namespace sf;
Vector2i anim(1, 1);
Clock c;
bool canjump = true, isjumping = false, isfalling = false, collr = false, collf = false, collj = false, facingright = true, death = false, deathjumping = false, deathfalling = false;
float speed = 200, gravity = 130, ground = 401, jumptime, jumpduration = 0.45;
float cof = 1;
class Mario
{
private:
	Texture tex;
	Sprite sp;
	Vector2f velocity;
	int life = 3;
public:
	Mario()
	{
		if (!tex.loadFromFile("./res/perso.png"))
			cout << "Un probleme lors du chargement du photo" << endl;
		tex.setSmooth(true);
		sp.setTexture(tex);
		velocity.x = 100; velocity.y = ground;
		sp.setTextureRect(IntRect(0, 0, 32, 48));
	}
	Texture gettex()
	{
		return tex;
	}
	Sprite getsp()
	{
		return sp;
	}
	void collision(int level[])
	{
		int i;
		int top = sp.getGlobalBounds().top, left = sp.getGlobalBounds().left, right = left + 32, bottom = top + 48;
		//collision bottom
		int cb = (((bottom + 5) / 32) * 75) + ((left + 16) / 32);
		if (level[cb] == 3 || level[cb] == 1 || level[cb] == 2 || level[cb] == 7 || level[cb] == 4 || level[cb] == 5 || level[cb] == 6 || level[cb] == 11 || level[cb] == 12 || level[cb] == 13 || level[cb] == 14)
		{
			isfalling = false;
			canjump = true;
		}
		//collision top cassable
		int ctc;
		if (facingright)
		{
			for (i = 0; i < 8; i++)
			{
				ctc = ((top / 32) * 75) + ((left + i) / 32);
				if (level[ctc] == 7)
				{
					isjumping = false;
					isfalling = true;
					level[ctc] = 0;
				}
			}
		}
		else
		{
			for (i = 24; i < 32; i++)
			{
				ctc = ((top / 32) * 75) + ((left + i) / 32);
				if (level[ctc] == 7)
				{
					isjumping = false;
					isfalling = true;
					level[ctc] = 0;
				}
			}
		}


		//collision top non cassable
		int ctnc = ((top / 32) * 75) + ((left + 16) / 32);
		if (level[ctnc] == 3 || level[ctnc] == 2 || level[ctnc] == 4 || level[ctnc] == 5)
		{
			isjumping = false;
			isfalling = true;
			level[ctnc] =2;
		}
		//collision right
		int cr = (((bottom - 16) / 32) * 75) + ((right + 5) / 32);
		if (level[cr] == 7 || level[cr] == 1 || level[cr] == 3 || level[cr] == 4 || level[cr] == 5 || level[cr] == 6 || level[cr] == 11 || level[cr] == 12 || level[cr] == 13 || level[cr] == 14 || level[cr] == 2)
			collr = true;
		else collr = false;
		//collision left
		int cl = (((bottom - 16) / 32) * 75) + ((left - 5) / 32);
		if (level[cl] == 7 || level[cl] == 1 || level[cl] == 3 || level[cl] == 4 || level[cl] == 5 || level[cl] == 6 || level[cl] == 11 || level[cl] == 12 || level[cl] == 13 || level[cl] == 14||level[cl] == 2)
			collf = true;
		else collf = false;
		if (1437 < velocity.x < 1567)
		{
			ground = 1000;
		}
		if (velocity.y > 900)
			death = true;
	}
	void dead()
	{	
		death = true;
		deathjumping = true;
	}
	void update(float deltatime, int level[])
	{
		if (!death)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right) && !(collr) && (sp.getPosition().x < 2376))
			{
				velocity.x += speed * deltatime;
				anim.y = 0;
				facingright = true;
				animation();
			}
			if (sp.getPosition().x >= 0.0f && Keyboard::isKeyPressed(Keyboard::Left) && !(collf))
			{
				velocity.x -= speed * deltatime;
				facingright = false;
				anim.y = 1;
				animation();
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) && canjump)
			{
				{
					isjumping = true;
					canjump = false;
					anim.x = 1;
					jumptime = 0;
				}
			}
			if (isjumping)
			{
				jumptime += deltatime;
				if (jumptime < jumpduration)
				{
					velocity.y -= gravity * 2 * deltatime ;
					anim.x = 1;
				}
				else
				{
					isjumping = false;
					isfalling = true;
					cof = 1;
				}
			}
			if (isfalling)
			{
				anim.x = 1;
				if (velocity.y > ground)
				{
					isfalling = false;
					canjump = true;
					velocity.y = ground;
				}
				else
				{
					velocity.y += gravity * 1.5f * deltatime * cof;
					cof +=0.025;
					cout << cof << endl;
				}
					
			}
			if ((velocity.y < ground) && (canjump))
			{
				isfalling = true;
				canjump = false;
			}
			collision(level);
		}
		else
		{
			sp.setTextureRect(IntRect(2 * 32, 2 * 48, 32, 48));
			if (deathjumping)
			{
				jumptime += deltatime;
				if (jumptime < 0.3)
				{
					velocity.y -= gravity * 2 * deltatime;
				}
				else
				{
					deathjumping = false;
					deathfalling = true;
				}
			}
			if (deathfalling)
			{
				if (velocity.y > 900)
				{
					deathfalling = false;
					velocity.y = 900;
				}
				else
					velocity.y += gravity * 1.5f * deltatime ;
					
			}
			}
	}
	void animation()
	{
		if (c.getElapsedTime().asMilliseconds() >= 100)
		{
			anim.x++;
			if (anim.x * 32 >= tex.getSize().x)
				anim.x = 0;
			sp.setTextureRect(IntRect(anim.x * 32, anim.y * 48, 32, 48));
			c.restart();
		}
	}
	void draw(RenderWindow& window)
	{
		sp.setPosition(velocity);
		window.draw(sp);
	}
	bool isdead()
	{
		return death;
	}
};
#endif
