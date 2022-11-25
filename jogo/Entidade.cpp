#pragma once
#include "Entidade.h"
 // ficou muito estranho Entidades::Entidade::Entidade() por exemplo
Entidade::Entidade():Ente()
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
	velocidadeV.y += 981.0f * deltaTempo;
}
void Entidade::executar(float deltaTempo)
{

}
void Entidade::scaleSprite(float x, float y)
{
	sprite.scale(x, y);
}
void Entidade::setPosi(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
void Entidade::setSpeed(float v)
{
	if(velocidade > 0)
		velocidade = velocidade - (v/50);
}
int Entidade::getPontuacao()
{
	return pontuacao;
}
void Entidade::danificar()
{

}
int Entidade::pontuacao = 0;