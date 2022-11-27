#include "Fase.h"

Fases::Fase::Fase():Ente()
{
}
Fases::Fase::~Fase()
{
}
void Fases::Fase::inicializaElementos()
{
}
Listas::ListaEntidades* Fases::Fase::getListaEntidades()
{
	return listaEntidades;
}
void Fases::Fase::executar()
{

}
void Fases::Fase::setPontos()
{
	memoria.lerArquivo();
	string nome;
	int flag=0;
	cout << "Insira o nome do jogador 1:";
	cin >> nome;
	pontuacoes.insert(pair<string, float>(nome, j1->getPontuacao()));
	cout << "Insira o nome do jogador 2:";
	cin >> nome;
	pontuacoes.insert(pair<string, float>(nome, j2->getPontuacao()));
	cout << "volte a tela do jogo :)";
	for (map<string, float>::iterator it = pontuacoes.begin();
		it != pontuacoes.end(); it++)
	{
		memoria.salvarPontos((*it).first, (*it).second);
	}
	//inserir função de salvamento de arquivo
	memoria.atualizaArq();
}