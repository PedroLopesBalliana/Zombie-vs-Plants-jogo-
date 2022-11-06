#pragma once
#include "Entidade.h"
#include <windows.h>

class Jogador :public Entidade
{
private:
	bool facingLeft;
	float jump;
	sf::Vector2f velocidadeV;
	float velocidade;
public:
	bool pulou;
	Jogador();
	~Jogador();
	void move(float deltaTime);
	float getY();
	void corrigir(float height);
	void gravidade(float DeltaTempo);
	void flutua();
	void pula();
	void executar(float deltaTempo);
};
