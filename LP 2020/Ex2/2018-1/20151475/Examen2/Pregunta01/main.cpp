/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 08:11 AM
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Autor.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Autor autor;
    ifstream archIn("Autores-LP1.csv", ios::in);
    ofstream archOut("con", ios::out);
    if(!archIn){
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    
    if(!archOut){
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    archIn >> autor;
    archOut << left << setw(12) << "DNI" << setw(30) << "NOMBRE" << right << endl;
    archOut << autor << endl;
    return 0;
}

