/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rodrigo
 * 
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include "Vehiculo.h"
#include <fstream>
#include <iterator>
#include <cstring>

using namespace std;

Vehiculo::Vehiculo() {
    placa = NULL;
}

 void Vehiculo::setPlaca(char *entrada){
     if (placa) delete[] placa;
     placa = new char [strlen(entrada)+1];
     strcpy(placa,entrada);
 }
    char* Vehiculo::getPlaca(){
        char *aux;
        aux = new char [strlen(placa)+1];
        strcpy(aux,placa);
        return aux;        
    }
    
    void Vehiculo::leer(ifstream &in){
        char *plac = new char [8];
        in.get(plac,8);
        setPlaca(plac);
    }
    void Vehiculo::imprimir(ofstream &out){
        out<<placa<<"  | Infracciones: ";
        if (infracciones.empty()) out<<"No posee"<<endl;
        else{list<int>::iterator it;
        for(it = infracciones.begin(); it !=infracciones.end() ; it++) out<<*it<<' ';
        out<<endl;            
        }
        
    }
    
    void Vehiculo::multar(int codigo){
        infracciones.push_back(codigo);
    }
    
    int* Vehiculo::obtenerMultas(){
        int* salida; int buff[100],n=0;
        for(list<int>::iterator it=infracciones.begin(); it!= infracciones.end(); it++){
            buff[n]=*it;
            n++;
        }
        salida = new int [n+1];
        for(int i=0;i<n;i++) salida[i] = buff [i];
        salida[n]=-1;
        
        return salida;
    }
    
    bool Vehiculo::operator>(Vehiculo orig){
        return (strcmp(placa,orig.placa)>0);
    }
