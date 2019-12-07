#ifndef INFRACCION_H
#define INFRACCION_H
#include <fstream>
using namespace std;

class Infraccion {
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char* gravedad);
    void GetGravedad(char *) const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator =(const Infraccion &);
    bool operator ==(int);
    bool operator >(const Infraccion &);
    double obtenerCosto();
};

void operator >>(ifstream &, Infraccion &);
ofstream &operator <<(ofstream &, const Infraccion &);

#endif /* INFRACCION_H */
