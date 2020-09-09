/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: crimson
 * 
 * Created on July 14, 2020, 1:11 PM
 */

#include "Producto.h"

Producto::Producto() {
    cod=NULL;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetCod(const char* cad) {
    if (cad == NULL) return;
    if (cod != NULL) delete cod;
    cod = new char[strlen(cad) + 1];
    strcpy(cod, cad);
}

void Producto::GetCod(char* cad) const {
    if (cod == NULL)
        return;
    strcpy(cad, cod);
}

void Producto::leer(ifstream&in){
    char cad[50],c;
    c=13;
    in.getline(cad,50,c);
    SetCod(cad);
    in>>ws;
}

void Producto::imprimir(ofstream&out){
    char cad[10];
    GetCod(cad);
    out<<'('<<cad<<')'<<endl;
    out<<"---------------------------"<<endl;
    lpallet.imprime(out);
}

void Producto::llenarP(ifstream&in){
    lpallet.crear(in);
}

void Producto::llenarPedidos(ifstream&in){
    cpedido.crear(in);
}

void Producto::imprimirPedidos(ofstream&out){
    char cad[10];
    GetCod(cad);
    out<<'('<<cad<<')'<<endl;
    out<<"---------------------------"<<endl;
    cpedido.imprimir(out);
}

void Producto::atPedidos(){
    Pedido aux;
    int CantKgfalt;
    while(!cpedido.vacia()){
        aux=cpedido.Pop();
//        cout<<aux.GetCantkg()<<' '<<aux.GetPedido()<<endl;
        CantKgfalt=aux.GetCantkg();
        
    }
}

