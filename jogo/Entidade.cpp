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
