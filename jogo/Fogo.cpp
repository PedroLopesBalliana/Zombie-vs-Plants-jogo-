#include "Fogo.h"

Fogo::Fogo() : labareda(0.5)
{
	if (!texture.loadFromFile("assets/Obstaculos/Floresta/fogo2.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5, 0.5));
	sprite.setPosition(sf::Vector2f(700.f, 450.f));
	danoso = true;
}
Fogo::~Fogo()
{

}
void Fogo::executar(float deltaTempo)
{
	if (deltaTempo == 1.0f)
	{
		labareda = labareda + 0.5;
		sprite.scale(sf::Vector2f(labareda, 1));
	}
	if (labareda > 2)
	{
		labareda = 0.5;
		sprite.scale(sf::Vector2f(0.15, 1));
	}
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	
}