/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 29 de mayo de 2020, 08:03 AM
 */

#include "FuncionesActividad05.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumnos;
    leerAlumnos(alumnos);
    imprimirAlumnos(alumnos);
    leerCursos(alumnos);
    consolidado(alumnos);
    return 0;
}

