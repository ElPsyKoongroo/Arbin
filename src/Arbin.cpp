#include "Arbin.h"

template<typename T>
Arbin<T>::Arbin()
{
	elimina(raiz);
	raiz = new PtrNodoB();
}

template <typename T>
Arbin<T>::Arbin(const T& objeto, const Arbin& ai, const Arbin& ad)
{
	elimina(raiz);
	raiz = new NodoB<T>(objeto, copia(ai.raiz), copia(ad.raiz));
}

template <typename T>
Arbin<T>::Arbin(const Arbin& a)
{
	elimina(raiz);
	raiz = copia(a.raiz);
}

template<typename T>
Arbin<T>& Arbin<T>::operator=(const Arbin& a)
{
	if(this == &a) return *this;
	elimina(raiz);
	raiz = copia(a.raiz);
	return *this;
}

template<typename T>
void Arbin<T>::elimina(PtrNodoB p)
{
	if (!p) return;

	elimina(p->getDer());
	elimina(p->getIzq());

	delete p;
}

template<typename T>
bool Arbin<T>::esVacio() const
{
	return raiz == NULL;
}

template <typename T>
int Arbin<T>::altura() const
{
	return getRaiz().altura();
}

template <typename T>
NodoB<T>* Arbin<T>::copia(PtrNodoB p)
{
	if (!p) return NULL;

	return new NodoB<T>(p->getObj(), copia(p->getIzq()), copia(p->getDer()));
}


template<typename T>
Arbin<T>::~Arbin()
{
	elimina(raiz);
}


/*
	|------------|
	|  Iterator  |
	|------------|
*/ 

template<typename T>
Arbin<T>::Iterador Arbin<T>::getRaiz() const
{
	return Iterador(raiz);
}

template <typename T>
Arbin<T>::Iterador Arbin<T>::subIzq(const Iterador& r) const
{
	if (!r.pnodo) throw PosicionErroneaExcepcion();
	
	return Iterador(r.pnodo->getIzq());
}

template<typename T>
Arbin<T>::Iterador Arbin<T>::subDer(const Iterador& r) const
{
	if (!r.pnodo) throw PosicionErroneaExcepcion();

	return Iterador(r.pnodo->getDer());
}

template <typename T>
int Arbin<T>::Iterador::altura() const
{
	if (arbolVacio())
		return 0;

	return 1 + max(Iterador(pnodo->getIzq()).altura(), Iterador(pnodo->getDer()).altura());
}
