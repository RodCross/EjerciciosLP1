#ifndef CURSONOTA_H
#define CURSONOTA_H
#include <fstream>
using namespace std;

class CursoNota {
    private:
        char *codigo;
        int nota;
    public:
        CursoNota();
        virtual ~CursoNota();
        void SetNota(int nota);
        int GetNota() const;
        void SetCodigo(const char* codigo);
        void GetCodigo(char*) const;
        void leer(ifstream &);
        void imprimir(ofstream &);
};

#endif /* CURSONOTA_H */
