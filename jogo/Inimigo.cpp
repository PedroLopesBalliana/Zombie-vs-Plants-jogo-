#include "Inimigo.h"
Entidades::Personagens::Inimigo::Inimigo(): Entidade::Entidade()
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}
Entidades::Personagens::Inimigo::~Inimigo()
{

}