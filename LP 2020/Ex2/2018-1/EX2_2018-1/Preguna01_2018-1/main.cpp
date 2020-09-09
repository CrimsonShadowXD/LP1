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
#include "Autor.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class Autor au;
    class Autor autores[500];
    ifstream arch("Autores-LP1.csv",ios::in);
    if (!arch){
        cout<<"Error al abrir Autores-LP1.csv"<<endl;
        exit(1);
    }
    ofstream rep("ReporteAutoresPreg01.txt",ios::out);
    if (!rep){
        cout<<"Error al abrir ReporteAutoresPreg01.txt"<<endl;
        exit(1);
    }
    int nD=0;
    while (1){
        arch>>au;
        if (arch.eof()) break;
        autores[nD] = au;
        rep<<right<<setw(4)<<nD+1<<") ";
        rep<<autores[nD];
        rep<<endl;
        nD++;
        while (arch.get() != '\n' );
    }
    return 0;
}

