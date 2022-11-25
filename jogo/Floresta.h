#pragma once
#include "Fase.h"
#include "Masmorra.h"
class Floresta : public Fase
{
private:
	Grama* gr;
	Espinho* esp;
	Masmorra* fase2;
public:
	Floresta(Jogador* j1, Jogador* j2, GerenciadorGrafico* GE);
	~Floresta();
	void inicializaGrama();
	void inicializaEspinhos();
	void inicializaBulbassauro();
	void inicializaAtirador();
	void inicializaFogo();
	void inicializaElementos();
	void executar();
};
