#pragma once
#include "Jogador.h"
#include "Atirador.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Ente.h"
#include "Bulbassauro.h"
#include "Grama.h"
#include "Espinhos.h"
#include "Fogo.h"

using namespace std;

class Fase : public Ente
{
protected:
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades *listaEntidades;
	Atirador* ati;
	Jogador* j1;
	Bulbassauro* bulb;
	Grama* gr;
	Projetil* pr;
	Espinhos* esp;
	Fogo* fogo;
	virtual void inicializaElementos();
public:
	Fase();
	~Fase();
	ListaEntidades* getListaEntidades();
	void executar()=0;
};
