#pragma once
#include "Entidade.h"

class Projetil : public Entidade
{
private:
public:
	Projetil();
	~Projetil();
	void executar(float deltaTempo);
	void gravidade(float deltaTempo);
	void atirar(sf::Vector2f posicao);
};
