#ifndef CADENA_H
#define CADENA_H

class Cadena {
    private:
        char *cad;
        int len;
        int cap;
    public:
        Cadena();
        Cadena(const char *);
        Cadena(int);
        Cadena(const Cadena &);
        ~Cadena();
        void assign(const char *);
        void assign(const Cadena &);
        void operator =(const char *);
        void operator =(const Cadena &);
        void append(const char *);
        void append(const Cadena &);
        void swap(Cadena &);
        Cadena operator +(const Cadena &);
        int compare(const char *);
        int compare(const Cadena &);
        int operator ==(const Cadena &);
        int operator >(const Cadena &);
        int operator <(const Cadena &);
        int length();
        void print();
};

#endif