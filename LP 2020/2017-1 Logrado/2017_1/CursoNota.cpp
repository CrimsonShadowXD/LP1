
/* 
 * File:   CursoNota.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 10:17 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include "CursoNota.h"

using namespace std;

    CursoNota::CursoNota(){
        codigo=NULL;
        nota=0;
        
    }
    CursoNota::~CursoNota(){
        
    }
    
    void CursoNota::setCodigo(char *entrada){
        codigo = new char [strlen(entrada)+1];
        strcpy(codigo,entrada);    
    }
    
    void CursoNota::setNota(int entrada){
        nota = entrada;
    }
    
    char* CursoNota::getCodigo(){
        char *aux;
        aux = new char [strlen(codigo)+1];
        strcpy(aux,codigo);
        return aux;
        
    }
    int CursoNota::getNota(){
        return nota;        
    }
    
    void CursoNota::imprimir(ofstream &out){
        out<<getCodigo()<<"   "<<getNota()<<endl;        
    }
    
    void CursoNota::leer(ifstream &in){
        char buff[50]; int n;
        in.getline(buff,50,',');
        in>>n;in.get(); if (in.eof()) return;
        
        setCodigo(buff);
        setNota(n);
    }
    
    ofstream& operator<<(ofstream &out, CursoNota &reg){
        reg.imprimir(out);
        return out;
    }