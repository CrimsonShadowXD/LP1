
/* 
 * File:   AlIntercambio.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 6 de julio de 2020, 18:24
 */

#include "AlIntercambio.h"
#include <cstring>
#include <fstream>

using namespace std;

AlIntercambio::AlIntercambio() {
    nSemestres=0;
    idiomas=nullptr;
    pais=nullptr;
    
}

void AlIntercambio::setNSemestres(int nSemestres) {
    this->nSemestres = nSemestres;
}

int AlIntercambio::getNSemestres() const {
    return nSemestres;
}

void AlIntercambio::setIdiomas(char** &idiomas) {
    this->idiomas = idiomas; 
}


void AlIntercambio::setPais(char* pais) {
         this->pais = new char [strlen(pais)+1];
    strcpy(this->pais,pais);
}

char* AlIntercambio::getPais() const {
       char *salida = new char [strlen(this->pais)+1];
    strcpy(salida,this->pais);
    return salida;
}


AlIntercambio::~AlIntercambio() {
    if (idiomas) delete[] idiomas;
    if (pais) delete[] pais;
}

   void AlIntercambio::imprimir(ofstream &out){
         out<<"Codigo de Alumno: "<<GetCodigo()<<endl;
    out<<"Alumno de Intercambio\nNombre del alumno:"<<GetNombre()<<endl;
    out<<"Pais: "<<getPais()<<endl;
    out<<"Idiomas: ";  
    for(int i=0; this->idiomas[i];i++){
        out<<idiomas[i]<<' '; if (idiomas[i+1]) out<<"- ";
               
    } out<<endl;
    out<<"Permanecerá 4 semestres"<<endl;
    
   }
   
   void AlIntercambio::leer(ifstream &in){
       int codigo; char buff[500]; int semestres=-1; int n=0;
       char *buffIdiomas[20];
    in>>codigo; in.get(); if (in.eof()) return;
    in.getline(buff,500,',');
    this->SetNombre(buff);
    in.getline(buff,500,','); //Leemos el pais.
    this->setPais(buff);
    //Leemos los idiomas que habla.
    while(1){
        in>>semestres; if (semestres!=-1) break; //Se detiene cuando hallamos los semestres.
        in.clear();
        in.getline(buff,500,',');
        buffIdiomas[n]=new char [strlen(buff)+1];
        strcpy(buffIdiomas[n],buff);
        n++;           
    }
    char **idiomas = new char* [n+1];
    for(int i=0;i<n;i++) idiomas[i]=buffIdiomas[i];
    idiomas[n]=nullptr;
    this->setIdiomas(idiomas); //Setter de los idiomas.
    this->setNSemestres(semestres);
   }
   
   char AlIntercambio::getTipo(){
       return 'I';
   }

