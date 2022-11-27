#include "Espinho.h"
Entidades::Obstaculos::Espinho::Espinho()
{
	danoso = true;
	if (!texture.loadFromFile("assets/Obstaculos/Floresta/espinhos.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5, 0.40));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
	ferrao = 2.0;
}
Entidades::Obstaculos::Espinho::~Espinho()
{

}
void Entidades::Obstaculos::Espinho::executar(const float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	ferrao += 0.001;
}
const float Entidades::Obstaculos::Espinho::getTipo()
{
	return ferrao;
}
void Entidades::Obstaculos::Espinho::danificar(Entidades::Personagens::Jogador* jog)
{
	ferrao++;
	jog->operator--(ferrao);
	jog->corrigir(20.f, 0.f);
}