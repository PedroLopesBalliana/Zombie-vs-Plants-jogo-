#pragma once
#include "Entidade.h"

class Projetil : public Entidade
{
private:
public:
	Projetil();
	~Projetil();
	void executar(float deltaTempo, sf::Vector2f posicao);
	void atirar(sf::Vector2f posicao);
};
