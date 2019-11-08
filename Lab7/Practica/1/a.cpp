/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "a.h"

void *leeRegistros(ifstream& arch){
    char BuffCod[10],BuffNom[200],*cod,*nom;
    float *Pprecio,precio;
    void **reg;
    arch.getline(BuffCod,10,',');
    if(arch.eof())return NULL;
    cod=new char[strlen(BuffCod)+1];
    strcpy(cod,BuffCod);
    arch.getline(BuffNom,200,',');
    nom=new char[strlen(BuffNom)+1];
    strcpy(nom,BuffNom);
    arch>>precio;
    arch>>ws;
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

void eliminaReg(void *d){ 
    void **aux=(void**)d;
    char *cod = (char*)aux[0];
    char *nom = (char*)aux[1];
    float *precio = (float*)aux[2];
    delete[]cod;
    delete[]nom;
    delete[]precio;
}

void eliminalista(void *lista,void(*elimina)(void*)){   
    void **aux=(void**)lista,**paux;

    while(aux){   
        paux = aux;
        aux = (void**)(aux[1]);
        elimina(paux[0]);
        delete[]paux;
    }    

}

int contarElem(void *lista){
    int cant=0;
    void **aux=(void**)lista;
    while(aux){
        cant++;
        aux=(void**)aux[1];
    }
    return cant;
}

void crearPila(void *&lista,void *&dep){
    void **aux1 = (void**)lista;
    void **aux2=NULL,**prec,**pant;
    
    prec = aux1;
    while(prec){
        pant = prec;
        prec = (void**)prec[1];
        if(aux2==NULL){
            pant[1]=NULL;
            aux2 = pant;
        }
        else{
            pant[1] = aux2;
            aux2 = pant;
        }
    }
    dep = aux2;
}

