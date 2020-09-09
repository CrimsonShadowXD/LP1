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
#include "Libro.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Libro lb;
    ifstream arch("Libreria-LP1.csv",ios::in);
    if (!arch){
        cout<<"Error al abrir Libreria-LP1.csv"<<endl;
        exit(1);
    }
    ofstream rep("ReporteLibro.txt",ios::out);
    if (!rep){
        cout<<"Error al abrir ReporteLibro.txt"<<endl;
        exit(1);
    }
    int i=0;
    rep<<right<<setw(40)<<"RELACION DE LIBROS DE LA LIBRERIA"<<endl;
    for (int i = 0; i < 100; i++) 
        rep<<'=';
    rep<<endl;

    while (1){
        arch>>lb;
        if (arch.eof()) break;
        rep<<right<<setw(3)<<i+1<<") ";
        lb.imprime(rep);
        rep<<endl;
        i++;
    }
    return 0;
}

