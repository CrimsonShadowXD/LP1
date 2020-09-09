/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 7:38 PM
 */

#include "C.h"

C::C() {
}

C::C(const C& orig) {
}

C::~C() {
}

void C::imprimir(ofstream&arch){
    arch<<'C'<<' '<<GetFil()<<' '<<GetCol()<<endl;
}

void C::mover(char dir,int cant){
    switch(dir){
        case 'P':
            SetFil(GetFil()-2);
            SetCol(GetCol()-1);
            break;
        case 'Q':
            SetFil(GetFil()-1);
            SetCol(GetCol()+2);
            break;
        case 'R':
            SetFil(GetFil()+2);
            SetCol(GetCol()+1);
            break;
        case 'S':
            SetFil(GetFil()+1);
            SetCol(GetCol()-2);
            break;
    }    
}

