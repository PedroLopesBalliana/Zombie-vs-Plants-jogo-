#pragma once
#include "Obstaculo.h"

class Grama : public Obstaculo
{
public:
	Grama();
	~Grama();
	void flutua(float deltaTempo);
	void executar(float deltaTempo);
};
