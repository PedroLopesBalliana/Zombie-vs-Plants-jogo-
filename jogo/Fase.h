#pragma once
#include "Jogador.h"
#include "Atirador.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Ente.h"
#include "Bulbassauro.h"
#include "Grama.h"
#include "Espinho.h"
#include "Fogo.h"
#include <map>

using namespace std;

class Fase : public Ente
{
protected:
	Gerenciadores::GerenciadorColisoes gerenciadorColisoes;
	ListaEntidades *listaEntidades;
	Atirador* ati;
	Jogador* j1;
	Jogador* j2;
	Bulbassauro* bulb;
	Projetil* pr;
	map<string, float> pontuacoes;
	Fogo* fogo;
	virtual void inicializaElementos();
	Memoria memoria;
public:
	Fase();
	~Fase();
	ListaEntidades* getListaEntidades();
	void executar()=0;
	void setPontos();
};
