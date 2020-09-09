/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */

#include "Funcioneslaboratorio01.h"

void imprimenumero(void *reg,ofstream& arch){
    void ** aux=(void**)reg;
    int *num;
    num=(int*)aux[0];
    arch<<*num<<endl;
}

void *leenumero(ifstream& arch){
    int *PCant,Cant;
    void **reg;
    
    arch>>Cant;
    cout<<Cant<<endl;
    PCant=new int;
    *PCant=Cant;  
    reg=new void*[1];
    reg[0]=PCant;
    return reg;
}