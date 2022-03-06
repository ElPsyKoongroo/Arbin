#ifndef NodoB_h
#define NodoB_h

template<typename T>
class NodoB
{
	typedef NodoB<T>* PtrNodoB;
public:
	NodoB(const T& objeto);
	NodoB(const T& objeto, PtrNodoB nizq, PtrNodoB nder);
	NodoB(const NodoB& n);
	const T& getObj() const;
	PtrNodoB getIzq() const;
	PtrNodoB getDer() const;
	void setObj(const T& objeto);
	void setIzq(PtrNodoB p);
	void setDer(PtrNodoB p);
private:
	T obj;
	PtrNodoB izq, der;
};
#endif // !NodoB_h
