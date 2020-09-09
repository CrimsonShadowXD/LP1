/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:11 AM
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Libreria.h"
#define N 256
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Libreria libreria;
    if(argc==1){
        cerr << "No ingreso el nombre de los archivos" << endl;
        exit(1);
    }
    if(argc<5){
        cerr << "Se olvido de agregar el nombre de un archivo, seguro fue el nombre del reporte" << endl;
        exit(1);
    }
    libreria.leer_libros(argv[1]);
    libreria.completar_autores(argv[2]);
    libreria.registar_ventas(argv[3]);
    libreria.imprimir(argv[4]);
    return 0;
}

