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
	Text menu[MAX], karim, yasmine, majid, parag, retour;
	SoundBuffer click;
	Sound clicksound;
	Texture backgd;
	Sprite sbackgd;

public:
	mainmenu()
	{
		if (!backgd.loadFromFile("./res/mario0.png"))
			cout << "Un probleme lors du chargement du bg" << endl;
		sbackgd.setTexture(backgd);
		backgd.setSmooth(true);
		if (!click.loadFromFile("./res/sound_ex_machina_Button_Blip.ogg"))
			cout << "probleme avec le sound" << endl;

		clicksound.setBuffer(click);
		if (!font.loadFromFile("./res/Cafe-Matcha.ttf"))
			cout << "Un probleme lors du chargement du font" << endl;
		menu[0].setFont(font);
		menu[0].setCharacterSize(65);
		menu[0].setFillColor(Color::White);
		menu[0].setPosition(800 / 2 - 240, 174);
		menu[0].setString("NEW GAME");

		menu[1].setFont(font);
		menu[1].setCharacterSize(65);
		menu[1].setFillColor(Color::Black);
		menu[1].setPosition(800 / 2 - 240, 304);
		menu[1].setString("ABOUT US");

		menu[2].setFont(font);
		menu[2].setCharacterSize(65);
		menu[2].setFillColor(Color::Black);
		menu[2].setPosition(800 / 2 - 190, 434);
		menu[2].setString("EXIT");

		selecteditm = 0;

		parag.setFont(font);
		parag.setCharacterSize(30);
		parag.setFillColor(Color::Black);
		parag.setPosition(800 / 2 - 330, 124);
		parag.setString("Ce Jeu intitule << Smart Mario >> \n developpe en C++ et SFML par \n des eleves ingenieurs de l'ENSI\n\n\n\n\n\n            dans le cadre \n       d'un projet de classe ");
		//Karim
		karim.setFont(font);
		karim.setCharacterSize(35);
		karim.setFillColor(Color::Color(50, 50, 200));
		karim.setPosition(800 / 2 - 270, 244);
		karim.setString("    Karim Hmidi");
		//yasmine
		yasmine.setFont(font);
		yasmine.setCharacterSize(35);
		yasmine.setFillColor(Color::Color(50, 50, 170));
		yasmine.setPosition(800 / 2 - 270, 294);
		yasmine.setString("Yasmine Boubaker");
		//majid
		majid.setFont(font);
		majid.setCharacterSize(35);
		majid.setFillColor(Color::Color(50, 50, 230));
		majid.setPosition(800 / 2 - 270, 344);
		majid.setString("Abdel Majid Maalej");
		//button return
		retour.setFont(font);
		retour.setCharacterSize(45);
		retour.setFillColor(Color::White);
		retour.setPosition(800 / 2 - 220, 494);
		retour.setString("RETURN");


	}
	~mainmenu()
	{
	}
	//Update main menu 
	void update(Mario& mario, Music& music,float x)
	{
		if (mario.isdead())
		{

			if (music.getStatus() == SoundStream::Paused)
				music.play();
			else if (music.getStatus() == SoundStream::Playing)
				music.pause();
		}
		if (x > 400)
		{
			sbackgd.setPosition(Vector2f(x - 382, 00.f));
			menu[0].setPosition(x - 240, 174);
			menu[1].setPosition(x - 240, 304);
			menu[2].setPosition(x - 190, 434);
			parag.setPosition(x - 330, 124);
			karim.setPosition(x - 270, 244);
			yasmine.setPosition(x - 270, 294);
			majid.setPosition(x - 270, 344);
			retour.setPosition(x - 220, 494);
		}
		if (x > 2000)
		{
			sbackgd.setPosition(Vector2f(2000 - 400, 00.f));
			menu[0].setPosition(2000 - 240, 174);
			menu[1].setPosition(2000 - 240, 304);
			menu[2].setPosition(2000 - 190, 434);
			parag.setPosition(2000 - 330, 124);
			karim.setPosition(2000 - 270, 244);
			yasmine.setPosition(2000 - 270, 294);
			majid.setPosition(2000 - 270, 344);
			retour.setPosition(2000 - 220, 494);
		}
	}
	//Button up
	void moveup(bool test, bool aboutus)
	{
		if (!aboutus)
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
	}
	//Button down
	void movedown(bool test, bool aboutus)
	{
		if (!aboutus)
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
	}
	// Dessinr
	void drawmenu(RenderWindow& window, bool test)
	{
		window.draw(sbackgd);
		if (!test)
		{
			window.draw(sbackgd);
			for (int i = 0; i < MAX; i++)
			{
				window.draw(menu[i]);
			}
		}
		else
		{
			window.draw(parag);
			window.draw(karim);
			window.draw(yasmine);
			window.draw(majid);
			window.draw(retour);
		}
	}
	//choisir un boutton
	int getitempressed()
	{
		return selecteditm;
	}
};
#endif // !MAINMENU_H