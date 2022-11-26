#include "Bulbassauro.h"
Bulbassauro::Bulbassauro(): Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/bublbassauroSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1));
	sprite.setPosition(sf::Vector2f(700.f, 685.f));
	raiva = 1.0;
}
Bulbassauro::~Bulbassauro()
{

}
void Bulbassauro::executar(float deltaTempo)
{
	if (num_vidas > 0)
	{
		gravidade(deltaTempo);
		imprimirSe();
		mover();
		raiva += 0.001;
	}
	else
	{
		sprite.move(sf::Vector2f(1000, 1000));
	}
}
void Bulbassauro::mover()
{
	if (sprite.getPosition().x < limEsq && !facingLeft)
	{
		facingLeft = true;
		sprite.scale(-1, 1);
	}
	if (sprite.getPosition().x > limDir && facingLeft)
	{
		facingLeft = false;
		sprite.scale(-1, 1);
	}
	if (!facingLeft)
		sprite.move(sf::Vector2f(-3.0f * raiva, 0.f));
	else
		sprite.move(sf::Vector2f(3.0f * raiva, 0.f));
}

void Bulbassauro::setLimites(float esq, float dir)
{
	limEsq = esq;
	limDir = dir;
}
void Bulbassauro::danificar(Jogador* jog)
{
	raiva = raiva + 0.5f;
	jog->operator--(3);
	if (raiva > 3.0)
		raiva = 1.0;
	if (jog->getSentido())
		jog->corrigir(10.f, 10.f);
	else
		jog->corrigir(10.f, -10.f);
}

