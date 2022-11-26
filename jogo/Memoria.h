#include <String>
#include <vector>
using namespace std;
	
struct info
{
	int pont;
	string nome;
};
class Memoria
{
private:
	FILE* arquivo;
	vector<info> informations;
public:
	Memoria();
	~Memoria();
	void lerArq();
	void salvarPontos(string nm, float pt);
	void atualizaArq();
	void ordenaVet();
};