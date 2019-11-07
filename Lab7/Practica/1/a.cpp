/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "a.h"

void *leeRegistros(ifstream& arch){
    char Buff[200],*cod,*nom;
    float *Pprecio,precio;
    void **reg;
    arch.getline(Buff,200,',');
    if(arch.eof())return NULL;
    cod=new char[strlen(Buff)+1];
    strcpy(cod,Buff);
    arch.getline(Buff,200,',');
    nom=new char[strlen(Buff)+1];
    strcpy(nom,Buff);
    arch>>precio;
    Pprecio=new float;
    *Pprecio=precio;
    reg=new void*[3];
    reg[0]=cod;
    reg[1]=nom;
    reg[2]=Pprecio;
    return reg;
}

int compararReg(void *elem,void *dato){
    void **auxElem,**auxDato;
    char *ElemChar,*DatoChar;
    auxElem=(void**)elem;
    auxDato=(void**)dato;
    ElemChar=(char*)auxElem[0];
    DatoChar=(char*)auxDato[0];
    return strcmp(ElemChar,DatoChar);
}

void insertarlista(void *&lista,void *dato,int(*comp)(void*,void*)){
    void **aux=(void**)lista;
    void **nuevo,**ant=NULL;
    nuevo=new void*[2];
    nuevo[0]=dato;
    while(aux){
        if(comp(aux[0],dato)>0)break;
        ant=aux;
        aux=(void**)(aux[1]);
    }
    nuevo[1]=aux;
    if(ant==NULL)lista=nuevo;
    else ant[1]=nuevo;
}

void crearlista(void *&lista,void*(*lee)(ifstream&),int (*comp)(void*,void*)){
    void *dato;
    ifstream arch("productos.csv",ios::in);
    if(!arch){
        cout<<"MAMAAAAAAAAA"<<endl;
        exit(1);
    }
    while(1){
        dato=lee(arch);
        if(dato==NULL)break;
        insertarlista(lista,dato,comp);
    }
}

void imprime(void *reg,ofstream& arch){
    void **aux=(void**)reg;
    char *cod,*nom;
    float *precio;
    cod=(char*)(aux[0]);
    nom=(char*)(aux[1]);
    precio=(float*)(aux[2]);
    arch<<cod<<' '<<left<<setw(60)<<nom<<' '<<*precio<<endl;
}

void imprimelista(void*lista,void(*imprime)(void*,ofstream&)){
    void **aux=(void**)lista;
    ofstream arch("salida.txt",ios::out);
    while(aux){
        imprime(aux[0],arch);
        aux=(void**)aux[1];
    }
}