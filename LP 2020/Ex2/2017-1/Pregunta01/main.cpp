/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 19, 2020, 3:53 PM
 */

#include "Alumno.h"
#include "Intercambio.h"
#include "Nacional.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Alumnos.csv", ios::in);
    ofstream out("prueba.txt", ios::out);
    if (!in) {
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }

    if (!out) {
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    Alumno *entrada;
    while (1) {
        char T;
        in>>T;
        if (in.eof())break;
        in.get();
        if (T == 'R')
            entrada = new Nacional;
        else if (T == 'I')
            entrada = new Intercambio;
        entrada->leer(in);
        entrada->imprimir(out);
    }
    return 0;
}

