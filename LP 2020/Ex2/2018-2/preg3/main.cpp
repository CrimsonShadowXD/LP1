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

#include "PlListaDoble.h"
#include "Infraccion.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archIn("Infracciones.csv", ios::in);
    if (!archIn) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    } 
    ofstream archOut("infracciones.txt", ios::out); 
    if (!archOut) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    PlListaDoble<Infraccion> p;
    p.crear(archIn);
    p.imprimirOrden(archOut,0);
    double c=p.buscarMonto(101);
    cout<<c<<endl;
    return 0;
}

