/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 10:21 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    codigo=NULL;
}

Producto::~Producto() {
    if(codigo)delete codigo;
}

void Producto::GetCodigo(char* cod) const {
    strcpy(cod,codigo);
}

void Producto::SetCodigo(char* cod) {   
    if(codigo)delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Producto::imprimirProducto(ofstream&archOut) {
    
    archOut<<codigo<<endl;
}
