#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include <list>
#include <vector>

class GerenciadorColisoes
{
private:
	std::vector<Inimigo> LIs;
	std::list<Obstaculo> LOs;
public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	std::vector<Inimigo> getLIs();
	std::list<Obstaculo> getLOs();
};