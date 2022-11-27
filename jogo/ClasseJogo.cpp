#include "ClasseJogo.h"

ClasseJogo::ClasseJogo() : pGrafico(pGrafico->getGgr()), jogador1(nullptr), jogador2(nullptr)
{
    menu = new Menu(pGrafico);
}
void ClasseJogo::Executar()
{
}
void ClasseJogo::fase1Prin()
{
}
ClasseJogo::~ClasseJogo()
{
    delete menu;
    menu = nullptr;
}
