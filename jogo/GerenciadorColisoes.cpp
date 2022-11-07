#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes() : jogador(NULL)
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
std::list<Projetil*> GerenciadorColisoes::getLPs()
{
	return LPs;
}
void GerenciadorColisoes::setJogador(Jogador *jog)
{
	jogador = jog;
}
void GerenciadorColisoes::checaColisao(Obstaculo* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds(), sect))
	{

		jogador->corrigir(sect.height, 0.f);
		if (ob->getDanoso() == true)
		{
			jogador->operator--();
		}
	}
}
void GerenciadorColisoes::checaColisaoInimigo(Inimigo* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds()))
	{
		jogador->operator--();
		jogador->corrigir(100.f, 0.f);
	}
}
void GerenciadorColisoes::checaColisaoProjetil(Projetil* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds()))
	{
		jogador->operator--();
		if(jogador->getSentido())
			jogador->corrigir(0.f, 100.f);
		else
			jogador->corrigir(0.f, -100.f);
	}
}
void GerenciadorColisoes::percorrer()
{
	percorrerObstaculo();
	percorrerInimigo();
	percorrerProjetil();
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
void GerenciadorColisoes::percorrerProjetil()
{
	std::list<Projetil*>::iterator it;
	it = LPs.begin();
	while (it != LPs.end())
	{
		checaColisaoProjetil(*it);
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
void GerenciadorColisoes::pushProjetil(Projetil* pr)
{
	LPs.push_back(pr);
}
