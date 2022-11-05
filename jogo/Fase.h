#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "Obstaculo.h"
#include "ListaObstaculos.h"
#include "GerenciadorGrafico.h"
#include "Background.h"
#include "GerenciadorColisoes.h"
#include "Ente.h"

using namespace std;

class Fase : public Ente
{
protected:
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades *listaEntidades;
	Entidades::Personagens::Inimigo* i1;
	Jogador* j1;
	Obstaculo* ob1;
	virtual void inicializaElementos();
public:
	Fase();
	~Fase();
	ListaEntidades* getListaEntidades();
	void executar()=0;
};
