#include "NodoB.h"

template<typename T>
NodoB<T>::NodoB(const T& objeto)
{
	obj = objeto;

	izq = nullptr;
	der = nullptr;
}

template<typename T>
NodoB<T>::NodoB(const T& objeto, PtrNodoB nizq, PtrNodoB nder)
{
	obj = objeto;

	izq = nizq;
	der = nder;
}

template<typename T>
NodoB<T>::NodoB(const NodoB& n)
{
	*this = n;
}

template<typename T>
const T& NodoB<T>::getObj() const
{
	return obj;
}

template<typename T>
NodoB<T>::PtrNodoB NodoB<T>::getIzq() const
{
	return izq;
}

template<typename T>
NodoB<T>::PtrNodoB NodoB<T>::getDer() const
{
	return der;
}

template<typename T>
void NodoB<T>::setObj(const T& objeto)
{
	obj = objeto;
}

template<typename T>
void NodoB<T>::setIzq(PtrNodoB p)
{
	izq = p;
}

template<typename T>
void NodoB<T>::setDer(PtrNodoB p)
{
	der = p;
}
