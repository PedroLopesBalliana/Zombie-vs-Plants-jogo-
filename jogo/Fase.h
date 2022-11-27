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

namespace Fases
{

	class Fase : public Ente
	{
	protected:
		Gerenciadores::GerenciadorColisoes gerenciadorColisoes;
		Listas::ListaEntidades* listaEntidades;
		Entidades::Personagens::Atirador* ati;
		Entidades::Personagens::Jogador* j1;
		Entidades::Personagens::Jogador* j2;
		Entidades::Personagens::Bulbassauro* bulb;
		Entidades::Projetil* pr;
		map<string, float> pontuacoes;
		Entidades::Obstaculos::Fogo* fogo;
		virtual void inicializaElementos() = 0;
		virtual void inicializaFogo() = 0;
		virtual void inicializaAtirador() = 0;
		Memoria memoria;
		sf::Text texto;
		sf::Event evento;
		sf::Font pontuacaoFonte;
		sf::Texture pontuacaoTela;
	public:
		Fase();
		~Fase();
		Listas::ListaEntidades* getListaEntidades();
		void executar() = 0;
		void setPontos();
	};
}
