/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 09:05 AM
 */
//20150008 Daniela Cisneros
#include <cstdlib>
#include "GestorPublicaciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GestorPublicaciones g;
    g.leerPapers("Papers02.csv");
    g.imprimirReporte("Reporte.txt");
    
    return 0;
}

