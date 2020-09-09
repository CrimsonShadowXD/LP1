/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 09:37 PM
 */

#include "Intercambio.h"
#include <cstring>
#include <fstream>

using namespace std;

    Intercambio::Intercambio(){
        semestres=0;
        pais=NULL;
        idioma=NULL;
    }
    Intercambio::~Intercambio(){
        
    }
    
    void Intercambio::setPais(char *entrada){
        pais = new char [strlen(entrada)+1];
        strcpy(pais,entrada);
        
    }
    void Intercambio::setIdioma(char* entrada){
        idioma = new char [strlen(entrada)+1];
        
    }
    void Intercambio::setSemestres(int entrada){
        semestres = entrada;
    }
    
    char* Intercambio::getPais(){
        char *aux;
        aux = new char [strlen(pais)+1];
        strcpy(aux,pais);        
        return aux;
    }
    char* Intercambio::getIdioma(){
        char *aux;
        aux = new char [strlen(idioma)+1];
        strcpy(aux,idioma);       
        return aux;        
    }
    
    char Intercambio::getTipo(){ return 'I';}
    
        int Intercambio::getSemestres(){
            return semestres;
        }

    void Intercambio::imprimir(ofstream &out){
         out<<"Codigo de Alumno: "<<this->getCodigo()<<endl;
        out<<"Alumno de Intercambio"<<endl;
        out<<"Nombre de Alumno: "<<this->getNombre()<<endl;       
        out<<"Pais: "<<getPais()<<endl;
        out<<"Permanecerá ";
        if (getSemestres()==1) out<<"1 semestre"<<endl;
        else out<<getSemestres()<<" semestres"<<endl;
    }
    void Intercambio::leer(ifstream &in){
        Alumno::leer(in);
        char buff[200]; int n;
        in.getline(buff,200,',');
        setPais(buff);
        in.getline(buff,200,',');
        setIdioma(buff);
        in>>n; in.get();
        setSemestres(n);
        return;        
    }



 