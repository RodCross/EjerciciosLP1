#ifndef VEHICULO_H
#define VEHICULO_H
#include <list>
#include <fstream>
using namespace std;

class Vehiculo {
private:
    char *placa;
    list<int> infracciones;
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetPlaca(const char* placa);
    void GetPlaca(char *) const;
    void asignarInfraccion(ifstream &);
    void imprimirInfracciones(ofstream &);
};

#endif /* VEHICULO_H */
