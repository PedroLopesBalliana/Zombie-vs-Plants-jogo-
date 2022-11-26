#include "GerenciadorColisoes.h"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes() : jogador(NULL)
{

}
Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{

}
std::vector<Inimigo*> Gerenciadores::GerenciadorColisoes::getLIs()
{
	return LIs;
}
std::list<Obstaculo*> Gerenciadores::GerenciadorColisoes::getLOs()
{
	return LOs;
}
std::list<Projetil*> Gerenciadores::GerenciadorColisoes::getLPs()
{
	return LPs;
}
void Gerenciadores::GerenciadorColisoes::setJogador(Jogador *jog)
{
	jogador = jog;
}
void Gerenciadores::GerenciadorColisoes::checaColisao(Obstaculo* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds(), sect))
	{
		if (sect.height < sect.width)
		{
			if (sect.top - ob->getSprite().getPosition().y > ob->getSpriteBounds().height / 2)
			{
				jogador->corrigir(-sect.height, 0.f);
			}
			else
			{
				jogador->corrigir(sect.height, 0.f);
				ob->danificar(jogador);
			}
		}
		else
		{
			if (sect.left - ob->getSprite().getPosition().x > ob->getSpriteBounds().width / 2)
			{
				jogador->corrigir(0.f, sect.width);
			}
			else
			{
				jogador->corrigir(0.f, -sect.width);
			}
		}
	
		if (ob->getDanoso() == true)
		{
			ob->danificar(jogador);
		}
	}
}
void Gerenciadores::GerenciadorColisoes::checaColisaoInimigo(Inimigo* in)
{
	if (in->getSpriteBounds().intersects(jogador->getSpriteBounds()))
	{
		if (jogador->getAtacando())
		{
			in->operator--();
			jogador->incrementaPontos();
		}
		else
		{
			in->danificar(jogador);
		}
	}
}
void Gerenciadores::GerenciadorColisoes::checaColisaoProjetil(Projetil* ob)
{
	if (ob->getSpriteBounds().intersects(jogador->getSpriteBounds()))
	{
		ob->danificar(jogador);
	}
}
void Gerenciadores::GerenciadorColisoes::percorrer()
{
	percorrerObstaculo();
	percorrerInimigo();
	percorrerProjetil();
}
void Gerenciadores::GerenciadorColisoes::percorrerObstaculo()
{
	std::list<Obstaculo*>::iterator it;
	it = LOs.begin();
	while (it != LOs.end())
	{
		checaColisao(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::percorrerProjetil()
{
	std::list<Projetil*>::iterator it;
	it = LPs.begin();
	while (it != LPs.end())
	{
		checaColisaoProjetil(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::percorrerInimigo()
{
	std::vector<Inimigo*>::iterator it;
	it = LIs.begin();
	while (it != LIs.end())
	{
		checaColisaoInimigo(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::pushObstaculo(Obstaculo* ob)
{
	LOs.push_back(ob);
}
void Gerenciadores::GerenciadorColisoes::pushInimigo(Inimigo* in)
{
	LIs.push_back(in);
}
void Gerenciadores::GerenciadorColisoes::pushProjetil(Projetil* pr)
{
	LPs.push_back(pr);
}
