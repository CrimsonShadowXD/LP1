
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 09:33
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ACurso.h"
#include "Curso.h"
#include "Alumno.h"
#include "auxiliar.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int n=0; Alumno *alumnos= new Alumno[30];
    
    leerAlumnos(alumnos,n);
    leerCursos(alumnos);
    corregirCursos(alumnos);
    imprimirAlumnos(alumnos,n);     

    return 0;
}

