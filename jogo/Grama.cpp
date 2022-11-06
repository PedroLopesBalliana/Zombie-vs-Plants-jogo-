#include "Grama.h"

Grama::Grama()
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Grama3.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
}
Grama::~Grama()
{
}
void Grama::setPosi(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
void Grama::flutua(float deltaTempo)
{
	velocidadeV.y -= 981.0f * deltaTempo;
}
void Grama::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
}
