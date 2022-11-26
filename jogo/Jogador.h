#pragma once
#include "Personagem.h"
#include <windows.h>

class Jogador :public Personagem
{
private:
	int charge;
	bool pulou;
	bool atacando;
	sf::Texture ataque;
	bool movimento;
	float pontos;
public:
	Jogador();
	~Jogador();
	void move(float deltaTime);
	void corrigir(float height, float side);
	void executar(float deltaTempo);
	void atacar();
	bool getAtacando();
	float getPontuacao();
	void setMovimento(bool mov);
	void incrementaPontos();
	int getNumVidas();
	void operator--();
	void operator--(int dan);
};
