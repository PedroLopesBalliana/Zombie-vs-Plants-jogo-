#include "Obstaculo.h"

Obstaculo::Obstaculo(): danoso(false)
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Grama3.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.25, 0.10));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
}
Obstaculo::~Obstaculo()
{
}
void Obstaculo::setPosi(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
void Obstaculo::flutua(float deltaTempo)
{
	velocidadeV.y -= 981.0f * deltaTempo;
}
void Obstaculo::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
}
bool Obstaculo::getDanoso()
{
	return danoso;
}