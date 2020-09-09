
/* 
 * File:   Persona.cpp
* Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 3 de julio de 2020, 08:05
 */
#include <cstring>
#include "Persona.h"
#include <fstream>

using namespace std;

Persona::Persona() {
    nombre= nullptr;
    codigo=0;
    distrito= nullptr;
}
Persona::Persona(const Persona &orig){
    SetNombre(orig.GetNombre());
    SetCodigo(orig.GetCodigo());
    SetDistrito(orig.GetDistrito());
}


Persona::~Persona() {
    if (nombre) delete[] nombre;
    if (distrito) delete[] distrito;
}

void Persona::SetDistrito(char* distrito) {
    this->distrito = new char [strlen(distrito)+1];
            strcpy(this->distrito,distrito);
}

char* Persona::GetDistrito() const {
    char *salida = new char [strlen(this->distrito)];
    strcpy(salida,this->distrito);
    
    return salida;
}

void Persona::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Persona::GetCodigo() const {
    return codigo;
}

void Persona::SetNombre(char* nombre) {
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

char* Persona::GetNombre() const {
      char *salida = new char [strlen(this->nombre)+1];
    strcpy(salida,this->nombre);
    
    return salida;
}

void Persona::leer(ifstream &in){
    char buff[200]; int codigo;
        in.getline(buff,200,','); //Nombre
        SetNombre(buff);
        in>>codigo; in.get();
        SetCodigo(codigo); //Codigo;
        in.getline(buff,200,',');
        SetDistrito(buff); //distrito;
}


