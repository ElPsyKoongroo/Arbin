#ifndef PosicionErroneaExcepcion_h
#define PosicionErroneaExcepcion_h

#include <exception>

class PosicionErroneaExcepcion : public std::exception
{
public:
	const char* what() const;
};

#endif // !PosicionErroneaExcepcion
