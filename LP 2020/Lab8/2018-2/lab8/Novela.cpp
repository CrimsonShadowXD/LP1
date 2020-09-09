/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: crimson
 * 
 * Created on July 8, 2020, 3:59 AM
 */

#include "Novela.h"

Novela::Novela() {
    for(int i=0;i<300;i++){
        arr[i]=-0.1;
    }
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::operator=(const Novela& nuevo){
    for(int i=0;i<300;i++){
        arr[i]=nuevo.arr[i];
    }
}

ifstream &operator >> (ifstream &in,Novela &nuevo){
    char cad[500];
    in.getline(cad,500,';');
    nuevo.SetTitulo(cad);
    
    in.getline(cad,500,';');
    nuevo.SetAutor(cad);
    int i=0;
    double dato;
    while(1){
        in>>dato;
        
        if(in.peek()==',')in.get();
        if(in.peek()=='\n')break;
        i++;         
    }
}

ofstream &operator << (ofstream &out, const Novela &orig){
    
}