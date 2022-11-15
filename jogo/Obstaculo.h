#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade
{
protected:
	bool danoso;
	int tipo;
public:
	Obstaculo();
	~Obstaculo();
	virtual void flutua(float deltaTempo);
	virtual void executar(float deltaTempo);
	virtual bool getDanoso();
	virtual int getTipo();
};
