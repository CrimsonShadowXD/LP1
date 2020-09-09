/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   main.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 02:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Libreria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Libreria libreria;
    libreria.crearArbol_E_ImprimeReporte(argv);
    return 0;
}

