/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A.cpp
 * Author: crimson
 * 
 * Created on July 4, 2020, 7:37 PM
 */

#include "A.h"

A::A() {
}

A::A(const A& orig) {
}

A::~A() {
}

void A::imprimir(ofstream&arch){
    arch<<'A'<<' '<<GetFil()<<' '<<GetCol()<<endl;
}

void A::mover(char dir,int cant){
    switch(dir){
        case 'P':
            SetFil(GetFil()-cant);
            break;
        case 'Q':
            SetCol(GetCol()+cant);
            break;
        case 'R':
            SetFil(GetFil()+cant);
            break;
        case 'S':
            SetCol(GetCol()-cant);
            break;
    }
}