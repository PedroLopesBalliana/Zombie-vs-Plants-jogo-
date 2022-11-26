#pragma once
#include "Entidade.h"
#include "Jogador.h"
class Obstaculo : public Entidade
{
protected:
	bool danoso;
public:
	Obstaculo();
	~Obstaculo();
	virtual void flutua(float deltaTempo);
	virtual void executar(float deltaTempo);
	virtual bool getDanoso();
	virtual int getTipo();
	virtual void danificar(Jogador* jog);
};
