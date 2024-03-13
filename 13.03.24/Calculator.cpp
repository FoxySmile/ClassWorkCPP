#include "Calculator.h"

Calculator::Calculator() : window(sf::VideoMode(398, 598), "I-calculator "),
gray(200, 200, 200, 255),
white(20, 20, 20, 255),
orange(198, 114, 57, 255)
{
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			keybord.push_back(Button(sf::Vector2f(98, 98), gray, sf::Vector2f(j * 100, i * 100)));
		}
	}
}

void Calculator::update()
{
}

void Calculator::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Calculator::render()
{
	window.clear();
	for (auto el : keybord) {
		el.draw(window);
	}
	window.display();
}

void Calculator::run()
{
	while (window.isOpen()) {
		processEvent();
		render();
		update();
	}
}
