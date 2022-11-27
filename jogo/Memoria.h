#include <String>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
	
struct info
{
	int pont;
	string nome;
};
class Memoria
{
private:
	ofstream gravador;
	ifstream leitor;
	vector<info> informations;
public:
	Memoria();
	~Memoria();
	void salvarPontos(string nm, int pt);
	void atualizaArq();
	void ordenaVet();
	void lerArquivo();
};