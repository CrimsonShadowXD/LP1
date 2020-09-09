/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libreria.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 10:12 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "Libreria.h"
#include "Libro.h"
#include "Autor.h"
#define N 256
#define COD 7
using namespace std;

Libreria::Libreria() {
}

void Libreria::leer_libros(const char* nomb) {
    ifstream arch(nomb, ios::in);
    Libro libro;
    char cod[N], tit[N];
    if(!arch){
        cerr << "Error al abrir el archivo " << nomb;
        exit(1);
    }
    while(!arch.eof()){
        arch >> libro;
        libro.GetCodigo(cod);
        libro.GetTitulo(tit);
        arbolLibros.insertar(cod, tit, libro.GetPrecio());
        arch >> ws;
    }
}

void Libreria::imprimir(const char* nomb) {
    ofstream arch(nomb, ios::out);
    Libro libro;
    char cod[N], tit[N];
    if(!arch){
        cerr << "Error al abrir el archivo " << nomb;
        exit(1);
    }
    arbolLibros.imprimir(arch);
    arbolLibros.eliminar();
}

void Libreria::completar_autores(const char* nomb) {
    ifstream arch(nomb, ios::in);
    Autor autor;
    char c;
    char nombAut[N], tit[N], codLib[COD];
    if(!arch){
        cerr << "Error al abrir el archivo " << nomb;
        exit(1);
    }
    while(!arch.eof()){
        arch >> autor;
        autor.GetNombre(nombAut);
        /*leemos los codigos de los libros escritos por el autor*/
        while((c=arch.get())==','){
            arch.getline(codLib, COD);
            /*Como se leen N--1 digitos del codigo, se activa el bit de error*/
            arch.clear();
            arbolLibros.insertar_autor(autor.GetDni(), nombAut, codLib);
        }
        arch.unget();
        arch>>ws;
    }
}

void Libreria::registar_ventas(const char* nomb) {
    ifstream arch(nomb, ios::in);
    Autor autor;
    char codLib[COD];
    if(!arch){
        cerr << "Error al abrir el archivo " << nomb;
        exit(1);
    }
    while(!arch.eof()){
        arch.ignore(N,','); //Ignoramos la fecha
        arch.ignore(N,','); //Ignoramos la hora;
        arch.getline(codLib, COD); //leemos el codigo;
        arbolLibros.incrementar_ventas(codLib);
        arch>>ws;
    }
}
