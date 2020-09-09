/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   Libreria.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 07:31 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Libreria.h"

void Libreria::crearArbol_E_ImprimeReporte(char ** argv) {
    ifstream archLibros(argv[1],ios::in);
    if (!archLibros){
        cout<<"Error al abrir "<<argv[1]<<endl;
        exit(1);
    }
    ifstream archAutores(argv[2],ios::in);
    if (!archAutores){
        cout<<"Error al abrir "<<argv[2]<<endl;
        exit(1);
    }
    ifstream archVentas(argv[3],ios::in);
    if (!archVentas){
        cout<<"Error al abrir "<< argv[3]<<endl;
        exit(1);
    }
    ofstream rep(argv[4],ios::out);
    if (!rep){
        cout<<"Error al abrir "<< argv[4]<<endl;
        exit(1);
    }
    arbol.crear(archLibros);
    arbol.completarAutores(archAutores);
    arbol.registrarVentas(archVentas);
    arbol.reporte(rep);
    arbol.eliminaArbol();
}


