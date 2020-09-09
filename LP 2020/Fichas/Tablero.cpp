/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 9:04 PM
 */

#include "Tablero.h"

Tablero::Tablero() {
    numfichas=0;
}

Tablero::Tablero(const Tablero& orig) {
}

Tablero::~Tablero() {
}

void Tablero::leerFichas(ifstream &arch){
    char cad[10],tipo;
    int f,c;
    while(1){
        arch>>cad;
        if(arch.eof())
            break;
        arch>>tipo;
        arch>>f;
        arch>>c;
        colocarFichas(cad,tipo,f,c);
    }
}

void Tablero::colocarFichas(char *id,char t,int f,int c){
    switch(t){
        case 'A':
            ficha[numfichas]=new A;
            break;
        case 'B':
            ficha[numfichas]=new B;
            break;
        case 'C':
            ficha[numfichas]=new C;
            break;
    }
    ficha[numfichas]->asigna(id,f,c);
    numfichas++;
}

void Tablero::leerMovimientos(ifstream &arch){
    char cad[10],tipo;
    int cant;
    while(1){
        arch>>cad;
        if(arch.eof())break;
        arch>>tipo;
        arch>>cant;
        moverFicha(cad,tipo,cant);
    }
}

void Tablero::moverFicha(char *id,char t,int cant){
    char cad[10];
    int maximo=numfichas;
    for(int i=0;i<maximo;i++){
        ficha[i]->GetId(cad);
        if(strcmp(cad,id)==0){
            ficha[i]->mover(t,cant);
            return;
        }
    }
}

void Tablero::imprimeDatos(ofstream&arch){
    int maximo=numfichas;
    for(int i=0;i<maximo;i++){
        ficha[i]->imprimir(arch);
    }
}

