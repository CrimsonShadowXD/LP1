/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contenedor.cpp
 * Author: cueva
 * 
 * Created on 1 de julio de 2020, 01:04 PM
 */
#include <iostream>
#include <fstream>
#include "sobrecarga.h"
#include "Intercambio.h"
#include "Nacional.h"
#include "contenedor.h"

contenedor::contenedor() {
}

contenedor::contenedor(const contenedor& orig) {
}

contenedor::~contenedor() {
}
//I;5258;Gavidia/Mendoza/Ronald-Johnny;Japon;Japones;2

void contenedor::lee(){
    char tipo;
    int i=0,j=0;

    ifstream arch("Alumnos.csv",ios::in);
    if(!arch){
        cout << "No se puede abrir";
        exit(1);
    }
    while(1){
        arch >> tipo;
        if(arch.eof()) break;
        arch.get();
        if(tipo=='I'){
            arch >> inter[i];
            i++;
        }
        else{
            arch >> nacio[j];
            j++;
        }
    }
}




void contenedor::imprime(){
    int i=0,j=0;
    
    ofstream archi("Intercambio.txt",ios::out);
    if(!archi){
        cout << "No se puede abrir";
        exit(1);
    }
    while(1){
        if(inter[i].GetCodigo()<0)
            break;
        archi << inter[i];  
        i++;
    }

    ofstream archn("Nacional.txt",ios::out);
    if(!archn){
        cout << "No se puede abrir";
        exit(1);
    }
    while(1){
        if(nacio[j].GetCodigo()<0)
            break;
        archn << nacio[j];  
        j++;
    }
}
