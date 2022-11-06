#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
private:
public:
	Obstaculo();
	~Obstaculo();
	virtual void setPosi(float x, float y);
	virtual void flutua(float deltaTempo);
	virtual void executar(float deltaTempo);
};
