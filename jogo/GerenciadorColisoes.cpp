#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes()
{

}
GerenciadorColisoes::~GerenciadorColisoes()
{

}
std::vector<Entidades::Personagens::Inimigo> GerenciadorColisoes::getLIs()
{
	return LIs;
}
std::list<Obstaculo> GerenciadorColisoes::getLOs()
{
	return LOs;
}
