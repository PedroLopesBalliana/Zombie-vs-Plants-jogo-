#include "GerenciadorColisoes.h"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes() : jogador(NULL)
{

}
Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{
	std::vector<Entidades::Personagens::Inimigo*>::iterator it;
	std::list<Entidades::Projetil*>::iterator it2;
	std::list<Entidades::Obstaculos::Obstaculo*>::iterator it3;

	Entidades::Personagens::Inimigo* pAux;
	LIs.pop_back();
	it = LIs.begin();
	while (it != LIs.end())
	{
		pAux = *it;
		if (pAux != NULL)
		{
			delete pAux;
		}
		pAux = NULL;
		it++;
	}
	LIs.clear();

	Entidades::Obstaculos::Obstaculo*  pAux2;
	LOs.pop_back();
	it3 = LOs.begin();
	while (it3 != LOs.end())
	{
		pAux2 = *it3;
		if (pAux2 != NULL)
		{
			delete pAux2;
		}
		pAux2 = NULL;
		it3++;
	}
	LOs.clear();

	Entidades::Projetil* pAux3;
	LPs.pop_back();
	it2 = LPs.begin();
	while (it2 != LPs.end())
	{
		pAux3 = *it2;
		if (pAux3 != NULL)
		{
			delete pAux3;
		}
		pAux3 = NULL;
		it2++;
	}
	LPs.clear();


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
