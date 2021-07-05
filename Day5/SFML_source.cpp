#include <SFML/Graphics.hpp>

int main()
{
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

int i = 0;

while (window.isOpen())
{
sf::CircleShape shape(100.f+i);
shape.setFillColor(sf::Color::Green);

sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

window.clear();

window.draw(shape);

window.display();

i++;

if (i == 200)
i = 0;
}

return 0;
}
