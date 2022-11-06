#pragma once
#include "Jogador.h"
#include "Atirador.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Ente.h"
#include "Bulbassauro.h"

using namespace std;

class Fase : public Ente
{
protected:
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades *listaEntidades;
	Atirador* i1;
	Jogador* j1;
	Bulbassauro* i2;
	Obstaculo*ob1, * obteste;
	Projetil* pr;
	virtual void inicializaElementos();
public:
	Fase();
	~Fase();
	ListaEntidades* getListaEntidades();
	void executar()=0;
};
