#include <SFML/Graphics.hpp>

/*
Задание 12
Разработать при помощи библиотеки SFML минимальную программу, которая будет позволять
Запускать изменение фигуры на экран по нажатию одной клавиши и останавливать по другой

Вариант 1
Вращаем прямоугольник
*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 450), "SFML works!");

	const int x = 100, y = 50;
	bool rot_f = false;

	//rectangle initiation
	sf::RectangleShape rect(sf::Vector2f(x, y));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(2 * x, 3 * y);

	while (window.isOpen())
	{
		window.clear();
		window.draw(rect);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}

			//right and left arrows control movement
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Right) rot_f = true;
				if (event.key.code == sf::Keyboard::Left) rot_f = false;
				break;
			}
		}

		if (rot_f) rect.rotate(1);

		//little smooth for the movement
		sf::sleep(sf::milliseconds(5));
	}

	return 0;
}
