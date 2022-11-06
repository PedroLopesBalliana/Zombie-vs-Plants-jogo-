#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes() : jogador(NULL), obstaculo(NULL)
{

}
GerenciadorColisoes::~GerenciadorColisoes()
{

}
std::vector<Inimigo*> GerenciadorColisoes::getLIs()
{
	return LIs;
}
std::list<Obstaculo*> GerenciadorColisoes::getLOs()
{
	return LOs;
}
void GerenciadorColisoes::setJogador(Jogador *jog)
{
	jogador = jog;
}
void GerenciadorColisoes::setObstaculo(Obstaculo* ob)
{
	obstaculo = ob;
}
void GerenciadorColisoes::checaColisao(Obstaculo* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds(), sect))
	{
		jogador->corrigir(sect.height, 0.f);
	}
}
void GerenciadorColisoes::checaColisaoInimigo(Inimigo* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds()))
	{
		jogador->operator++();
		jogador->corrigir(200.f, 200.f);
	}
}
void GerenciadorColisoes::percorrer()
{
	percorrerObstaculo();
	percorrerInimigo();
}
void GerenciadorColisoes::percorrerObstaculo()
{
	std::list<Obstaculo*>::iterator it;
	it = LOs.begin();
	while (it != LOs.end())
	{
		checaColisao(*it);
		it++;
	}
}
void GerenciadorColisoes::percorrerInimigo()
{
	std::vector<Inimigo*>::iterator it;
	it = LIs.begin();
	while (it != LIs.end())
	{
		checaColisaoInimigo(*it);
		it++;
	}
}
void GerenciadorColisoes::pushObstaculo(Obstaculo* ob)
{
	LOs.push_back(ob);
}
void GerenciadorColisoes::pushInimigo(Inimigo* in)
{
	LIs.push_back(in);
}
