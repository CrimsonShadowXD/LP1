/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaProductos.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 10:33 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaProductos.h"

ListaProductos::ListaProductos() {
    listaProductos=NULL;
}

ListaProductos::~ListaProductos() {
    NodoProducto *p=listaProductos,*sale;
    while(p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}

void ListaProductos::leerProductos(ifstream&archIn  ) {
    char codProd[100];
    
    while(1){
        archIn.getline(codProd,100);
        if(archIn.eof())break;
        insertarProducto(codProd);
    }
}

void ListaProductos::insertarProducto(char*codProd) {
    NodoProducto*p=listaProductos,*ant=NULL,*nuevo;
    nuevo=new NodoProducto;
    nuevo->producto.SetCodigo(codProd);
    while(p){
        char codP[100];
        p->producto.GetCodigo(codP);
        if(strcmp(codP,codProd)>0)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant)ant->sig=nuevo;
    else listaProductos=nuevo;
}

void ListaProductos::imprimirProductos(ofstream&archOut) {
    NodoProducto*p=listaProductos;
    archOut<<"Codigo Producto"<<endl;
    while(p){
        p->producto.imprimirProducto(archOut);
        p=p->sig;
    }
}
