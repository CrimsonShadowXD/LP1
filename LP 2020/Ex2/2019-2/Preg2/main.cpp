/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 20, 2020, 5:34 PM
 */

#include "PilaPallet.h"
#include "ListaPallet.h"
#include "ColaPallet.h"
#include "Pallet.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archIn("pallets.csv", ios::in);
    ofstream archOut("pruebald.txt", ios::out);
    ofstream out("pruebaelimnodo.txt", ios::out);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    ListaPallet p; 
    p.crear(archIn); 
    p.imprimir(archOut);    
    p.eliminar(5);
    p.imprimir(out);
    return 0;
}

