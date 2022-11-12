#pragma once

template <class TL>class Lista
{
public:
	template <class TE>class Elemento
	{
	private:
		Elemento<TE>* pProximo;
		TE* item;
	public:
		Elemento()
		{
			pProximo = nullptr;
			item = nullptr;
		}
		~Elemento()
		{

		}
		void setpProximo(Elemento<TE>* pProx)
		{
			this->pProximo = pProx;
		}
		void setItem(TE* item)
		{
			this->item = item;
		}
		Elemento<TE>* getpProximo()
		{
			return pProximo;
		}
		TE* getItem()
		{
			return item;
		}
	};
	Lista();
	~Lista();
	int getLen()
	{
		return len;
	}
	TL* getItem(int posi)
	{
		Elemento <TL>* temp = pPrimeiro;
		if (posi == 0)
		{
			return temp->getItem();
		}
		else
		{
			for (int i = 0; i < posi; i++)
			{
				temp = temp->getpProximo();
			}
		}
		return temp->getItem();//Implementar solução para ponteiro vazio.
	}

	void push(TL* item)
	{
		if (pPrimeiro == nullptr)
		{
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setItem(item);
			pUltimo = pPrimeiro;
		}
		else
		{
			Elemento <TL>* temp = new Elemento <TL>;
			temp->setItem(item);
			pUltimo->setpProximo(temp);
			pUltimo = temp;
		}
		len++;
	}

	void pop(TL* item)
	{
		Elemento <TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = nullptr;
		while (temp->getItem() != item)
		{
			tempAnt = temp;
			temp = temp->getpProximo();
		}
		if (temp == pPrimeiro)
		{
			pPrimeiro = temp->getpProximo();
		}
		else if (temp == pUltimo)
		{
			tempAnt->setpProximo(nullptr);
			pUltimo = tempAnt;
		}
		else
		{
			tempAnt->setpProximo(temp->getpProximo());
		}
		delete temp;
		len--;
	}
private:
	Elemento <TL>* pPrimeiro;
	Elemento <TL>* pUltimo;
	int len;
};

template<class TL>
inline Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{

}
