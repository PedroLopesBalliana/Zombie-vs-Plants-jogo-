#pragma once
#include "Entidade.h"
 // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidade::Entidade():Ente(), gravid(981.f)
{

}
Entidade::~Entidade()
{

}
//sf::Vector2f Entidade::getFronteiras()
//{
//	return sprite.getPosition();
//}
sf::Sprite Entidade::getSprite()
{
	return sprite;
}
sf::FloatRect Entidade::getSpriteBounds()
{
	return sprite.getGlobalBounds();
}
void Entidade::gravidade(float deltaTempo)
{
	velocidadeV.y += gravid * deltaTempo;
}
void Entidade::executar(float deltaTempo)
{

}
void Entidade::scaleSprite(const float x, const float y)
{
	sprite.scale(x, y);
}
void Entidade::setPosi(const float x, const float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
void Entidade::setSpeed(const float v)
{
	if(velocidade > 0)
		velocidade = velocidade - (v/50);
}
void Entidade::danificar()
{

}