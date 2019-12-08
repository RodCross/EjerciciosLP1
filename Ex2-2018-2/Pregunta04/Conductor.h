#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "ListaVehiculos.h"
#include <fstream>
using namespace std;

class Conductor {
private:
    int dni;
    char *nombre;
    int telefono;
    ListaVehiculos vehiculos;
public:
    Conductor();
    virtual ~Conductor();
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    void leer(ifstream &);
    void imprimir(ofstream &);
    void leerInfraccion(ifstream &);
    void acumularMultas(int *);
};

#endif /* CONDUCTOR_H */
