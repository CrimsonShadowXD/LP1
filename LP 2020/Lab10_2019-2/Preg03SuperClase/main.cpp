
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama
 *
 * Created on 6 de julio de 2020, 20:16
 */

#include "InstitucionEducativa.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    InstitucionEducativa pamer;
    pamer.leerAlumnos();
    pamer.leerCursos();
   pamer.imprimirReporte();

    return 0;
}

