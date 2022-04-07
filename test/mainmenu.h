#ifndef MAINMENU_H
#define MAINMENU_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#define MAX 3 
using namespace sf;
using namespace std;
class mainmenu
{
private:
	int selecteditm;
	Font font;
	Text menu[MAX];
	SoundBuffer click;
	Sound clicksound;
public:
	mainmenu()
	{
		if (!click.loadFromFile("./res/sound_ex_machina_Button_Blip.ogg"))
			cout << "probleme avec le sound" << endl;

		clicksound.setBuffer(click);
		if (!font.loadFromFile("./res/Cafe-Matcha.ttf"))
			std::cout << "Un probleme lors du chargement du font" << endl;
		menu[0].setFont(font);
		menu[0].setCharacterSize(30);
		menu[0].setFillColor(Color::White);
		menu[0].setPosition(800 / 2 - 30, 608 / (MAX + 1) * 1);
		menu[0].setString("NEW GAME");

		menu[1].setFont(font);
		menu[1].setCharacterSize(30);
		menu[1].setFillColor(Color::Black);
		menu[1].setPosition(800 / 2 - 30, 608 / (MAX + 1) * 2);
		menu[1].setString("SETTINGS");

		menu[2].setFont(font);
		menu[2].setCharacterSize(30);
		menu[2].setFillColor(Color::Black);
		menu[2].setPosition(800 / 2 - 30, 608 / (MAX + 1) * 3);
		menu[2].setString("EXIT");

		selecteditm = 0;
	}
	~mainmenu()
	{
	}
	void moveup(bool test)
	{
		if (!test)
		{
			if (selecteditm - 1 >= 0)
			{
				menu[selecteditm].setFillColor(Color::Black);
				selecteditm--;
				menu[selecteditm].setFillColor(Color::White);
			}
			clicksound.play();
		}
	}
	void movedown(bool test)
	{
		if (!test)
		{
			if (selecteditm + 1 < MAX)
			{
				menu[selecteditm].setFillColor(Color::Black);
				selecteditm++;
				menu[selecteditm].setFillColor(Color::White);
			}
			clicksound.play();
		}	
	}
	void drawmenu(RenderWindow& window)
	{
		for (int i = 0; i < MAX; i++)
		{
			window.draw(menu[i]);
		}
	}
	int getitempressed()
	{
		return selecteditm;
	}
};
#endif // !MAINMENU_H
