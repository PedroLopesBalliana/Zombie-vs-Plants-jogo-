
#include "Memoria.h"

Memoria::Memoria()
{
	lerArq();
}
Memoria::~Memoria()
{

}
void Memoria::lerArq()
{
	arquivo=fopen("save.txt", "r");
}
void Memoria::ordenaVet()
{
	//bubble sort
	for (int i = 0; i < (informations.size() - 1); i++) 
	{
		for (int j = 0; j < (informations.size() - i - 1); j++)
		{
			if (informations[j].pont > informations[j + 1].pont)
			{
				info temp= informations[j];
				informations[j] = informations[j + 1];
				informations[j + 1] = temp;
			}
		}
	}
	atualizaArq();
}
void Memoria::salvarPontos(string nm, float pt)
{
	info aux;
	aux.nome = nm;
	aux.pont = pt;
	informations.push_back(aux);
	ordenaVet();
}
void Memoria::atualizaArq()
{
	for (int i = 0; i != (informations.size()-1);i++)
	{
		info aux2;
		aux2.nome = informations[i].nome;
		aux2.pont = informations[i].pont;
		fprintf(arquivo, "%s", aux2.nome);
		fprintf(arquivo, "%f", aux2.pont);
	}
}
