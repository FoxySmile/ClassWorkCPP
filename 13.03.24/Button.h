#pragma once

#include "SFML/Graphics.hpp"
class Button
{
private:
	sf::RectangleShape shape;
public:
	Button(sf::Vector2f size, sf::Color color, sf::Vector2f position);
	void draw(sf::RenderWindow& window);
};

