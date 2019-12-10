/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de diciembre de 2017, 08:07 AM
 */
//20150008 Daniela Cisneros
#include <cstdlib>
#include "GestorAutores.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GestorAutores g;
    g.leerAuthors("Authors.csv");
    g.leerPapers("Papers.csv");
    g.imprimirReporte("Reporte.txt");
    g.eliminarLista();
    return 0;
}

