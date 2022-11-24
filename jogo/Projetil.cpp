#include "Projetil.h"

Projetil::Projetil()
{
	if (!texture.loadFromFile("assets/Inimigos/projetil5.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!maca.loadFromFile("assets/Inimigos/applee.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.17, 0.17));
	sprite.setPosition(sf::Vector2f(700.f, 100.f));
	velocidadeV.y = 50.0f;
}
Projetil::~Projetil()
{

}
void Projetil::executar(float deltaTempo, sf::Vector2f posicao)
{
	//sprite.setTexture(maca);
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
void Projetil::setMaca()
{
	sprite.setTexture(maca);
	sprite.setScale(sf::Vector2f(0.5, 0.5));
}