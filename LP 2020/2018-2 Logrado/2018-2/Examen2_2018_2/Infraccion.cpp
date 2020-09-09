/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: Rodrigo
 * 
 * Created on 7 de diciembre de 2019, 07:28 PM
 */

#include "Infraccion.h"
#include <cstring>
#include <fstream>

#include <iostream>

using namespace std;

Infraccion::Infraccion() {
    concepto = NULL;
}

Infraccion::~Infraccion() {
}

    int Infraccion::getCodigo(){
        return codigo;
    }
    double Infraccion::getMonto(){
        return monto;
    }
    char* Infraccion::getConcepto(){
        char *aux;
        aux = new char [strlen(concepto)+1];
        strcpy(aux,concepto);
        return aux;
    }
    
     char* Infraccion::getGravedad(){
          char *aux;
        aux = new char [strlen(gravedad)+1];
        strcpy(aux,gravedad);
        return aux;
     }
    
    void Infraccion::setConcepto(char* entrada){
        concepto = new char [strlen(entrada)+1];
        strcpy(concepto,entrada);
    }
    
       void Infraccion::setGravedad(char* entrada){
           gravedad = new char [strlen(entrada)+1];
           strcpy(gravedad,entrada);           
       }
       
    void Infraccion::setCodigo(int entrada){
        codigo = entrada;        
    }
    void Infraccion::setMonto(int entrada){
        monto = entrada;        
    }
    
    bool Infraccion::operator<(Infraccion b){
        return  (codigo<b.codigo);
    }
    bool Infraccion::operator>(Infraccion b){
        return  (codigo>b.codigo);
    }
    bool Infraccion::operator==(Infraccion b){
        return  (codigo==b.codigo);
    }
    
    void Infraccion::imprimir(ofstream &out){
        out<<"Codigo: "<<codigo<<" | Monto: "<<monto<<endl;
        out<<"Gravedad: "<<gravedad<<" | "<<concepto<<endl;
        
    }
    void Infraccion::leer(ifstream &in){
        char buff[400],buff2[60]; int cod; double plata;
        in>>cod;   if (in.eof()) return;
        in.get();
        in.getline(buff,400,',');
        in.getline(buff2,60,',');
        in>>plata;
      
            setMonto(plata);
            setConcepto(buff);
            setCodigo(cod);        
            setGravedad(buff2);
    }

