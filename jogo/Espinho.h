#pragma once
#include "Obstaculo.h"

class Espinho : public Obstaculo
{
private:
	int ferrao;
public:
	Espinho();
	~Espinho();
	void executar(float deltaTempo);
	int getTipo();
};
