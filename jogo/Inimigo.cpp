#include "Inimigo.h"
Inimigo::Inimigo(): Entidade::Entidade()
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 200.f));
}
Inimigo::~Inimigo()
{

}
void Inimigo::gravidade(float deltaTempo)
{
	sprite.move(sf::Vector2f(0.f, 0.15f));
	flutua();
}
void Inimigo::flutua()
{
	sprite.move(sf::Vector2f(0.f, -0.15f));
}
void Inimigo::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
}