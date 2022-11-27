#include "Projetil.h"

Entidades::Projetil::Projetil()
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
Entidades::Projetil::~Projetil()
{

}
void Entidades::Projetil::executar(const float deltaTempo, sf::Vector2f posicao)
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
void Entidades::Projetil::setForca(float f)
{
	forca = f;
}
void Entidades::Projetil::setMaca()
{
	sprite.setTexture(maca);
	sprite.setScale(sf::Vector2f(0.5, 0.5));
}
void Entidades::Projetil::danificar(Entidades::Personagens::Jogador* jog)
{
	jog->operator--();
	if (jog->getSentido())
	jog->corrigir(0.f, 30.f);
	else
	jog->corrigir(0.f, -30.f);
}
