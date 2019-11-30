#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;

class Libro {
    private:
        char *codigo;
        char *titulo;
        char *autor;
        double precio;
        int nVend;
        double monto;
    public:
        Libro();
        virtual ~Libro();
        void SetMonto(double);
        double GetMonto() const;
        void SetNVend(int);
        int GetNVend() const;
        void SetPrecio(double);
        double GetPrecio() const;
        void SetAutor(char *);
        void GetAutor(char *) const;
        void SetTitulo(char *);
        void GetTitulo(char *) const;
        void SetCodigo(char *);
        void GetCodigo(char *) const;
        void operator ++(int);
};

void operator >>(ifstream &, Libro &);
ofstream &operator <<(ofstream &, const Libro &);

#endif /* LIBRO_H */
