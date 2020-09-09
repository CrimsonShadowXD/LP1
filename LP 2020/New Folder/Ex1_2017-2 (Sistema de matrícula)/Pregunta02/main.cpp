
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 *  Creado el 2 de Junio del 2020.
 */

#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *codCur, **requisitos, *codAlum;
    char **cursos,**alumnos;
    
    leerCursos(codCur,cursos,requisitos);
    imprimirCursos(codCur,cursos,requisitos);

    leerAlumnos(codAlum,alumnos);
    imprimirAlumnos(codAlum,alumnos);
    return 0;
}

