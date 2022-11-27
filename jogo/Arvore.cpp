#pragma once
#include "Arvore.h"

Entidades::Personagens::Arvore::Arvore() : Inimigo(), Bulbassauro(), Atirador()
{
	if (!texture.loadFromFile("assets/Inimigos/Arvoreee.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!envenenar.loadFromFile("assets/Inimigos/entespikes.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture, true);
	sprite.scale(sf::Vector2f(0.5, 0.5));
	sprite.setPosition(sf::Vector2f(300.f, 325.f));
	Personagem::facingLeft=false;
	Entidade::velocidadeV.y = 50.f;
	Entidade::velocidade = 300.f;
	Personagem::num_vidas = 1;
	raiva = 1;
}
Entidades::Personagens::Arvore::~Arvore()
{

}
void Entidades::Personagens::Arvore::pular()
{
	Entidade::velocidadeV.y = -sqrtf(2.0f * gravid * (raiva * 100.0f));
}
void Entidades::Personagens::Arvore::mover()
{
	if (sprite.getPosition().x < limEsq && !Personagem::facingLeft)
	{
		Personagem::facingLeft = true;
		sprite.move(sf::Vector2f(300.0f, 0.f));
		sprite.scale(-1, 1);
	}
	if (sprite.getPosition().x > limDir && Personagem::facingLeft)
	{
		Personagem::facingLeft = false;
		sprite.move(sf::Vector2f(-300.0f, 0.f));
		sprite.scale(-1, 1);
	}
	if (!Personagem::facingLeft)
		sprite.move(sf::Vector2f(-3.0f, 0.f));
	else
		sprite.move(sf::Vector2f(3.0f, 0.f));
	if (sprite.getPosition().y > 525.f)
	{
		pular();
	}

}
void Entidades::Personagens::Arvore::executar(const float deltaTempo)
{
	if (Personagem::num_vidas > 0)
	{
		float aux;
		float centroX, centroY;
		sf::Vector2f posi;
		Entidade::gravidade(deltaTempo);
		imprimirSe();
		mover();
		sprite.move(Entidade::velocidadeV * 0.01f);
		aux = rand() % 500;
		if (rand() % 2)
		{
			aux = -aux;
		}
		tiro->setForca(aux);
		if (Personagem::facingLeft)
		{
			centroX = sprite.getPosition().x - (sprite.getGlobalBounds().width / 2);
			centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
		}
		else
		{
			centroX = sprite.getPosition().x + (sprite.getGlobalBounds().width / 2);
			centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
		}
		posi.x = centroX;
		posi.y = centroY;
		tiro->executar(0.001);
		charge++;
		if (charge == 500)
		{
			sprite.setTexture(envenenar);
			Entidades::Obstaculos::Pedra::setVeneno(true);
			charge = 0;
		}
		if (charge == 100)
		{
			sprite.setTexture(texture);
			Entidades::Obstaculos::Pedra::setVeneno(false);
		}
	}
	else
	{
		sprite.move(1000.f, 1000.f);
		tiro->executar(deltaTempo);
	}
}

void Entidades::Personagens::Arvore::operator--()
{
	if (quant > 4)
	{
		sprite.setTexture(envenenar);
		Entidades::Obstaculos::Pedra::setVeneno(true);
	}
	else
	{
		Personagem::num_vidas--;
		quant--;
	}
}
void Entidades::Personagens::Arvore::danificar(Jogador* jog)
{
		jog->operator--(10);
	if (jog->getSentido())
		jog->corrigir(20.f, 50.f);
	else
		jog->corrigir(20.f, -50.f);
	raiva += 0.5;
}
