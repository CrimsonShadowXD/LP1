
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 *  Creado el 2 de Junio del 2020.
 */

#include "Bib_Func_Preg1.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *codCur, **requisitos;
    char **cursos;
    
    leerCursos(codCur,cursos,requisitos);
    imprimirCursos(codCur,cursos,requisitos);

    return 0;
}

