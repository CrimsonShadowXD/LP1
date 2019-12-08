/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libreria.cpp
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:38 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "libro.h"
#include "Libreria.h"

#define N 256
#define MAXCHAR 150
using namespace std;

Libreria::Libreria() {
}

void Libreria::crearBibliotecaLibros(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    libro lib;
    if(!arch.is_open()){
        cerr << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    while(!arch.eof()){
        arch >> lib;
        libros.insertar(lib); //Insertamos el libro en el arbol ordenadamente
        arch >> ws;
    }
}

void Libreria::leerVentasDeLibros(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    libro lib;
    char codLib[N];
    if(!arch.is_open()){
        cerr << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    while(!arch.eof()){
        arch.ignore(N, ',');//Ignoramos la fecha
        arch.ignore(N, ','); //Ignoramos la hora
        arch.getline(codLib, N);
        libros.modificar(codLib);
        arch >> ws;
    }
}

void Libreria::imprimir(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    char codLib[N];
    char titulo[] = "LISTA DE LIBROS";
    if(!arch.is_open()){
        cerr << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    impLinea(arch, '=', MAXCHAR);
    //El titulo estara centrado en el reporte
    arch << setw(MAXCHAR/2 + strlen(titulo)/2) << titulo << endl;   
    impLinea(arch, '=', MAXCHAR);
    arch << setw(10) << "CODIGO" << left << setw(4) << ' ' << setw(60) << "TITULO"
    << setw(35) << "AUTOR" << right << setw(10) << "PRECIO" << setw(15) << "MONTO"
    << setw(16) << "N° VENDIDOS" << endl;
    impLinea(arch, '-', MAXCHAR);
    libros.imprimir(arch);//Imprimimos los libros de la libreria
    impLinea(arch, '=', MAXCHAR);
}

void Libreria::impLinea(ofstream& out, char c, int tam){
    int i;
    for(i=0; i<tam; i++)
        out << c;
    out <<endl;
}


