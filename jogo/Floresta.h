#pragma once
#include "Fase.h"
#include "Masmorra.h"
namespace Fases
{
	class Floresta : public Fase
	{
	private:
		Entidades::Obstaculos::Grama* gr;
		Entidades::Obstaculos::Espinho* esp;
		Masmorra* fase2;
	public:
		Floresta(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2, Gerenciadores::GerenciadorGrafico* GE);
		~Floresta();
		void inicializaGrama();
		void inicializaEspinhos();
		void inicializaBulbassauro();
		void inicializaAtirador();
		void inicializaFogo();
		void inicializaElementos();
		void executar();
	};
}
