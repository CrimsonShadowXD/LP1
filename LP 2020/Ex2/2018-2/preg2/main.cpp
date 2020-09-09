/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 20, 2020, 5:51 AM
 */

#include "ListaConductores.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archIn("Conductores.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    } 
    ofstream archOut("conductores.txt", ios::out); 
    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    ListaConductores p;
    p.cargar(archIn);
    p.imprimirOrden(archOut,0);
    return 0;
}

