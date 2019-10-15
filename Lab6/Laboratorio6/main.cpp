/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 *
 * Created on 11 de octubre de 2019, 08:08 AM
 */

#include "Funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *palets,*producto;
    leerPalets(palets);
    ImprimirPalets(palets);
    leerProductos(producto);
    imprimirProductos(producto);
    ordenarproductos(producto);
    imprimirProductos(producto);
    cargastock(palets,producto);
    return 0;
}

