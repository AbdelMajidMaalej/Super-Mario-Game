#ifndef QUIZ_H
#define QUIZ_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace sf;
using namespace std;
int clicktime=0;
class Quiz
{
private:
	int selecteditemindex = 2,n=-1;
	int bonnereponse=0;
	Font font;
	Text menu[7],reponse,time;
	Texture bg;
	Sprite sbg;
	RectangleShape rec;
	int width = 800, height = 604,indquiz=0;
	bool rep = false, fin = true;
public:
	const int max = 7;
	Quiz(float width, float height, String ques[10][7])
	{
		time.setFont(font);
		time.setString("0");
		time.setCharacterSize(24);
		time.setFillColor(Color::Red);
		time.setPosition(Vector2f(760, 44));
		reponse.setFont(font);
		rec.setSize(Vector2f(height, width));
		rec.setFillColor(Color::Color(50, 50, 50, 0.5));
		rec.setPosition(Vector2f(height / 2, width / 2));
		if (!font.loadFromFile("res/font.ttf"))
			cout << "Probleme de chargement de fonte" << endl;
		if (!bg.loadFromFile("res/mario1.png"))
			cout << "Probleme de chargement du bg quiz" << endl;
		bg.setSmooth(true);
		sbg.setTexture(bg);
		sbg.setPosition(0, 0);
		for (int i = 0; i < 7; i++)
		{
			menu[i].setFont(font);
			menu[i].setString(ques[0][i]);
			menu[i].setCharacterSize(24);
			menu[i].setFillColor(Color::Black);
			switch (i)
			{
			case 1:
				menu[i].setPosition(Vector2f(width / 20, height / (max + 1) * i));
			case 2:
				menu[i].setPosition(Vector2f(width / 10, height / (max + 1) * i));
			case 3:
				menu[i].setPosition(Vector2f(width, height / (max + 1) * i));
			case 4:
				menu[i].setPosition(Vector2f(width / 20, height / (max + 1) * i));
			case 5:
				menu[i].setPosition(Vector2f(width / 20, height / (max + 1) * i));
			case 6:
				menu[i].setPosition(Vector2f(width / 20, height / (max + 1) * i));
			case 7:
				menu[i].setPosition(Vector2f(width / 20, height / (max + 1) * i));
			}
			menu[2].setFillColor(Color::Blue);
		}
	}
	void repondre(int i,RenderWindow &window,bool final)
	{
		rep = true;
		if (getselected() == i)
		{
			menu[getselected()].setFillColor(Color::Green);
			n++;
			if (final)
				bonnereponse++;
			cout << bonnereponse << endl;
		}
		else 
			menu[getselected()].setFillColor(Color::Red);
	}
	void arreter(float& heure)
	{
		if (rep)
		{
			if (heure > clicktime+3)
			{
				quiz = false;
				rep = false;
					indquiz++;
				heure = 0;
				fin = true;
				cout << "majda" << endl;
			}
		}
		else
		{	
			clicktime = heure;
			if ((heure > 10))
			{
				indquiz++;
				quiz = false;
				heure = 0;
				fin = true;
				cout << "majda" << endl;
			}
		}
	}
	void Settext(String ques[10][7],float x)
	{
		if (fin)
		{
			if (x < 400)
				x = 385;
			if ((x > 1900) && (x<2100))
				x = 1985;
			if ((x > 2200))
				x = 1985;
			sbg.setPosition(x - 385, 0);
			cout << "kimoooooooo" << endl;
			for (int i = 0; i < max; i++)
			{
				menu[i].setFont(font);
				menu[i].setString(ques[indquiz][i]);
				menu[i].setCharacterSize(24);
				switch (i)
				{
					
				case 0:
				{
					menu[i].setPosition(Vector2f(x - 130, height / (max + 1) * i));
					cout << "yasmine" << endl;
					break;
				}
				case 1:
				{
					menu[i].setPosition(Vector2f(x - 250, height / (max + 1) * i));
					break;
				}
				case 2:
				{
					menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
					menu[i].setFillColor(Color::Blue);

					break;
				}
				case 3:
				{
					menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
					menu[i].setFillColor(Color::Black);
					break;
				}
				case 4:
				{
					menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
					menu[i].setFillColor(Color::Black);
					break;
				}
				case 5:
				{
					menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
					menu[i].setFillColor(Color::Black);
					break;
				}

				case 6:
				{
					menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
					menu[i].setFillColor(Color::Black);
					break;
				}
				case 7:
				{
					menu[i].setPosition(Vector2f(x - 350, height / (max + 1) * i));
					menu[i].setFillColor(Color::Black);
					break;
				}
				}
				selecteditemindex = 2;
			}
			time.setPosition(x + 250, 50);
			rep = false;
			fin = false;
		}
	}
	void finalquiz(String ques[10][7], float x,RenderWindow &window,float& heure,bool& final,Mario mario)
	{
		if (indquiz < 5)
			indquiz = 5;
			window.clear();
			Settext(ques, x);
			drawit(window, heure,mario);
			arreter(heure);
			if (indquiz==10)
				final = false;
	}
	void drawit(RenderWindow& window,float heure,Mario mario)
	{
		window.draw(sbg);
		for (int i = 0; i < max-1; i++)
		{
			window.draw(menu[i]);
		}
		if (!rep)
			time.setString(to_string(int(heure)));
		window.draw(time);
		if (mario.getcoin() != 0)
		{
			window.draw(menu[6]);
			mario.subcoin();;
		}
	}
	void moveup()
	{
		if (selecteditemindex - 1 >= 2)
		{
			menu[selecteditemindex].setFillColor(Color::Black);
			selecteditemindex--;
			menu[selecteditemindex].setFillColor(Color::Blue);
		}
	}
	void movedown()
	{

		if (selecteditemindex + 1 < max)
		{
			menu[selecteditemindex].setFillColor(Color::Black);
			selecteditemindex++;
			menu[selecteditemindex].setFillColor(Color::Blue);
		}
	}
	int getselected()
	{
		return (selecteditemindex);
	}
};
#endif;
