#ifndef PAUSEGAME8H
#define PAUSEGAME_H
#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>


using namespace sf;
using namespace std;


bool paused = false;
int x = 0;

class Pausegame
{
private:

	Text pausetitle;
	RectangleShape backgroundrec;
	RectangleShape container;
	Font font;

public:
	Pausegame(RenderWindow& window)
	{	//init background
		backgroundrec.setSize(Vector2f(static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)));
		backgroundrec.setFillColor(Color(20, 20, 20, 200));
		// init container
		container.setSize(Vector2f(static_cast<float>(window.getSize().x) / 3.f,
			static_cast<float>(window.getSize().y) + 30));
		container.setFillColor(Color(20, 20, 20, 500));
		container.setPosition(static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f, 00.f);
		//init text
		if (!font.loadFromFile("./res/Cafe Matcha.ttf"))
			cout << "Un probleme lors du chargement du font" << endl;
		pausetitle.setFont(font);
		pausetitle.setString("paused");
		pausetitle.setOrigin(pausetitle.getLocalBounds().width / 2,
			pausetitle.getLocalBounds().height / 2);
		pausetitle.setCharacterSize(60);
		pausetitle.setFillColor(Color::White);
		pausetitle.setPosition(365, 290);
	}

	~Pausegame()
	{
	}
	void update(Event event)
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && x == 0)
		{
			paused = !paused;
		}
	}
	void drawit(RenderWindow& window)
	{
		if (paused)
		{

			window.draw(backgroundrec);
			window.draw(container);
			window.draw(pausetitle);
		}
	}
};

#endif