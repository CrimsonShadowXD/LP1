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
#include "ArbolLibros.h"
#include "Libro.h"  
#define N 256
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ArbolLibros libros;
    Libro libro;
    int i;
    char cod[N], tit[N];
    ifstream archIn("Libreria-LP1.csv", ios::in);
    ofstream archOut("con", ios::out);
    if(!archIn){
        cerr << "Error al abrir el archivo de autores" << endl;
        exit(1);
    }
    
    if(!archOut){
        cerr << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
    for(i=0; i<6; i++){
        archIn >> libro; //Leemos el autor
        libro.GetCodigo(cod);
        libro.GetTitulo(tit);
        libros.insertar(cod, tit, libro.GetPrecio()); //Insertamos el libro en el arbol
        archIn >> ws;
    }
    libros.insertar_autor(545434, "Aldo", "UV2257");
    libros.insertar_autor(567534, "Mario", "UV2257");
    libros.insertar_autor(235345, "Elisa", "UV2257");
    libros.insertar_autor(9765634, "Aldo", "AI7921");
    libros.insertar_autor(1111111, "Helena", "HV6319");
    libros.insertar_autor(8454453, "Susana", "AI7921");
    libros.insertar_autor(8454453, "Susana", "ZF7975");
    libros.insertar_autor(8454453, "Susana", "KZ6738");
    libros.incrementar_ventas("UV2257");
    libros.incrementar_ventas("AI7921");
    libros.incrementar_ventas("AI7921");
    libros.incrementar_ventas("HV6319");
    libros.incrementar_ventas("HV6319");
    libros.incrementar_ventas("HV6319");
    libros.imprimir(archOut);
    libros.eliminar();
    return 0;
}

