/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:01 AM
 */

#include <cstdlib>
#include "Libreria.h"
using namespace std;

/*El formato del archivo sera como los que se daban en los primeros laboratorios:
linea separadora, Titulo, linea separadora, nombres de las columnas, linea separadora, 
 datos, linea separadora
 
 ACLARACION IMPORTANTE:
 ArbolBinario.cpp y ArbolBinario.h debian ser ArbolLibro.cpp y ArbolLibro.h
 Me confundi con el nombre de los archivos y de la clase. La clase era
 ArbolLibros, pero aqui se llama ArbolBinario*/
int main(int argc, char** argv) {
    Libreria libreria;
    libreria.crearBibliotecaLibros("Libreria-LP1.csv");//Creamos la biblioteca
    libreria.leerVentasDeLibros("Ventas-Libreria-LP1.csv");//Agregamos las ventas
    libreria.imprimir("reporte.txt");//Imprimimos el reporte
    return 0;
}

