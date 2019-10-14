/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Func-Ex-Preg01.h"
#define INC 5

using namespace std;

void incrementarReg(char **&reg,int &n,int &cap){
    char **aux;
    cap+=INC;
    aux=new char*[cap];
    for(int i=0;i<n;i++)
        aux[i]=reg[i];
    reg=aux; 
}

char **ObtenerCliente(ifstream& arch){
    char c,*cod,*Nomb,*Destinos[150],*aux,**reg;
    int n,cap;
    n=3,cap=3;
    
    
    cod=new char[9];
    arch.getline(cod,9,',');
    
    
    Nomb=new char[100];
    arch.getline(Nomb,100,',');
    //cout<<cod<<' '<<Nomb<<endl;
    
    reg=new char*[cap];
    reg[0]=cod;
    reg[1]=Nomb;
    reg[2]=NULL;
    while(!isdigit(arch.peek())){
        aux=new char[60];
        if(n==cap)incrementarReg(reg,n,cap);
        arch.getline(aux,60,',');
        reg[n-1]=aux;
        reg[n]=NULL;
        n++;
    }
    return reg;
}

int obtenerAsientos(ifstream& arch){
    int asientos=0;
    arch>>asientos;
    arch>>ws;
    return asientos;
}

void incrementarRutas(char ***&rutas,int *&asientos,int &n, int &cap){
    char ***aux;
    int *auxINT;
    cap+=INC;
    if(rutas==NULL){
        rutas=new char**[cap];
        asientos=new int[cap];
        n=1;
        rutas[0]=NULL;
        asientos[0]=-1000;
    }
    else{
        aux=new char**[cap];
        auxINT=new int[cap];
        for(int i=0;i<n;i++){
            aux[i]=rutas[i];
            auxINT[i]=asientos[i];
        }
        rutas=aux;
        asientos=auxINT;
    }
}

void leerRutas(char ***&rutas,int *&asientos){
    char **aux,c;
    int auxInt;
    int n,cap;
    
    ifstream arch("a.csv",ios::in);
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    rutas=NULL;
    asientos=NULL;
    n=0,cap=0;
    while(1){
        c=arch.peek();
        if(c=='\n'||isdigit(c))break;
        aux=ObtenerCliente(arch);     
        auxInt=obtenerAsientos(arch);
        if(n==cap)incrementarRutas(rutas,asientos,n,cap);
        rutas[n-1]=aux;
        asientos[n-1]=auxInt;
        rutas[n]=NULL;
        n++;
    }
    arch.close();
}

void imprimirRuta(ofstream& arch,char **ruta){
    arch<<"Cod: "<<ruta[0]<<' '<<"Nombre: "<<ruta[1]<<endl;
    arch<<"Destinos:"<<endl;
    for(int i=2;ruta[i]!=NULL;i++)
        arch<<setw(30)<<' '<<ruta[i]<<endl;
}

void imprimirRutas(char ***rutas,int *asientos){
    ofstream arch("1.txt",ios::out);
    
    for (int i=0;rutas[i]!=NULL;i++){
        imprimirRuta(arch,rutas[i]);
        arch<<"asientos: "<<asientos[i]<<endl<<endl;
    }
}