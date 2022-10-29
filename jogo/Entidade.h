#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Entidade
{
protected:
	sf::RectangleShape body;
	sf::RenderWindow *window;
public:
	Entidade();
	~Entidade();
	void setWindow(sf::RenderWindow* window);
	void draw();
};