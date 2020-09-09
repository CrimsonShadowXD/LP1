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
#include "ArbolLibro.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class ArbolLibro aLib;
    ifstream archLibros("Libreria-LP1.csv",ios::in);
    if (!archLibros){
        cout<<"Error al abrir Libreria-LP1.csv"<<endl;
        exit(1);
    }
    ifstream archAutores("Autores-LP1.csv",ios::in);
    if (!archAutores){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    ifstream archVentas("Ventas-Libreria-LP1.csv",ios::in);
    if (!archVentas){
        cout<<"Error al abrir Ventas-Libreria-LP1.csv"<<endl;
        exit(1);
    }
    ofstream rep("ReporteLibroConAutoresYVentas.txt",ios::out);
    if (!rep){
        cout<<"Error al abrir ReporteLibro.txt"<<endl;
        exit(1);
    }
    aLib.crear(archLibros);
    
    aLib.completarAutores(archAutores);
    aLib.registrarVentas(archVentas);
    aLib.reporte(rep);
    
    aLib.eliminaArbol();
    return 0;
}

