#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include <list>
#include <vector>
#include "Jogador.h"
#include "Inimigo.h"

class GerenciadorColisoes
{
private:
	std::vector<Inimigo*> LIs;
	std::list<Obstaculo*> LOs;
	std::list<Projetil*> LPs;
	Jogador* jogador;
	sf::FloatRect sect;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	std::vector<Inimigo*> getLIs();
	std::list<Obstaculo*> getLOs();
	std::list<Projetil*> getLPs();
	void setJogador(Jogador *jog);
	void checaColisao(Obstaculo* ob);
	void checaColisaoInimigo(Inimigo* ob);
	void checaColisaoProjetil(Projetil* ob);
	void percorrer();
	void percorrerObstaculo();
	void percorrerInimigo();
	void percorrerProjetil();
	void pushObstaculo(Obstaculo* ob);
	void pushInimigo(Inimigo* in);
	void pushProjetil(Projetil* pr);
};