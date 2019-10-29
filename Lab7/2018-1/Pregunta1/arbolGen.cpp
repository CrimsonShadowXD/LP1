/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "arbolGen.h"
enum ABB {DATO,IZQ,DER};

void *crearNodo(void *reg){
    void **Aux;
    Aux=new void*[3];
    Aux[DATO]=reg;
    Aux[IZQ]=NULL;
    Aux[DER]=NULL;
}

int comparar(void *dato,void *reg){
    void **AuxDato=(void**)dato,**AuxReg=(void**)reg;
    char *strDato,*strReg;
    strDato=(char*)AuxDato[0];
    strReg=(char*)AuxReg[0];
    return strcmp(strDato,strReg);    
}

void insertar(void *nodoActual,void *reg){
    void **nodoAux=(void**)nodoActual;
    if(nodoActual==NULL)
        nodoActual=crearNodo(reg);
    else{
        int comp=comparar(nodoAux[DATO],reg);
        if (comp<0)
            insertar(nodoAux[IZQ],reg);
        else
            insertar(nodoAux[DER],reg);
    }
}

