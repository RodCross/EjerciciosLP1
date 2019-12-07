#ifndef RESERVA_H
#define RESERVA_H
#include <fstream>
using namespace std;

class Reserva {
    private:
        char *solicitud;
        char *atencion;
        char *devolucion;
        int estado;
        void convertirFecha(char *);
    public:
        Reserva();
        virtual ~Reserva();
        void SetDevolucion(const char *);
        void GetDevolucion(char *) const;
        void SetAtencion(const char *);
        void GetAtencion(char *) const;
        void SetSolicitud(const char *);
        void GetSolicitud(char *) const;
        void SetEstado(int);
        int GetEstado() const;
        void leer(ifstream &);
        void imprimir(ofstream &);
        bool operator <(const Reserva &);
};

#endif /* RESERVA_H */
