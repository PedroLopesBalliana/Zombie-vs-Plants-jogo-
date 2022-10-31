#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "Obstaculo.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Fase
{
private:
	ListaEntidades *listaEntidades;
	ListaInimigos* listainimigos;
	Inimigo* i1;
	Jogador* j1;
	Obstaculo* ob1;
	void inicializaElementos();
	sf::RenderWindow* window;
public:
	Fase(Jogador* j1, sf::RenderWindow* window);
	~Fase();
	ListaEntidades* getListaEntidades();
};
