#pragma once
template <class TE>class Elemento
{
private:
	Elemento<TE>* pProximo;
	TE item;
public:
	Elemento();
	~Elemento();
	void setpProximo(Elemento<TE>* pProx)
	{
		this->pProximo = pProx;
	}
	void setItem(TE* item)
	{
		this->item = item;
	}
	Elemento<TE>* getpProximo()//implementar const
	{
		return pProximo;
	}
	TE* getItem()//implementar const
	{
		return item;
	}

};


template <class TE>
inline Elemento<TE>::Elemento()
{
	pProximo = nullptr;
	item = nullptr;
}

template <class TE>
inline Elemento<TE>::~Elemento()
{

}

