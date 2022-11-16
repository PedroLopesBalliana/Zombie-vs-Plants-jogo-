#pragma once
#include "Entidade.h"

class Projetil : public Entidade
{
private:
	float forca;
public:
	Projetil();
	~Projetil();
	void executar(float deltaTempo, sf::Vector2f posicao);
	void setForca(float f);
};
