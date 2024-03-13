#include "Button.h"

Button::Button(
	sf::Vector2f size,
	sf::Color color,
	sf::Vector2f position)
{
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(position);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
