#include "Projetil.h"

Projetil::Projetil()
{
	if (!texture.loadFromFile("assets/Inimigos/projetil.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(1100.f, 1100.f));
	velocidade = 0.0f;
}
Projetil::~Projetil()
{

}
void Projetil::executar(float deltaTempo)
{

}
void Projetil::gravidade(float deltaTempo)
{
	velocidadeV.y += 981.0f * deltaTempo;
}
void Projetil::atirar(sf::Vector2f posicao)
{
	sprite.setPosition(posicao);
}