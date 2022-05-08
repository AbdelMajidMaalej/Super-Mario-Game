#ifndef WINMENU_H
#define WINMENU_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
class Winmenu
{
private:
	Text wintitle;
	RectangleShape bgover;
	RectangleShape containerover;
	Text go[2];
	Font font;
	int selecteditm;
	SoundBuffer click;
	Sound clicksound;
	Texture bg;
	Sprite sbg;
public:
	Winmenu(RenderWindow& window)
	{	//init background
		if (!bg.loadFromFile("./res/win.jpg"))
			cout << "Un probleme de chargement pic Win" << endl;
		sbg.setTexture(bg);
		float x = 250;
		bgover.setSize(Vector2f(2400,
			static_cast<float>(window.getSize().y)));
		bgover.setFillColor(Color(20, 20, 20, 100));
		// init container
		containerover.setSize(Vector2f(static_cast<float>(window.getSize().x) / 3.f,
			static_cast<float>(window.getSize().y) + 30));
		containerover.setFillColor(Color(20, 20, 20, 500));
		containerover.setPosition(Vector2f(255, 00.f));
		//init text
		if (!font.loadFromFile("./res/Cafe-Matcha.ttf"))
			cout << "Un probleme lors du chargement du font" << endl;
		wintitle.setFont(font);
		wintitle.setString("GAME OVER");
		wintitle.setOrigin(wintitle.getLocalBounds().width / 2 + 15,
		wintitle.getLocalBounds().height / 2 + 70);
		wintitle.setCharacterSize(60);
		wintitle.setFillColor(Color::White);
		wintitle.setPosition(370, 150);

		if (!click.loadFromFile("./res/sound_ex_machina_Button_Blip.ogg"))
			cout << "probleme avec le sound" << endl;

		clicksound.setBuffer(click);

		go[0].setFont(font);
		go[0].setCharacterSize(30);
		go[0].setFillColor(Color::White);
		go[0].setPosition(370, 450);
		go[0].setString("MAIN MENU");




		selecteditm = 0;

	}

	~Winmenu()
	{
	}
	int getitempressed()
	{
		return selecteditm;
	}
	void update(Mario& mario, Music& music,bool win)
	{
		if (win)
		{
			music.pause();
		}
		x = mario.getsp().getPosition().x;
		if (x > 400)
		{
			containerover.setPosition(Vector2f(x - 140, 00.f));
			wintitle.setPosition(x - 52, 290);
			go[0].setPosition(x - 55, 525);

		}
		if (x > 2000)
		{
			containerover.setPosition(Vector2f(2000 - 140, 00.f));
			wintitle.setPosition(2000 - 52, 290);
			go[0].setPosition(2000 - 55, 525);

		}
	}
	void drawover(RenderWindow& window)
	{
		window.draw(bgover);
		window.draw(containerover);
		window.draw(sbg);
		window.draw(wintitle);
		window.draw(go[0]);
		window.display();
	}


};
#endif