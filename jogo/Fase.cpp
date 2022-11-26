#include "Fase.h"

Fase::Fase():Ente()
{
}
Fase::~Fase()
{
}
void Fase::inicializaElementos()
{
}
ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}
void Fase::executar()
{

}
void Fase::setPontos()
{
	string nome;
	int flag=0;
	printf("Insira o nome do jogador 1:");
	scanf_s("%s",&nome);
	pontuacoes.insert(pair<string, float>(nome, j1->getPontuacao()));
	printf("Insira o nome do jogador 2:");
	scanf_s("%s", &nome);
	pontuacoes.insert(pair<string, float>(nome, j2->getPontuacao()));
	printf("nome jogador 1:%s",nome);

}