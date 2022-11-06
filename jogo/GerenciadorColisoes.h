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
	Jogador* jogador;
	Obstaculo* obstaculo;
	sf::FloatRect sect;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	std::vector<Inimigo*> getLIs();
	std::list<Obstaculo*> getLOs();
	void setJogador(Jogador *jog);
	void setObstaculo(Obstaculo* ob);
	void checaColisao(Obstaculo* ob);
	void checaColisaoInimigo(Inimigo* ob);
	void percorrer();
	void percorrerObstaculo();
	void percorrerInimigo();
	void pushObstaculo(Obstaculo* ob);
	void pushInimigo(Inimigo* in);
};