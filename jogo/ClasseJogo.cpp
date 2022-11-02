#include "ClasseJogo.h"

ClasseJogo::ClasseJogo()
{
    jogador1 = new Jogador();
    fase1 = new Fase1(jogador1);
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
