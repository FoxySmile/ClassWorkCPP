#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Button.h"

using namespace std;
class Calculator
{
private:
	sf::RenderWindow window;
	sf::Color gray;
	sf::Color white;
	sf::Color orange;
	vector <Button> keybord;

	void update();
	void processEvent();
	void render();
public:
	Calculator();
	void run();

};

