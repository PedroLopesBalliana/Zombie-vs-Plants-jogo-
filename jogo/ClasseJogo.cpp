#include "ClasseJogo.h"

ClasseJogo::ClasseJogo()
{
    menu = new Menu(&gerenciadorGrafico);
    jogador1 = new Jogador();
    jogador2 = new Jogador();
    fase1 = new Floresta(jogador1, jogador2, &gerenciadorGrafico);
}
void ClasseJogo::Executar()
{
}
void ClasseJogo::fase1Prin()
{
}
ClasseJogo::~ClasseJogo()
{
}
