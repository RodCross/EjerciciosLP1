#include "Funcioneslaboratorio05.h"

int main() {
    char ***almacenes, **codigoProd, **nombreProd;
    leerPalets(almacenes);
    imprimirPalets(almacenes);
    leerProductos(codigoProd, nombreProd);
    imprimirProductos(codigoProd, nombreProd);
    ordenaproductos(codigoProd, nombreProd);
    imprimirProductos(codigoProd, nombreProd);
    cuentaProductos(almacenes, codigoProd, nombreProd);
    return 0;
}

