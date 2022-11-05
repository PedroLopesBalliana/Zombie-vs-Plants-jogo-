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
		jogador->corrigir(sect.height);
	}
}
void GerenciadorColisoes::percorrer()
{
	std::list<Obstaculo*>::iterator it;
	it = LOs.begin();
	while (it != LOs.end())
	{
		checaColisao(*it);
		it++;
	}
}
void GerenciadorColisoes::push(Obstaculo* ob)
{
	LOs.push_back(ob);
}
