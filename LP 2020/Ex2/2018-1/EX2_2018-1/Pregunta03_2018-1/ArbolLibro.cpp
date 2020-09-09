/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *File:   ArbolLibro.cpp
 * Author: JHERSON JAIR ZUÑIGA SALAS
 * Codigo: 20145795
 * Created on 18 de julio de 2020, 04:06 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "ArbolLibro.h"
#include "Nodo.h"
#include "Libro.h"

ArbolLibro::ArbolLibro() {
    arbol = nullptr;
}
ArbolLibro::~ArbolLibro() {
}

void ArbolLibro::crear(ifstream& arch) {
    class Libro lb;
    while (1){
        arch>>lb;
        if (arch.eof()) break;
        insertar(lb,arbol);
    }
    int x = 5;
}

void ArbolLibro::insertar(Libro& libro, Nodo*& arbol) {
    if (arbol == nullptr){
        arbol = new class Nodo;
        arbol->libro = libro;
        
        return;
    }
    char codLibArb[10], codLib[10];
    arbol->libro.GetCodigo(codLibArb);
    libro.GetCodigo(codLib);
    if ( strcmp(codLib,codLibArb)<0)
        insertar(libro,arbol->izq);
    else insertar(libro,arbol->der);
}

void ArbolLibro::completarAutores(ifstream& arch) {
    char nomAutor[50], codLib[7];
    int dniAutor, longitud;
    class Nodo *libroBuscado;
    while (1){
        arch>>dniAutor;
        if (arch.eof()) return;
        arch.get();
        arch.getline(nomAutor,50,',');
        while (1){
            arch.get(codLib,7);
            if (arch.get()=='\n') break;
            libroBuscado = buscarLibro(codLib);
            if (libroBuscado)
                libroBuscado->libro.SetAutor(dniAutor,nomAutor);
        }
        
        
    }
}

Nodo* ArbolLibro::buscarLibro(char* codLib) {
    class Nodo *p = arbol;
    char codLibArb[7];
    while (p){
        p->libro.GetCodigo(codLibArb);
        if (strcmp(codLib,codLibArb)==0) return p;
        if ( strcmp(codLib,codLibArb)<0 ) p = p->izq;
        else if ( strcmp(codLib,codLibArb)>0 ) p = p->der;
    }
    return nullptr;

}

void ArbolLibro::registrarVentas(ifstream& arch) {
    char fechaHora[20], codLib[7];
    class Nodo *libroBuscado;
    
    while (1){
        arch.getline(fechaHora,20,',');
        if (arch.eof()) break;
        arch.getline(fechaHora,20,',');
        arch.getline(codLib,7);
        libroBuscado = buscarLibro(codLib);
        if (libroBuscado)
            ++libroBuscado->libro;
    }

}

void ArbolLibro::reporte(ofstream& arch) {
    arch<<right<<setw(70)<<"RELACION DE LIBROS DE LA LIBRERIA"<<endl;
    for (int i = 0; i < 100; i++) 
         arch<<'=';
    arch<<endl;
    arch<<left<<setw(6)<<"No."<<setw(10)<<"CODIGO"<<
            setw(62)<<"Titulo"<<setw(45)<<"Autores"<<
            setw(15)<<"Precios"<<setw(15)<<"Vendidos"<<
            setw(10)<<"Monto"<<endl;
    int n=0;
    imprimeRec(arch,arbol, n);

}

void ArbolLibro::imprimeRec(ofstream& arch, Nodo* arbol, int &n) {
    if (arbol == nullptr) return;
    imprimeRec(arch,arbol->izq,n);
    n++;
    arch<<right<<setw(4)<<n<<") ";
    arch<<arbol->libro;
    imprimeRec(arch,arbol->der,n);
}

void ArbolLibro::eliminaArbol() {
    eliminaRec(arbol);
}

void ArbolLibro::eliminaRec(Nodo*& arbol) {
    class Nodo *arbDer;
    if (arbol == nullptr)return;
    eliminaRec(arbol->izq);
    arbDer = arbol->der;
    delete arbol;
    eliminaRec(arbDer);
    
}
