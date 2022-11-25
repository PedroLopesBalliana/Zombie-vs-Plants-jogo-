#pragma once
#include "Obstaculo.h"

class Grama : public Obstaculo
{
private:
	int aderencia;
public:
	Grama();
	~Grama();
	void executar(float deltaTempo);
	int getTipo();
};
