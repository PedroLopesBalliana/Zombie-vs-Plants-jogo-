#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include <list>
#include <vector>
#include "Jogador.h"
#include "Inimigo.h"
namespace Gerenciadores
{
	class GerenciadorColisoes
	{
	private:
		std::vector<Entidades::Personagens::Inimigo*> LIs;
		std::list<Entidades::Obstaculos::Obstaculo*> LOs;
		std::list<Entidades::Projetil*> LPs;
		Entidades::Personagens::Jogador* jogador;
		sf::FloatRect sect;

	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();
		std::vector<Entidades::Personagens::Inimigo*> getLIs();
		std::list<Entidades::Obstaculos::Obstaculo*> getLOs();
		std::list<Entidades::Projetil*> getLPs();
		void setJogador(Entidades::Personagens::Jogador* jog);
		void checaColisao(Entidades::Obstaculos::Obstaculo* ob);
		void checaColisaoInimigo(Entidades::Personagens::Inimigo* ob);
		void checaColisaoProjetil(Entidades::Projetil* ob);
		void percorrer();
		void percorrerObstaculo();
		void percorrerInimigo();
		void percorrerProjetil();
		void pushObstaculo(Entidades::Obstaculos::Obstaculo* ob);
		void pushInimigo(Entidades::Personagens::Inimigo* in);
		void pushProjetil(Entidades::Projetil* pr);
	};
}