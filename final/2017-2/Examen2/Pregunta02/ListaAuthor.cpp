/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAuthor.cpp
 * Author: alulab14
 * 
 * Created on 5 de diciembre de 2017, 08:13 AM
 */
//20150008 Daniela Cisneros
#include "ListaAuthor.h"

ListaAuthor::ListaAuthor() {
    lista=NULL;
}

ListaAuthor::ListaAuthor(const ListaAuthor& orig) {
}

ListaAuthor::~ListaAuthor() {
    
}

void ListaAuthor::insertar(Author& d) {
    NodoAuthor *p=lista, *ant=NULL,* nuevo;
    nuevo = new NodoAuthor;
    nuevo->dato=d;
    while(p){
        if(p->dato>d) break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant !=NULL) ant->sig=nuevo;
    else lista=nuevo;
}

void ListaAuthor::eliminar() {
   NodoAuthor *p=lista, *ant;
   while(p){
        p->lstPapers.eliminar();
        ant=p;
        p=p->sig;
        delete ant;
    }

}

void ListaAuthor::imprimir(ostream& arch) {
    NodoAuthor *p=lista;
    while(p){
        arch<<p->dato;
        p->lstPapers.imprimir(arch);
        arch<<endl;
        p=p->sig;
    }
}

void ListaAuthor::insertarPaper(int cod, Paper* dato) {
    NodoAuthor *p=lista;
    while(p){
        if(p->dato.GetId()==cod) {
            p->lstPapers.insertar(dato);
            break;
        }
        
        p=p->sig;
    }
}
