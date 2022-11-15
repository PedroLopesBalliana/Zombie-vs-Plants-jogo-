#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "Jogador.h"
class Inimigo : public Personagem
{
private:
	static int quant;
protected:
	bool goingUp;
	int tipo;
public:
	Inimigo();
	~Inimigo();
	virtual void flutua();
	virtual void executar(float deltaTempo);
	virtual void mover(int tipo);
	void setTipo(int ti);
	static int getQuant();
	void operator--();
};
