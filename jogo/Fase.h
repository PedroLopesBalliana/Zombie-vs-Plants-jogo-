#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;

class Fase
{
private:
	ListaEntidades *listaEntidades;
	Inimigo* i1;
	Jogador* j1;
	Obstaculo* ob1;
	list<Inimigo> listaInimigos;
	void inicializaElementos();
	sf::RenderWindow* window;
public:
	Fase(Jogador* j1, sf::RenderWindow* window);
	~Fase();
	ListaEntidades* getListaEntidades();
};
