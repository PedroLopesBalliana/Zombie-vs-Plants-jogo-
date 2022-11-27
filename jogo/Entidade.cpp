#pragma once
#include "Entidade.h"
 // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidades::Entidade::Entidade():Ente(), gravid(981.f)
{

}
Entidades::Entidade::~Entidade()
{

}
//sf::Vector2f Entidade::getFronteiras()
//{
//	return sprite.getPosition();
//}
sf::Sprite Entidades::Entidade::getSprite()
{
	return sprite;
}
sf::FloatRect Entidades::Entidade::getSpriteBounds()
{
	return sprite.getGlobalBounds();
}
void Entidades::Entidade::gravidade(float deltaTempo)
{
	velocidadeV.y += gravid * deltaTempo;
}
void Entidades::Entidade::executar(float deltaTempo)
{

}
void Entidades::Entidade::scaleSprite(const float x, const float y)
{
	sprite.scale(x, y);
}
void Entidades::Entidade::setPosi(const float x, const float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
void Entidades::Entidade::setSpeed(const float v)
{
	if(velocidade > 0)
		velocidade = velocidade - (v/50);
}
void Entidades::Entidade::danificar()
{

}