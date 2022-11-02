#pragma once
#include "Entidade.h"
using namespace Entidades; // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidade::Entidade() 
{
	sprite.setPosition(sf::Vector2f(100.f, 100.f));
}
Entidade::~Entidade()
{

}
sf::Vector2f Entidade::getFronteiras()
{
	return sprite.getPosition();
}
sf::Sprite Entidade::getSprite()
{
	return sprite;
}