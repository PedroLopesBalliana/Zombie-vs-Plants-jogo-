#pragma once
#include "Entidade.h"

class Projetil : public Entidade
{
private:
public:
	Projetil();
	~Projetil();
	void executar(float deltaTempo, sf::Vector2f posicao);
};
