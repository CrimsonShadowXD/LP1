/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   B.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 7:38 PM
 */

#include "B.h"

B::B() {
}

B::B(const B& orig) {
}

B::~B() {
}

void B::imprimir(ofstream&arch){
    arch<<'B'<<' '<<GetFil()<<' '<<GetCol()<<endl;
}

void B::mover(char dir,int cant){
    switch(dir){
        case 'P':
            SetFil(GetFil()-cant);
            SetCol(GetCol()-cant);
            break;
        case 'Q':
            SetFil(GetFil()-cant);
            SetCol(GetCol()+cant);
            break;
        case 'R':
            SetFil(GetFil()+cant);
            SetCol(GetCol()+cant);
            break;
        case 'S':
            SetFil(GetFil()+cant);
            SetCol(GetCol()-cant);
            break;
    }    
}