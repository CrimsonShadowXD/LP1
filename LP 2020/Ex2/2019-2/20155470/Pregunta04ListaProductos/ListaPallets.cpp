/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPallets.cpp
 * Author: Alexis Johan Andres Avelino Campos 20155470
 * 
 * Created on 10 de diciembre de 2019, 10:03 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaPallets.h"

ListaPallets::ListaPallets() {
    listaPallets=NULL;
}

ListaPallets::~ListaPallets() {
    NodoPallet *p=listaPallets,*sale;
    
    while(p){
        sale=p;
        p=p->sig;
        delete sale;
    }
    
}

void ListaPallets::leerPallets(ifstream&archIn) {
    char tipo[100];
    while(1){
        archIn.getline(tipo,100,',');
        if(archIn.eof())break;
        insertarPallet(tipo,archIn);
    }
    
}

void ListaPallets::insertarPallet(char* tipo,ifstream&archIn) {
    NodoPallet *p=listaPallets,*ant=NULL,*nuevo;
    nuevo=new NodoPallet;
    nuevo->pallet.definirTipo(tipo);
    nuevo->pallet.leerDatos(archIn);
    char idNuevo[100];
    nuevo->pallet.devolverId(idNuevo);
    while(p){
        char idP[100];
        p->pallet.definirTipo(idP);
        if(strcmp(idP,idNuevo)>0)break;
        ant=p;
        p=p->sig;
    }
    nuevo->sig=p;
    if(ant)ant->sig=nuevo;
    else listaPallets=nuevo;
}

void ListaPallets::imprimirPallets(ofstream&archOut) {
    NodoPallet*p=listaPallets;
    archOut<<left<<setw(15)<<"IDENTIFICADOR"<<setw(15)<<"CAPACIDAD"<<setw(15)<<"TIPO"<<endl;
    while(p){
        p->pallet.imprimirDatos(archOut);
        p=p->sig;
    }
}
