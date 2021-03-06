/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */
#include "BibliotecaColaGenerica.h"

bool colaVacia(void *cola){
    void **aux=(void**)cola;
    if(cola==NULL){
        return true;
    }
    if(aux[0]==NULL){
        return true;
    }
    else{
        return false;
    }
}


void encola(void *&colaInicio,void *&colaFin,void *dato){
    void **auxInicio=(void**)colaInicio;
    void **auxFin=(void**)colaFin;
    void **nuevo;
    nuevo=new void*[2];
    nuevo[0]=dato;
    nuevo[1]=NULL;
    if(colaInicio==colaFin && colaInicio==NULL){
        colaInicio=nuevo;
        colaFin=nuevo;
    }
    else{
        auxFin[1]=nuevo;
        colaFin=nuevo;
    }
} 

void creaCola(void *&cola,void *(*lee)(ifstream&)){
    void *dato,**aux;
    ifstream arch("Banco-Clientes.csv",ios::in);
    if(!arch){
        cerr<<"Error al abrir el archivo Banco-Clientes.csv"<<endl;
        exit(1);
    }
    aux=new void*[2];
    aux[0]=NULL;
    aux[1]=NULL;
    while(1){
        if(arch.eof())break;
        dato=lee(arch);
        if(dato==NULL)break;
        encola(aux[0],aux[1],dato);
    }
    cola=aux;
}

void *desencolarDato(void *&colaInicio,void *&colaFin){
    void **auxInicio=(void**)colaInicio;
    colaInicio=auxInicio[1];
    return auxInicio[0];
}

void *desencola(void *&cola){
    void **aux=(void**)cola;
    void *resultado;
    if(cola==NULL){
        return NULL;
    }
    else{
        if(!colaVacia(cola)){
            resultado=desencolarDato(aux[0],aux[1]);
            return resultado;
        }
        else{
            return NULL;
        }
    }
} 

void atiendeCola(void *&cola,void (*imprime)(void*,ofstream&)){
    void *ElementoCola;
    ofstream arch("Cola atendida.txt",ios::out);
    int hh, mm,ss;
    cerr<<"Ingrese hora, minutos, y segundos de apertura"<<endl;
    cin>>hh>>mm>>ss;
    arch<<"Hora de apertura: "<<hh<<':'<<mm<<':'<<ss<<endl;
    arch<<left<<setw(8)<<"DNI"<<setw(50)<<"NOMBRE"<<setw(50)<<"DE LLEGADA"<<setw(50)<<"DE ESPERA"<<setw(50)<<"DE SALIDA"<<endl;
    while(!colaVacia(cola)){
        ElementoCola=desencola(cola);
        imprime(ElementoCola, arch);
    }
}