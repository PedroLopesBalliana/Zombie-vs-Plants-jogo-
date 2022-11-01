#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	body.setFillColor(sf::Color::Red);
	body.setPosition(sf::Vector2f(300.f, 100.f));
}
Obstaculo::~Obstaculo()
{

}
void Obstaculo::setPosi(float x, float y)
{
	body.setPosition(sf::Vector2f(x, y));
}