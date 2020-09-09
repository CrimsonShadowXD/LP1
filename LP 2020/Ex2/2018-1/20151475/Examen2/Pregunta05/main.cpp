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
#include "ArbolBinario.h"
#include "Autor.h"
#define N 256
using namespace std;

/*
 * 
 */

void prueba_double();
void prueba_autor();

int main(int argc, char** argv) {
    prueba_double();
    prueba_autor();
    return 0;
}

void prueba_double(){
    ArbolBinario < double > arbol;
    ifstream archIn("numeros.txt", ios::in);
    ofstream archOut("reporte_numeros.txt", ios::out);
    if (!archIn){
        cerr << "Error al abrir el archivo numeros.txt" << endl;;
        exit(1);
    }
    if(!archOut){
        cerr << "Error al abrir el archivo de reporte de numeros" << endl;
        exit(1);
    }
    arbol.crear(archIn);
    archOut << "NUMERO" << setprecision(2) << fixed << endl;
    arbol.imprimir(archOut);
}

void prueba_autor(){
    ArbolBinario < Autor > arbol;
    ifstream archIn("Autores-LP1.csv", ios::in);
    ofstream archOut("reporte_autores.txt", ios::out);
    if (!archIn){
        cerr << "Error al abrir el archivo Autores-LP1.csv" << endl;;
        exit(1);
    }
    if(!archOut){
        cerr << "Error al abrir el archivo de reporte de autores" << endl;
        exit(1);
    }
    arbol.crear(archIn);
    archOut << left << setw(12) << "DNI" << "NOMBRE" << endl;
    arbol.imprimir(archOut);
}