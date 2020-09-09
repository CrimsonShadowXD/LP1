

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 5 de julio de 2020, 08:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "Lpersona.h"

using namespace std;

/*
 resolver el lab10 2019-1 con listas
 aumentar los sueldos solo impresión 
 alumnos nada
 docentes y administrativos si se aumenta
 * 
 variante: docentes según grado 50% doctores y 45% mag 
 * 
 */
int main(int argc, char** argv) {
    Lpersona lp;
    char nombre[50];
    
    lp.lee("persona.csv");
    lp.busca(12193112, nombre);
    cout << nombre;
    lp.imprime("reporte.txt");

    return 0;
}

