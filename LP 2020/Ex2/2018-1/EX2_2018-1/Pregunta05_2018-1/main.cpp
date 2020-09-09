/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   main.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 07:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "PlArbol.h"
#include "Autor.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class PlArbol<double> arbDouble;
    class PlArbol<Autor> arbAutor;
    double datoDouble;
    class Autor datoAutor;
    ifstream archDouble("numerosD.txt",ios::in);
    if (!archDouble){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    ifstream archAutores("Autores-LP1.csv",ios::in);
    if (!archAutores){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    ofstream rep("ReporteDouble.txt", ios::out);
    if (!rep){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    ofstream rep2("ReporteAutores.txt", ios::out);
    if (!rep2){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    arbDouble.crear(archDouble);
    arbDouble.imprimir(rep);
    
    arbAutor.crear(archAutores);
    arbAutor.imprimir(rep2);
    return 0;
}

