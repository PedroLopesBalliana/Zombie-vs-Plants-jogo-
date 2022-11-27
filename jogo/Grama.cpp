#include "Grama.h"

Entidades::Obstaculos::Grama::Grama(): aderencia(0)
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Grama3.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(0.125f, 0.125f);
	sprite.setPosition(sf::Vector2f(300.f, 100.f));

}
Entidades::Obstaculos::Grama::~Grama()
{
}
void Entidades::Obstaculos::Grama::executar(const float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	aderencia += 0.001;
}
const float Entidades::Obstaculos::Grama::getTipo()
{
	return aderencia;
}
void Entidades::Obstaculos::Grama::danificar(Entidades::Personagens::Jogador* jog)
{
	aderencia++;
	jog->setSpeed(aderencia);
}
