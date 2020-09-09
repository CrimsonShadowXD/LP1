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

#include "Matricula.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Matricula p;
    p.leerAlumnos();
    p.imprimirAlumnos();
    p.cargarNotas();
    p.imprimirAlumnos();
    p.cargaCursos();
    p.imprimirCursos();
    return 0;
}

