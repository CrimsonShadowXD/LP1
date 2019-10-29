/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "arbolGen.h"
#include "ManejoArch.h"

void leerCad(ifstream& arch){
    //
}

void *crearArbol(ifstream& arch){
    void *arbol,*reg;
    arbol=NULL;
    while(1){
        reg=leerCad(arch);
        if(reg==NULL)break;
        insertar(arbol,reg);
    }
    return arbol;
}