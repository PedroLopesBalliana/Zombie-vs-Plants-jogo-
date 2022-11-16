#include "Projetil.h"

Projetil::Projetil()
{
	if (!texture.loadFromFile("assets/Inimigos/projetil.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1.5, 1.5));
	sprite.setPosition(sf::Vector2f(700.f, 100.f));
	velocidadeV.y = 50.0f;
}
Projetil::~Projetil()
{

}
void Projetil::executar(float deltaTempo, sf::Vector2f posicao)
{
	gravidade(deltaTempo);
	if (sprite.getPosition().y > 750.f)
	{
		sprite.setPosition(posicao);
		velocidadeV.y = -(abs(forca)/2);
		velocidadeV.x = forca;
	}
	sprite.move(velocidadeV * deltaTempo);
	imprimirSe();
}
void Projetil::setForca(float f)
{
	forca = f;
}