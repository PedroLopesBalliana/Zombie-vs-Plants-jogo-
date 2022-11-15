#include "Fogo.h"

Fogo::Fogo() : labareda(0.5)
{
	if (!texture.loadFromFile("assets/Obstaculos/Floresta/fogo2.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.0, 0.40));
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
		sprite.setScale(sf::Vector2f(labareda, 0.40));
	}
	if (labareda > 1.8)
	{
		labareda = 0.5;
		sprite.setScale(sf::Vector2f(1.0, 0.40));
	}
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	
}
int Fogo::getTipo()
{
	return labareda;
}