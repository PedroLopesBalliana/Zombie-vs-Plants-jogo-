#include "Espinho.h"
Espinho::Espinho()
{
	danoso = true;
	if (!texture.loadFromFile("assets/Obstaculos/Floresta/espinhos.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5, 0.40));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
	ferrao = 2;
}
Espinho::~Espinho()
{

}
void Espinho::executar(float deltaTempo)
{
	if (deltaTempo == 1.0f)
	{
		ferrao++;
	}
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
}
int Espinho::getTipo()
{
	return ferrao;
}