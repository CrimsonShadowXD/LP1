/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: crimson
 * 
 * Created on July 19, 2020, 1:09 PM
 */

#include "Arbol.h"

Arbol::Arbol() {
    inicio = NULL;
}

Arbol::~Arbol() {
    eliminarNodo(inicio);
}

void Arbol::crear(ifstream&in) {
    while (1) {
        class Libro dato;
        in>>dato;
        if (in.eof())break;
        insertar(inicio, dato);
    }
}

void Arbol::insertar(NodoArbol *&nodo, const Libro& dato) {
    class NodoArbol *nuevo;
    if (nodo == NULL) {
        nuevo = new class NodoArbol;
        nuevo->elem = dato;
        nodo = nuevo;
    } else {
        if (nodo->elem > dato)
            insertar(nodo->izq, dato);
        else
            insertar(nodo->der, dato);
    }
}

void Arbol::imprimeNodo(NodoArbol *nodo, ofstream&out) {
    if (nodo == NULL)return;
    imprimeNodo(nodo->izq, out);
    out << nodo->elem << endl;
    imprimeNodo(nodo->der, out);
}

void Arbol::imprimir(ofstream&out) {
    imprimeNodo(inicio, out);
}

void Arbol::eliminarNodo(NodoArbol*nodo) {
    if (nodo == NULL)return;
    eliminarNodo(nodo->izq);
    class NodoArbol *aux;
    aux = nodo->der;
    delete nodo;
    eliminarNodo(aux);
}

NodoArbol* Arbol::buscarNodo(const char *codLib) {
    class NodoArbol *p=inicio;
    int n;
    char cad[10];
    while(p){
        p->elem.GetCodigo(cad);
        n=strcmp(codLib,cad);
        if(n==0) return p;
        else if(n<0) p=p->izq;
        else if(n>0) p=p->der;
    }
    return NULL;
}

bool Arbol::vacia() {
    return (inicio == NULL);
}



void Arbol::completarAutores(ifstream&archIn){
    int dni,lon;
    char nom[100],buff[7];
    NodoArbol *auxL;
    while(1){
        archIn>>dni;
        if(archIn.eof())break;
        archIn.get();
        archIn.getline(nom,100,',');
        while(1){
            archIn.get(buff,7);
            char c=archIn.get();
            auxL=buscarNodo(buff);
            if(auxL!=NULL){                
                cout<<buff<<','<<endl;
                Autor auxA;
                auxA.SetDni(dni);
                auxA.SetNombre(nom);
                auxL->elem.MeterLibro(auxA);
            }
            if(c==13 || c=='\n'){
               break; 
            }
        }
        cout<<endl;
    }
}

void Arbol::registrarVentas(ifstream&inx){
    NodoArbol *auxL;
    int numero;
    char sep,cad[7];
    while(1){
        inx>>numero>>sep;
        if(inx.eof())break;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        inx>>numero>>sep;
        sep=13;
        inx.getline(cad,7,sep);  
        cout<<cad<<';'<<endl;
        auxL=buscarNodo(cad);
        if(auxL!=NULL)++auxL->elem;
    }
}