#pragma once
#include "Entidade.h"
Entidade::Entidade():
	body(sf::Vector2f(100.f, 100.f))
{
}
Entidade::~Entidade()
{

}
void Entidade::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
sf::Vector2f Entidade::getFronteiras()
{
	return body.getPosition();
}
void Entidade::draw()
{
	window->draw(body);
}