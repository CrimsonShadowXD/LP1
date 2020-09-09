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
    int *Pdni,*PHora,horallegada;
    char *PNom;
    float *PTiempo;
    Pdni=(int*)aux[0];
    PNom=(char*)aux[1];
    PHora=(int*)aux[2];
    PTiempo=(float*)aux[3];
    arch<<*Pdni<<' '<<left<<setw(5)<<PNom<<' '<<*PHora<<' '<<*PTiempo<<endl;
}

void *leenumero(ifstream& arch){
    char BuffNom[200],*PNom,coma;
    int *Pdni,DNI,*PHora, hora, mm, ss, horallegada;
    float *PTiempo,tiempo;
    void **reg;
    
    arch>>DNI>>coma;    
    if(arch.eof())return NULL;
    Pdni=new int;
    *Pdni=DNI;  
    
    arch.getline(BuffNom,200,',');
    PNom=new char[strlen(BuffNom)+1];
    strcpy(PNom,BuffNom);
    
    arch>>hora>>coma>>mm>>coma>>ss>>coma;
    horallegada=hora*10000+mm*100+ss;
    PHora=new int;
    *PHora=horallegada;  
    
    arch>>tiempo;
    PTiempo=new float;
    *PTiempo=tiempo;  
    
    reg=new void*[4];
    reg[0]=Pdni;
    reg[1]=PNom;
    reg[2]=PHora;
    reg[3]=PTiempo;
    return reg;
}