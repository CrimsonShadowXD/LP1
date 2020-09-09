
/* 
 * File:   Alumno.cpp
 * Author: Rodrigo Agama    Codigo:20151460
 * 
 * Created on 3 de julio de 2020, 08:06
 */

#include "Alumno.h"
#include <fstream>
#include <cstring>

using namespace std;

Alumno::Alumno() {
    especialidad = nullptr;
    facultad= nullptr;
}

  Alumno::Alumno(const Alumno &orig){
    SetNombre(orig.GetNombre());
    SetCodigo(orig.GetCodigo());
    SetDistrito(orig.GetDistrito());
    SetEspecialidad(orig.GetEspecialidad());
    SetFacultad(orig.GetFacultad());
  }


Alumno::~Alumno() {
    if (especialidad) delete[] especialidad;
    if (facultad) delete[] facultad;
}

void Alumno::SetFacultad(char* facultad) {
    this->facultad = new char [strlen(facultad)+1];
    strcpy(this->facultad,facultad);
}

char* Alumno::GetFacultad() const {
    char *aux = new char [strlen(this->facultad)+1];
    strcpy(aux,this->facultad);
    return aux;
}

void Alumno::SetEspecialidad(char* especialidad) {
    this->especialidad = new char [strlen(especialidad)+1];
    strcpy(this->especialidad,especialidad);
}

char* Alumno::GetEspecialidad() const {
    char *aux = new char [strlen(this->especialidad)+1];
    strcpy(aux,this->especialidad);
    return aux;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::operator=(Alumno &orig){
    if (orig.GetCodigo()==-1) {
        this->SetCodigo(-1);
        return;
    }
    SetNombre(orig.GetNombre());
    SetCodigo(orig.GetCodigo());
    SetDistrito(orig.GetDistrito());
    SetEspecialidad(orig.GetEspecialidad());
    SetFacultad(orig.GetFacultad());    
}

void Alumno::leer(ifstream &in){
    int escala; char buff[200];
    this->Persona::leer(in); 
    in>>escala; in.get();
    this->SetEscala(escala);
    in.getline(buff,200,',');
    this->SetEspecialidad(buff);
    in.getline(buff,200);
    this->SetFacultad(buff);   
    
}

void Alumno::imprimir(ofstream &out){
    out<<"Codigo Alumno: "<<GetCodigo()<<endl;
    out<<"Nombre del Alumno: "<<GetNombre()<<endl;
    out<<"Distrito: "<<GetDistrito()<<endl;
    out<<"Escala de Pago: "<<GetEscala()<<endl;
    out<<"Especialidad: "<<GetEspecialidad()<<endl;
    out<<"Facultad: "<<GetFacultad()<<endl;
    out<<endl;
    
}

