#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
private:
public:
	Obstaculo();
	~Obstaculo();
	void setPosi(float x, float y);
	void flutua(float deltaTempo);
	void executar(float deltaTempo);
};
