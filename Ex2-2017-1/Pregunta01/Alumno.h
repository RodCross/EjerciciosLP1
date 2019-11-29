#ifndef ALUMNO_H
#define ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
    private:
        int codigo;
        char *nombre;
    public:
        Alumno();
        virtual ~Alumno();
        void SetNombre(const char* nombre);
        void GetNombre(char *) const;
        void SetCodigo(int codigo);
        int GetCodigo() const;
        virtual void leer(ifstream &) = 0;
        virtual void imprimir(ofstream &) = 0;
        virtual char GetTipo() = 0;
};

#endif /* ALUMNO_H */
