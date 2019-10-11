/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: La Rosa
 *
 * Created on 7 de octubre de 2019, 20:41
 */

#include "newfile.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *almacenes,*codigoProd,*nombreProd;
    int N;
    leerPalets(almacenes,N);
    imprimirPalets(almacenes,N);
    leerProductos(codigoProd,nombreProd,N);
    imprimirProductos(codigoProd,nombreProd,N);
    ordenarproductos(codigoProd,nombreProd,N);
    imprimirProductos(codigoProd,nombreProd,N);
    cuentaproductos(almacenes,codigoProd,nombreProd,N);
    return 0;
}
