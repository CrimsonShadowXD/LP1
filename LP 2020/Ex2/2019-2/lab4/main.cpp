/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 15, 2020, 9:01 AM
 */

#include "PlCola.h"
#include "Alumno.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    PlCola<Alumno> p;
    ifstream archIn("Alumnos.txt", ios::in);
    ofstream archOut("p.txt", ios::out);
    if(!archIn){
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    p.crear(archIn);
    p.imprimir(archOut);
    return 0;
}

