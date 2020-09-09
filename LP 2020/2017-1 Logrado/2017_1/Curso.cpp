/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Rodrigo
 * 
 * Created on 9 de diciembre de 2019, 12:14 AM
 */

#include <fstream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Curso.h"
#include <iomanip>

using namespace std;

Curso::Curso() {
    this->codigo=0;
    this->creditos=0;
    this->nombre=0;
}

Curso::~Curso(){
    
}
    
    void Curso::setCodigo(char *entrada){
        codigo = new char [strlen(entrada)+1];
        strcpy(codigo,entrada);
        
    }
    void Curso::setNombre(char* entrada){
      nombre = new char [strlen(entrada)+1];
        strcpy(nombre,entrada);
    }
    void Curso::setCreditos(double entrada){
        creditos = entrada;        
    }
    
    char*Curso::getCodigo(){
        char *aux;
           aux = new char [strlen(codigo)+1];
        strcpy(aux,codigo);
        
    }
    char*Curso::getNombre(){
          char *aux;
           aux = new char [strlen(nombre)+1];
        strcpy(aux,nombre);
        
    }
    double Curso::getCreditos(){
        return creditos;
    }
    
    char** Curso::getRequisitos(){
        int n=0; char* buff[200];
         for(vector<char*>::iterator it=requisitos.begin(); it != requisitos.end() ; it ++) {
             buff[n]=*it;
             n++;
         }
        char** aux = new char* [n+1];
        for(int i=0;i<n;i++) aux[i] = buff[i];
        aux[n]=NULL;
        return aux;
    }
    
    void Curso::leer(ifstream &in){
        char buffCod[150],buffNom[150],buff[7],*aux;
        double n;
        
        in.getline(buffCod,150,',');
        in.getline(buffNom,150,',');
        in>>n; in.get();
        
        if (in.eof()) return;
        
        this->setCodigo(buffCod);
        this->setCreditos(n);
        this->setNombre(buffNom);
        
        while(1){
            aux = new char[7];
            in.get(buff,7);
            strcpy(aux,buff);
            requisitos.push_back(aux);
            if (in.peek()=='\n') {in.get();break;}
            in.get();
        }       
    }
    void Curso::imprimir(ofstream &out){
        out<<codigo<<"    "<<nombre<<setw(70-strlen(nombre));
        out<<creditos<<"   ";
        for(vector<char*>::iterator it=requisitos.begin(); it != requisitos.end() ; it ++) out<<*it<<' ';
        out<<endl;
        
    }
