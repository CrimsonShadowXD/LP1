/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 19, 2020, 1:03 PM
 */

#include "Arbol.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream i("Libreria-LP1.csv", ios::in);
    ofstream o("prueba0.txt", ios::out);
    if (!i) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!o) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    ifstream archIn("Autores-LP1.csv", ios::in);
    ofstream archOut("prueba.txt", ios::out);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    ifstream inx("Ventas-Libreria-LP1.csv", ios::in);
    ofstream outx("completo.txt", ios::out);
    if (!inx) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!outx) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    
    
    
    Arbol p;
    p.crear(i);
    p.imprimir(o);
    p.completarAutores(archIn);
    p.imprimir(archOut);
    p.registrarVentas(inx);
    p.imprimir(outx);
    
    return 0;
}

