/* 
 * Archivo:  main.cpp
 * Autor:    Rodrigo Alonso Cruz Lean
 * Codigo:   20170516
 *
 * Creado el 11 de octubre de 2019, 08:17 AM
 */

#include "Funcioneslaboratorio06.h"

int main() {
    void *palets, *producto;
    leerPalets(palets);
    imprimirPalets(palets);
    leerProductos(producto);
    imprimirProductos(producto);
    ordenaproductos(producto);
    imprimirProductos(producto);
    cargastock(palets, producto);
    return 0;
}

