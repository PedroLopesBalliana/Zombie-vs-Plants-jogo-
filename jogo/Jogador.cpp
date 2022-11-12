#include "Jogador.h"
Jogador::Jogador() :Personagem(), pulou(false), charge(50), atacando(false)
{
	if (!texture.loadFromFile("assets/Zumbi_Jogador/zombieSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!ataque.loadFromFile("assets/Zumbi_Jogador/zombieattack.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 0.f));
	facingLeft = true;
	velocidade = 300.0f;
	num_vidas = 100;
}
Jogador::~Jogador()
{
}
void Jogador::move(float deltaTempo)
{
	velocidadeV.x = 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocidadeV.x += velocidade;
		if (facingLeft)
		{
			sprite.scale(-1, 1);
			sprite.move(sf::Vector2f(50.0f, 0.f));
			facingLeft = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocidadeV.x -= velocidade;
		if (!facingLeft)
		{
			sprite.move(sf::Vector2f(-50.0f, 0.0f));
			sprite.scale(-1, 1);
			facingLeft = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pulou)
	{
		pulou = true;
		velocidadeV.y = -sqrtf(2.0f * 981.0f * 100.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && charge == 50)
	{
		atacar();
	}

	sprite.move(velocidadeV * deltaTempo);
}
void Jogador::corrigir(float height, float side)
{
	sprite.move(sf::Vector2f(side, -height ));
	velocidadeV.y = 0.f;
	pulou = false;
}
void Jogador::executar(float deltaTempo)
{
	move(deltaTempo);
	imprimirSe();
	gravidade(deltaTempo);
	if (charge < 50)
	{
		charge++;
	}
	if (charge == 50)
	{
		sprite.setTexture(texture);
		atacando = false;
	}
	printf("charge %d \n", charge);
}
void Jogador::operator--()
{
	num_vidas--;
	printf("jogador num_vidas : %d \n", num_vidas);
}

void Jogador::atacar()
{
	sprite.setTexture(ataque);
	atacando = true;
	charge = 0;
}
bool Jogador::getAtacando()
{
	return atacando;
}