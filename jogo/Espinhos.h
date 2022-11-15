#pragma once
#include "Obstaculo.h"

class Espinhos : public Obstaculo
{
private:
	int ferrao;
public:
	Espinhos();
	~Espinhos();
	void executar(float deltaTempo);
	int getTipo();
};
