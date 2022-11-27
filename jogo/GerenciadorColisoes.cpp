#include "GerenciadorColisoes.h"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes() : jogador(NULL)
{

}
Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{

}
std::vector<Entidades::Personagens::Inimigo*> Gerenciadores::GerenciadorColisoes::getLIs()
{
	return LIs;
}
std::list<Entidades::Obstaculos::Obstaculo*> Gerenciadores::GerenciadorColisoes::getLOs()
{
	return LOs;
}
std::list<Entidades::Projetil*> Gerenciadores::GerenciadorColisoes::getLPs()
{
	return LPs;
}
void Gerenciadores::GerenciadorColisoes::setJogador(Entidades::Personagens::Jogador *jog)
{
	jogador = jog;
}
void Gerenciadores::GerenciadorColisoes::checaColisao(Entidades::Obstaculos::Obstaculo* ob)
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
void Gerenciadores::GerenciadorColisoes::checaColisaoInimigo(Entidades::Personagens::Inimigo* in)
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
void Gerenciadores::GerenciadorColisoes::checaColisaoProjetil(Entidades::Projetil* ob)
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
	std::list<Entidades::Obstaculos::Obstaculo*>::iterator it;
	it = LOs.begin();
	while (it != LOs.end())
	{
		checaColisao(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::percorrerProjetil()
{
	std::list<Entidades::Projetil*>::iterator it;
	it = LPs.begin();
	while (it != LPs.end())
	{
		checaColisaoProjetil(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::percorrerInimigo()
{
	std::vector<Entidades::Personagens::Inimigo*>::iterator it;
	it = LIs.begin();
	while (it != LIs.end())
	{
		checaColisaoInimigo(*it);
		it++;
	}
}
void Gerenciadores::GerenciadorColisoes::pushObstaculo(Entidades::Obstaculos::Obstaculo* ob)
{
	LOs.push_back(ob);
}
void Gerenciadores::GerenciadorColisoes::pushInimigo(Entidades::Personagens::Inimigo* in)
{
	LIs.push_back(in);
}
void Gerenciadores::GerenciadorColisoes::pushProjetil(Entidades::Projetil* pr)
{
	LPs.push_back(pr);
}
