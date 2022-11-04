#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "Obstaculo.h"
#include "ListaObstaculos.h"
#include "GerenciadorGrafico.h"
#include "Background.h"

using namespace std;

class Fase
{
protected:
	GerenciadorGrafico* gerenciadorGrafico;
	ListaEntidades *listaEntidades;
	//ListaInimigos *listainimigos;
	//ListaObstaculos *listaObstaculos;
	Entidades::Personagens::Inimigo* i1;
	Jogador* j1;
	Obstaculo* ob1;
	Background* background;
	virtual void inicializaElementos();
public:
	Fase();
	~Fase();
	ListaEntidades* getListaEntidades();
	//ListaInimigos* getListaInimigos();
	//ListaObstaculos* getListaObstaculos();
	virtual void faseExecutar() = 0;
};
