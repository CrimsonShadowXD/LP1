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
#include "Libro.h"
#define N 256
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Libro libro;
    char nomb[N];
    int dni;
    ifstream archIn("Libreria-LP1.csv", ios::in);
    ofstream archOut("prueba.txt", ios::out);
    if(!archIn){
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    
    if(!archOut){
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    archIn >> libro;
    libro.SetAutor(987654312, "Alan Romero");
    libro.SetAutor(534546764, "Steven Beltran");
    libro.SetAutor(234656735, "Julia Ramirez");
    libro++;
    libro++;
    archOut << left << setw(10) << "CODIGO" << setw(60) << "TITULO" << setw(4) 
            << ' ' << setw(46) << "AUTOR" << setw(10) << "PRECIO"
                << setw(11) << "VENDIDOS" << setw(8) << "MONTO"
                << endl ;
    archOut << libro;
    
    archOut << "Buscando a un autor en la posicion 1" << endl;
    libro.GetAutor(dni, nomb, 1);
    archOut << "Autor encontrado: " << endl;
    archOut << "DNI: " << dni << endl;
    archOut << "NOMBRE: " << nomb << endl;
    return 0;
}

