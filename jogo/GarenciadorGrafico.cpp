#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{
}
void GerenciadorGrafico::setListaEntidades(ListaEntidades Le)
{
	LE = Le;
	for (int i = 0; i < LE.LEs.getLen(); i++)
	{
		Entidade* temp = LE.LEs.getItem(i);
		temp->setWindow(&window);
	}
}
GerenciadorGrafico::~GerenciadorGrafico()
{

}
void GerenciadorGrafico::desenharEntidades()
{
	for (int i = 0; i < LE.LEs.getLen(); i++)
	{
		Entidade* temp = LE.LEs.getItem(i);
		temp->draw();
	}
}
