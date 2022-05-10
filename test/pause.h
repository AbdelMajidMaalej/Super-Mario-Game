#ifndef PAUSEGAME_H
#define PAUSEGAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
//Declaration Globale
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
		float x=250;
		backgroundrec.setSize(Vector2f(2400,
			static_cast<float>(window.getSize().y)));
		backgroundrec.setFillColor(Color(20, 20, 20, 200));
		// init container
		container.setSize(Vector2f(static_cast<float>(window.getSize().x) / 3.f,
			static_cast<float>(window.getSize().y) + 30));
		container.setFillColor(Color(20, 20, 20, 500));
		container.setPosition(Vector2f(x, 00.f));
		//init text
		if (!font.loadFromFile("./res/Cafe-Matcha.ttf"))
			cout << "Un probleme lors du chargement du font" << endl;
		pausetitle.setFont(font);
		pausetitle.setString("paused");
		pausetitle.setOrigin(pausetitle.getLocalBounds().width / 2,
			pausetitle.getLocalBounds().height / 2);
		pausetitle.setCharacterSize(60);
		pausetitle.setFillColor(Color::White);
		pausetitle.setPosition(x+95, 290);
	}
	~Pausegame()
	{
	}
	//getter paused
	bool ispaused()
	{
		return paused;
	}
	//Update pause selon la position x de Mario
	void update(Event event,Mario& mario,Music& music)
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape )
		{
			paused = !paused;
			if (music.getStatus() == SoundStream::Paused)
				music.play();
			else if (music.getStatus() == SoundStream::Playing)
				music.pause();
		}
		x = mario.getsp().getPosition().x;
		if ((x > 400)&&(x<2000))
		{
			container.setPosition(Vector2f(x - 130, 00.f));
			pausetitle.setPosition(x-30, 290);
		}	
		if (x > 2000)
		{
			container.setPosition(Vector2f(2000 - 130, 00.f));
			pausetitle.setPosition(2000 - 30, 290);
		}
	}
	//dessiner
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