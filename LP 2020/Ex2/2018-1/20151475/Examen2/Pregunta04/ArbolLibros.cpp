/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolLibros.cpp
 * Author: Hans Matos Rios (20151475)
 *
 * Created on 5 de julio de 2018, 09:21 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "ArbolLibros.h"
#include "Autor.h"

#define N 256
#define MAXCHAR 160
using namespace std;

ArbolLibros::ArbolLibros() {
    raiz = NULL;
}



void ArbolLibros::insertar(const char* cod, const char* tit, double precio) {
    /*Se tendra como parametro a un puntero a NODO, no a autor*/
    insertarAux(raiz, cod, tit, precio);
}

void ArbolLibros::insertarAux(Nodo*& nodo, const char* cod, const char* tit, 
                              double precio) {
    char codLibro[N];  
    if (nodo == NULL){ //Se llego a una hoja
        class Libro libro;
        libro.SetCodigo(cod);
        libro.SetPrecio(precio);
        libro.SetTitulo(tit);
        nodo = new Nodo;
        nodo->libro = libro;
    }else{ //Aun se sigue buscando
        nodo->libro.GetCodigo(codLibro);
        if (strcmp(cod, codLibro)<0)
            insertarAux(nodo->izq, cod, tit, precio);
        else
            insertarAux(nodo->der, cod, tit, precio);
    }
}


void ArbolLibros::imprimir(ofstream& arch) {
    arch << setw(75) << "RELACION DE LIBROS DE LA LIBRERIA" << endl;
    impLinea(arch, '=', MAXCHAR);
    arch << setw(3) << "No. " << left << setw(10) << "CODIGO" << setw(60) << "TITULO" << setw(4) 
         << ' ' << setw(46) << "AUTOR" << setw(10) << "PRECIO"
         << setw(11) << "VENDIDOS" << setw(8) << "MONTO"
         << endl ;
   
    inorden(raiz, arch);
}

void ArbolLibros::inorden(Nodo* nodo, ofstream& arch) {
    static int i= 1; //Contador para la columna No.
    if (nodo == NULL) return;
    inorden(nodo->izq, arch);
    arch << setw(2) << i << ") ";
    i++;
    arch << nodo->libro << endl;
    impLinea(arch, '-', MAXCHAR);
    inorden(nodo->der, arch);
}

void ArbolLibros::impLinea(ofstream& arch, char c, int tam) {
    int i;
    for(i=0; i<tam; i++)
        arch << c;
    arch << endl;
}

void ArbolLibros::incrementar_ventas(const char* cod) {
    class Nodo* p = raiz;
    char codLib[N];
    /*La busqueda se hizo de manera iterativa para evitar llamar al auxiliar*/
    while(p){
        p->libro.GetCodigo(codLib);
        if(strcmp(cod, codLib)<0) p = p->izq;
        else if(strcmp(cod, codLib)>0) p = p->der;
        else if(strcmp(cod, codLib)==0) break;
    }
    (p->libro)++; //Aumentamos las ventas y el monto
}

void ArbolLibros::insertar_autor(int dni, const char* nomb, const char* cod) {
    class Nodo* p = raiz;
    char codLib[N];
    /*Se buscara de manera iterativa*/
    while(p){
        p->libro.GetCodigo(codLib);
        if(strcmp(cod, codLib)<0) p = p->izq;
        else if(strcmp(cod, codLib)>0) p = p->der;
        else if(strcmp(cod, codLib)==0) break;
    }
    p->libro.SetAutor(dni, nomb); //Insertamos el nuevo autor para el libro
    
}

void ArbolLibros::eliminar() {
    eliminarAux(raiz);
}

void ArbolLibros::eliminarAux(Nodo* nodo) {
    /*Se elimina el arbol usando recorrido postorden*/
    if(nodo==NULL) return;
    eliminarAux(nodo->izq);
    eliminarAux(nodo->der);
    delete nodo;
}
