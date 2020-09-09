/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 20, 2020, 10:51 AM
 */

#include "PlArbol.h"
#include "Cliente.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archIn("Banco-Clientes.csv", ios::in);
    ofstream archOut("prueba.txt", ios::out);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    int hh,mm,ss;
    char c;
    PlArbol<Cliente> p;
    archIn>>hh>>c;
    archIn>>mm>>c;
    archIn>>ss;
    archIn>>ws;
    p.crear(archIn);
    p.imprimir(archOut);
    return 0;
}
