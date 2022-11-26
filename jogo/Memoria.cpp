
#include "Memoria.h"

Memoria::Memoria()
{

}
Memoria::~Memoria()
{

}

void Memoria::ordenaVet()
{
	//bubble sort
	for (int i = 0; i < (informations.size() - 1); i++) 
	{
		for (int j = 0; j < (informations.size() - i - 1); j++)
		{
			if (informations[j].pont < informations[j + 1].pont)
			{
				info temp= informations[j];
				informations[j] = informations[j + 1];
				informations[j + 1] = temp;
			}
		}
	}
	if (informations.size() > 11)
	{
		informations.resize(11);
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
	try
	{
		gravador.open("Rank.txt");
		if (gravador)
		{
			for (int i = 0; i != (informations.size() - 1); i++)
			{
				info aux2;
				aux2.nome = informations[i].nome;
				aux2.pont = informations[i].pont;
				gravador << aux2.nome << " " << aux2.pont << " " << endl;
			}
		}
		else
		{
			cout << "falhou abertura de arquivo" << endl;
		}
		gravador.close();
	}
	catch (std::exception const& e)
	{
		cout << "erro na gravada" << e.what() << endl;
	}
}
void Memoria::lerArquivo()
{
	try 
	{
		leitor.open("Rank.txt");
		if (leitor)
		{
			info aux;

			while (!leitor.eof())
			{
				leitor >> aux.nome >> aux.pont;
				informations.push_back(aux);
			}
		}
		else
		{
			cout << "falhou abertura de arquivo" << endl;
		}
		leitor.close();
	}
	catch (std::exception const& e)
	{
		cout << "erro na gravada" << e.what() << endl;
	}
}
