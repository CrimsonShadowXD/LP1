/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Funcioneslaboratorio05.h"
#define N 100
#define NProd 500
#define INC 5
using namespace std;

char *leerCadena(ifstream &arch,char delim){
    char buff[N],*palabra;
    arch.getline(buff,N,delim);
    arch>>ws;
    palabra=new char[strlen(buff)+1];
    strcpy(palabra,buff);
    return palabra;
}

void incEspacios(char **&lAlm,char **&lProd,char **&lPalet,int &num,int &tam){
    char **aux1,**aux2,**aux3;
    tam+=INC;
    cout<<tam<<' '<<num<<endl;
    if(lAlm==NULL){
        lAlm=new char*[tam];
        lProd=new char*[tam];
        lPalet=new char*[tam];
        lAlm[0]=NULL;
        lProd[0]=NULL;
        lPalet[0]=NULL;
        num=1;
    }
    else{
        aux1=new char*[tam];
        aux2=new char*[tam];
        aux3=new char*[tam];
        for(int i=0;i<num;i++){
            
            aux1[i]=lAlm[i];
            aux2[i]=lProd[i];
            aux3[i]=lPalet[i];
        }
        delete[] aux1;
        delete[] aux2;
        delete[] aux3;
        lAlm=aux1;
        lProd=aux2;
        lPalet=aux3;
    }
}

void leerArchivo(char **&lAlm,char **&lProd,char **&lPalet){
    char *auxAlm,*auxProd,*auxPalet;
    int CProd=0,tam=0,num=0;
    lAlm=NULL;
    lProd=NULL;
    lPalet=NULL;
    ifstream Arch("Stock .txt",ios::in);
    if(!Arch){
        cerr<<"Error al abrir Stock .txt"<<endl;
        exit(1);
    }
    while(1){
        auxAlm=leerCadena(Arch,' ');
        auxProd=leerCadena(Arch,' ');
        auxPalet=leerCadena(Arch,'\n');
        cout<<auxAlm<<' '<<auxProd<<' '<< auxPalet<<endl;
        if(tam==num) incEspacios(lAlm,lProd,lPalet,num,tam);
        lAlm[num]=NULL;
        lProd[num]=NULL;
        lPalet[num]=NULL;
        lAlm[num-1]=auxAlm;
        lProd[num-1]=auxProd;
        lPalet[num-1]=auxPalet;
        num++;
        if(Arch.eof())break;
    }
    Arch.close();
}

void leerPalets(char ***&almacenes){
    char **lAlm,**lProd,**lPalet;
    leerArchivo(lAlm,lProd,lPalet);
    almacenes=new char**[4];
    almacenes[0]=lAlm;
    almacenes[1]=lProd;
    almacenes[2]=lPalet;
    almacenes[3]=NULL;
}

void imprimirPalets(char ***almacenes){
    for(int i=0;almacenes[0][i]!=NULL;i++){
        cout<<almacenes[0][i]<<' '<<almacenes[1][i]<<' '<<almacenes[2][i]<<endl;
    }
}
void leerProductos(char **&codigoProd,char **&nombreProd){
    char *BuffProd[500],*BuffNom[500];
    int CProd=0;
    ifstream Arch("Productos.csv",ios::in);
    if(!Arch){
        cerr<<"Error al abrir Productos.csv"<<endl;
        exit(1);
    }
    while(1){
        BuffProd[CProd]=leerCadena(Arch,',');
        BuffNom[CProd]=leerCadena(Arch,'\n');
        cout<<BuffProd[CProd]<<' '<<BuffNom[CProd]<<endl;
        CProd++;
        if(Arch.eof())break;
    }
    Arch.close();
    BuffProd[CProd]=NULL;
    BuffNom[CProd]=NULL;
    codigoProd=new char*[CProd+1];
    nombreProd=new char*[CProd+1];
    for(int i=0;i<=CProd;i++){
        codigoProd[i]=BuffProd[i];
        nombreProd[i]=BuffNom[i];
    }
}
void imprimirProductos(char **codigoProd,char **nombreProd){
    for(int i=0;codigoProd[i]!=NULL;i++){
        cout<<codigoProd[i]<<' '<<nombreProd[i]<<endl;
    }
}
void ordenarproductos(char **&codigoProd,char **&nombreProd){
}
void cuentaproductos(char ***almacenes,char **codigoProd,char **nombreProd){
}