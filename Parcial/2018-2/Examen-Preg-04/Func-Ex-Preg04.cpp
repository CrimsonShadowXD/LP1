/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Func-Ex-Preg04.h"
#define INC 5

using namespace std;

void *obtenerCantidades(ifstream& arch){
    float CantR,*pCantR,CantC,*pCantC,CantL,*pCantL,CantP,*pCantP,CantO,*pCantO;
    char c;
    void **CantReg;
    
    arch>>CantR;
    pCantR=new float;
    *pCantR=CantR;
    c=arch.get();
    
    arch>>CantC;
    pCantC=new float;
    *pCantC=CantC;
    c=arch.get();
    
    arch>>CantL;
    pCantL=new float;
    *pCantL=CantL;
    c=arch.get();
    
    arch>>CantP;
    pCantP=new float;
    *pCantP=CantP;
    c=arch.get();
    
    arch>>CantO;
    pCantO=new float;
    *pCantO=CantO;
    c=arch.get();
    
    CantReg=new void*[5];
    
    CantReg[0]=pCantR;
    CantReg[1]=pCantC;
    CantReg[2]=pCantL;
    CantReg[3]=pCantP;
    CantReg[4]=pCantO;
    //cout<<CantR<<' '<<CantC<<' '<<CantL<<' '<<CantP<<' '<<CantO<<endl;  
    arch>>ws;
    return CantReg;
}

void *obtenerExtraccion(ifstream& arch){
    int codProv,*pCod,anno,*pAnno;
    char *Especie,NomEsp[50],*Prov,NomProv[100],uniPeso,c;
    void **reg,*Cantidades;
    
    arch>>codProv;
    if(arch.eof())return NULL;
    pCod=new int;
    *pCod=codProv;
    c=arch.get();
    
    arch.getline(NomProv,100,',');
    Prov=new char[strlen(NomProv)+1];
    strcpy(Prov,NomProv);
    
    arch>>anno;
    pAnno=new int;
    *pAnno=anno;
    c=arch.get();
    
    arch.getline(NomEsp,50,',');
    Especie=new char[strlen(NomEsp)+1];
    strcpy(Especie,NomEsp);
    
    uniPeso=arch.get();
    c=arch.get();
    //cout<<*pCod<<' '<<NomProv<<' '<<anno<<' '<<NomEsp<<' '<<uniPeso<<endl;
    Cantidades=obtenerCantidades(arch);
    
    reg=new void*[5];
    reg[0]=pCod;
    reg[1]=Prov;
    reg[2]=pAnno;
    reg[3]=Especie;
    reg[4]=Cantidades;
    return reg;
}

void incrementar(void **&reg,int &n,int &cap){
    void **aux;
    cap+=INC;
    if(reg==NULL){
        reg=new void*[cap];
        reg[0]=NULL;
        n=1;
    }
    else{
        aux=new void*[cap];
        for(int i=0;i<n;i++)
            aux[i]=reg[i];
//        if(reg!=NULL)
//            delete[] reg;
        reg=aux;
    }
}

void leerArch(ifstream& arch,void *&extracciones,int &N){
    void **reg=(void**)extracciones,*auxExtra;
    int cap=0;
    extracciones=NULL;reg=NULL;
    while(1){
        auxExtra=obtenerExtraccion(arch);
        if(auxExtra==NULL)break;
        if(N==cap)incrementar(reg,N,cap);
        reg[N-1]=auxExtra;
        reg[N]=NULL;
        N++;
    }
    extracciones=reg;
}

void leerExtracciones(void *&extracciones,int &N){
    ifstream arch("extracciones.txt",ios::in);
    cout<<setprecision(1)<<fixed;
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    N=0;
    leerArch(arch,extracciones,N);
}







void imprimirCantidades(ofstream& arch,void *reg){
    void **aux=(void**)reg;
    cout<<setprecision(1)<<fixed;
    for(int i=0;i<5;i++){
        float *Cant=(float*)(aux[i]);
        cout<<*Cant<<' ';
    }
    cout<<endl;
}

void imprimir(ofstream& arch,void *reg){
    void **aux=(void**)reg;    
    int *cod=(int*)(aux[0]);
    char *prov=(char*)(aux[1]);
    int *anno=(int*)(aux[2]);
    char *tipo=(char*)(aux[3]);
    cout<<*cod<<' '<<prov<<' '<<*anno<<' '<<tipo<<endl;
    imprimirCantidades(arch,aux[4]);
}

void imprimirExtracciones(void *extracciones,int N){
    void **reg=(void**)extracciones;
    ofstream arch("pregunta4.txt",ios::out);
    //arch<<setprecision(1)<<fixed;
    for(int i=0;i<N-1;i++){
        imprimir(arch,reg[i]);
    }
}