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
	Font font;
	Text menu[7],reponse,time;
	RectangleShape rec;
	int width = 800, height = 604,indquiz=0;
	bool rep=false;
public:
	const int max = 6;
	Quiz(float width, float height, String ch[7], int ind, String ques[6][6])
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
		for (int i = 0; i < max; i++)
		{
			menu[i].setFont(font);
			menu[i].setString(ques[0][i]);
			menu[i].setCharacterSize(24);
			menu[i].setFillColor(Color::White);
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
			}
			menu[2].setFillColor(Color::Red);

		}
	}
	void repondre(int i,RenderWindow &window)
	{
		rep = true;
		if (getselected() == i)
		{
			reponse.setString("                     Bonne reponse");
			n++;
			//indices1[n] = indices[n];
		}
		else 
		reponse.setString("                      Mauvaise reponse");
		reponse.setFillColor(Color::Red);
		reponse.setPosition(Vector2f(200,550));
	}
	void arreter(float& heure)
	{
		if (rep)
		{
			if (heure > clicktime+4)
			{
				quiz = false;
				rep = false;
				indquiz++;
				heure = 0;
			}
		}
		else
		{	
			clicktime = heure;
			if ((heure > 10) && (!rep))
			{
				indquiz++;
				quiz = false;
				heure = 0;
			}
		}
	}
	void Settext(String ques[6][6],float x)
	{
		if (x < 400)
			x = 350;
		if (x > 1600)
			x = 1900;
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
				break;
			}
			case 3:
			{
				menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
				break;
			}
			case 4:
			{
				menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
				break;
			}
			case 5:
			{
				menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
				break;
			}

			case 6:
			{
				menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
				break;
			}

			case 7:
			{
				menu[i].setPosition(Vector2f(x - 270, height / (max + 1) * i));
				break;
			}
			}
			reponse.setPosition(x - 70, 550);
			time.setPosition(x + 250, 50);
		}
	}
	void drawit(RenderWindow& window,float heure)
	{
		window.draw(rec);
		for (int i = 0; i < max; i++)
		{
			window.draw(menu[i]);
		}
		time.setString(to_string(int(heure)));
		window.draw(time);
		if (rep)
			window.draw(reponse);
	}
	void moveup()
	{
		cout << "temchy" << endl;
		if (selecteditemindex - 1 >= 2)
		{
			menu[selecteditemindex].setFillColor(Color::White);
			selecteditemindex--;
			menu[selecteditemindex].setFillColor(Color::Red);
		}
	}
	void movedown()
	{
		cout << "temchy" << endl;
		if (selecteditemindex + 1 < max)
		{
			menu[selecteditemindex].setFillColor(Color::White);
			selecteditemindex++;
			menu[selecteditemindex].setFillColor(Color::Red);
		}
	}
	int getselected()
	{
		return (selecteditemindex);
	}
};
