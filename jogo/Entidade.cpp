#pragma once
#include "Entidade.h"
using namespace Entidades; // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidade::Entidade() :
	window(NULL)
{
	sprite.setPosition(sf::Vector2f(100.f, 100.f));
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
	return sprite.getPosition();
}
void Entidade::draw()
{
	window->draw(sprite);
}