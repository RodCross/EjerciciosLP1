#ifndef CADENA_H
#define CADENA_H

class Cadena {
    private:
        char *cadena;
        int longitud;
        int capacidad;
    public:
        // Inicializacion
        Cadena();
        Cadena(const char *);
        Cadena(int);
        Cadena(const Cadena &);
        
        // Asignacion
        void assign(const char *);
        void assign(const Cadena &);
        void operator =(const char *);
        void operator =(const Cadena &);
        
        // Agregacion
        void append(const char *);
        void operator +=(const Cadena &);
        
        // Comparacion
        int compare(const char *);
        int compare(const Cadena &);
        bool operator ==(const Cadena &);
        bool operator >(const Cadena &);
        bool operator <(const Cadena &);
        
        // Otros metodos
        void getCadena(char *) const;
        int length() const;
        void swap(Cadena &);
        ~Cadena();
};

#endif /* CADENA_H */

