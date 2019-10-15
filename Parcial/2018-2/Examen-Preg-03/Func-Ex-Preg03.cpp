/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Func-Ex-Preg03.h"
#define INC 5
using namespace std;

int incAux(char ****&pasajeros,char ***&Ruta,int *&Asientos,int &n,int &cap){
    char ****auxP,***auxR;
    int *auxA;
    cap+=INC;
    if (pasajeros==NULL){
        pasajeros=new char***[cap];
        Ruta=new char**[cap];
        Asientos=new int[cap];
        pasajeros[0]=NULL;
        Ruta[0]=NULL;
        Asientos[0]=-1000;
        n=1;
    }
    else{
        auxP=new char***[cap];
        auxR=new char**[cap];
        auxA=new int[cap];
        for(int i=0;pasajeros[i]!=NULL;i++){
            auxP[i]=pasajeros[i];
            auxR[i]=Ruta[i];
            auxA[i]=Asientos[i];
        }
        pasajeros=auxP;
        Ruta=auxR;
        Asientos=auxA;
    }
    
}

void eliminarRutasVacias(char ***&rutas,int *&asientos,char ****&pasajeros){
    char ****auxP,***auxR;
    int *auxA;
    int n,cap;
    n=0;
    cap=0;
    auxP=NULL;
    for(int i=0;rutas[i]!=NULL;i++){
        if(n==cap)incAux(auxP,auxR,auxA,n,cap);
        if(pasajeros[i]!=NULL){
            auxP[n-1]=pasajeros[i];
            auxP[n]=NULL;
            auxR[n-1]=rutas[i];
            auxR[n]=NULL;
            auxA[n-1]=asientos[i];
            auxA[n]=-1111;
            n++;
        }
    }
    rutas=new char**[n+1];
    pasajeros=new char***[n+1];
    asientos=new int[n+1];
    
    for(int i=0;auxP[i]!=NULL;i++){
        rutas[i]=auxR[i];
        pasajeros[i]=auxP[i];
        asientos[i]=auxA[i];
    }
    rutas[n]=NULL;
    pasajeros[n]=NULL;
    asientos[n]=-10000;
}

void incAuxRuta(char **&Ruta,int &n,int &cap){
    char **Aux;
    cap+=INC;
    Aux=new char*[cap];
    for(int i=0;Ruta[i]!=NULL;i++)
        Aux[i]=Ruta[i];
    Ruta=Aux;
}

void limpiarRutas(char **&rutas,char ***pasajeros){
    char **AuxRuta;
    int n=3,cap=3,noEncontrado,j;
    
    AuxRuta=new char*[cap];
    AuxRuta[0]=rutas[0];
    AuxRuta[1]=rutas[1];
    AuxRuta[2]=NULL;
    
    for(int i=2;rutas[i]!=NULL;i++){
        if(n==cap)incAuxRuta(AuxRuta,n,cap);
        j=0;
        noEncontrado=1;
        while(noEncontrado && pasajeros[j]!=NULL){
            noEncontrado=strcmp(rutas[i],pasajeros[j][2]);
            if(!noEncontrado){
                AuxRuta[n-1]=rutas[i];
                AuxRuta[n]=NULL;
                n++;
            }
            j++;
        }
    }
    rutas=new char*[n+1];
    for(int i=0;AuxRuta[i]!=NULL;i++)
        rutas[i]=AuxRuta[i];
    rutas[n]=NULL;
}

void eliminarDestinosVacios(char ***&rutas,char ****&pasajeros){
    for(int i=0;rutas[i]!=NULL;i++){
        limpiarRutas(rutas[i],pasajeros[i]);
    }
}

void redefinirRutas(char ***&rutas,int *&asientos,char ****&pasajeros){
    eliminarRutasVacias(rutas,asientos,pasajeros);
    eliminarDestinosVacios(rutas,pasajeros);
}