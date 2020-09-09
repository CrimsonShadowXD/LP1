/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:38 AM
 */

#include "PlCola.h"
#include "Alumno.h"
#include "Profesor.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Miembros.csv", ios::in);
    if (!in) {
        cout << "No se puede abrir Miembros" << endl;
        exit(1);
    }
    ofstream out("pruebadecolas.txt", ios::out);
    if (!out) {
        cout << "No se puede abrir" << endl;
        exit(1);
    }
    PlCola <Alumno> alumnos;
    PlCola <Profesor> profesores;
    char t;
    while (1) {
        in>>ws;
        in>>t;
        if (in.eof())break;
        in.get();
        if (t == 'A'){
            alumnos.crear(in);
        }
        else if (t == 'P'){
            profesores.crear(in);
        }
    }
    
    alumnos.imprimir(out);
    profesores.imprimir(out);
    return 0;
}

