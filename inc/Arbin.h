#ifndef Arbin_h
#define Arbin_h

#include "NodoB.h"
#include "PosicionErroneaExcepcion.h"

template<typename T>
class Arbin {
	typedef NodoB<T>* PtrNodoB;

	PtrNodoB raiz;
	PtrNodoB copia(PtrNodoB p);
	void elimina(PtrNodoB p);
public:
	
	class Iterador{ // clase iterador anidada dentro de la clase Arbin //
		friend class Arbin<T>;
		PtrNodoB pnodo;
		Iterador(PtrNodoB p) { pnodo = p; }
	public:
		const T& observar() const{
			if(pnodo == NULL) throw PosicionErroneaExcepcion();
			return pnodo->getObj();
		}
		bool arbolVacio() const {
			return pnodo == NULL;
		}
		bool operator!=(const Iterador& i) const {
			return (pnodo != i.pnodo);
		}
		bool operator==(const Iterador& i) const {
			return (pnodo == i.pnodo);
		}
		int altura() const;
	};

	
	Arbin();
	Arbin(const T& objeto, const Arbin& ai, const Arbin& ad);
	Arbin(const Arbin& a);
	Arbin& operator=(const Arbin& a);
	Iterador getRaiz() const;
	Iterador subIzq(const Iterador& r) const;
	Iterador subDer(const Iterador& r) const;
	bool esVacio() const;
	int altura() const;
	~Arbin();
};

#endif // !Arbin_h
