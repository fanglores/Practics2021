#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 450), "SFML works!");

	int i = 0;
	int x = 100, y = 50;


	while (window.isOpen())
	{
		sf::RectangleShape rect(sf::Vector2f(x, y));
		rect.setFillColor(sf::Color::Green);
		rect.setPosition(2*x, 2*y);
		rect.rotate(i);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(rect);

		window.display();

		i++;

		if (i == 360) i = 0;
	}

	return 0;
}
