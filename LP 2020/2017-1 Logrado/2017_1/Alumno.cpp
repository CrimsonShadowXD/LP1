

/* 
 * File:   Alumno.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 09:37 PM
 */

#include "Alumno.h"
#include <fstream>
#include <cstring>

using namespace std;

Alumno::Alumno() {
    nombre = NULL;
}

Alumno::~Alumno() {
}
    
    void Alumno::setCodigo(int entrada){
        codigo = entrada;
    }
    int Alumno::getCodigo(){
        return codigo;
    }
    
    void Alumno::setNombre(char* entrada){
        nombre = new char [strlen(entrada)+1];
        strcpy(nombre,entrada);        
    }
    char* Alumno::getNombre(){
        char *aux;
        aux = new char [strlen(nombre)+1];
        strcpy(aux,nombre);
        return aux;        
    }
    
    bool Alumno::operator<(Alumno &b){
        return (codigo<b.codigo);
    }
    bool Alumno::operator ==(Alumno &b){
        return (codigo==b.codigo);
    }
    bool Alumno::operator>(Alumno &b){
        return (codigo>b.codigo);
    }

    void Alumno::leer(ifstream &in){
        int cod; char buff[200];
        in>>cod; if (in.eof()) return;
        in.get();
        in.getline(buff,200,',');
        setCodigo(cod);
        setNombre(buff);
    }
