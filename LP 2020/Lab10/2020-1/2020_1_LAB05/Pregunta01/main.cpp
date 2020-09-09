/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 17 de julio de 2020, 08:04 AM
 */

#include "Alumno.h"
#include "Profesor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {    
    ifstream in("Miembros.csv", ios::in);
    if (!in) {
        cerr << "Error al abrir el archivo de Miembros" << endl;
        exit(1);
    }
    ofstream out("prueba.txt", ios::out);
    if (!out) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char t;
    Alumno alumnos;
    Profesor profesores;
    while (1) {
        in>>ws;
        in>>t;
        if (in.eof())break;
        in.get();
        if (t == 'A'){
            in>>alumnos;
            out<<alumnos;
        }
        else if (t == 'P'){
            in>>profesores;
            out<<profesores;
        }
    }

    return 0;
}

