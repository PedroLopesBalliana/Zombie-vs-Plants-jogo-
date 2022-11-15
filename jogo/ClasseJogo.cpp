#include "ClasseJogo.h"

ClasseJogo::ClasseJogo()
{
    //menu = new Menu(&gerenciadorGrafico);
    jogador1 = new Jogador();
    fase1 = new Fase1(jogador1, &gerenciadorGrafico);
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
