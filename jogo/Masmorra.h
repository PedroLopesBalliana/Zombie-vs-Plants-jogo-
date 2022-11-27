#pragma once
#include "Fase.h"
#include "Pedra.h"
#include "Arvore.h"
namespace Fases
{

	class Masmorra : public Fase
	{
	private:
		Entidades::Obstaculos::Pedra* pe;
		Entidades::Personagens::Arvore* arvore;
		Entidades::Projetil* maca;
	public:
		Masmorra(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2, Gerenciadores::GerenciadorGrafico* GE);
		~Masmorra();
		void inicializaAtirador();
		void inicializaFogo();
		void inicializaArvore();
		void inicializaPedra();
		void inicializaElementos();
		void executar();
	};
}