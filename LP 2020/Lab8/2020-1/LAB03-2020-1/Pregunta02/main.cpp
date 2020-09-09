
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 3 de julio de 2020, 09:29
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Alumno.h"
#include "Persona.h"
#include "Profesor.h"
#include "Miembro.h"
#include "SobrecargasIO.h"
#include "Proceso.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Proceso pro;
    
   
       
       pro.leemiembro("Miembros.csv");
       pro.imprimemiembro("Alumnos.txt","Profesor.txt");

    return 0;
}

