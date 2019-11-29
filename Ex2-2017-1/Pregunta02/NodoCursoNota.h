#ifndef NODOCURSONOTA_H
#define NODOCURSONOTA_H
#include <cstdlib>
#include "CursoNota.h"
#include "ListaCursoNota.h"

class NodoCursoNota {
    private:
        CursoNota cn;
        NodoCursoNota *sig;
    public:
        NodoCursoNota() {sig = NULL;}
        friend class ListaCursoNota;
};

#endif /* NODOCURSONOTA_H */
