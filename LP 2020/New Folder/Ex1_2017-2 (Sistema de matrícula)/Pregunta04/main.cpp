
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 *  Creado el 2 de Junio del 2020.
 */

#include <fstream>
#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"
#include "Bib_Func_Preg3.h"
#include "Bib_Func_Preg4.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *codCur, **requisitos, *codAlum, ***notas;
    char **cursos,**alumnos;
    
    leerCursos(codCur,cursos,requisitos);
    imprimirCursos(codCur,cursos,requisitos);

    leerAlumnos(codAlum,alumnos);
    imprimirAlumnos(codAlum,alumnos);
    
    leeNotas(codAlum,notas);
    imprimirNotas(codAlum,alumnos,notas);
    
    reporteDeMatricula(codCur,cursos,requisitos,codAlum,alumnos,notas);
    
    return 0;
}
