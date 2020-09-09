
/* 
 * File:   Profesor.cpp
 * Author: Rodrigo Agama    Codigo:20151460
 * 
 * Created on 3 de julio de 2020, 08:06
 */

#include "Profesor.h"
#include <fstream>
#include <cstring>

using namespace std;

Profesor::Profesor() {
    categoria = nullptr;
    dedicacion = nullptr;
    seccion = nullptr;
    grado = nullptr;
    
}
Profesor::Profesor(const Profesor& orig){
    SetNombre(orig.GetNombre());
    SetCodigo(orig.GetCodigo());
    SetDistrito(orig.GetDistrito());
    SetCategoria(orig.GetCategoria());
    SetDedicacion(orig.GetDedicacion());
    SetSeccion(orig.GetSeccion());
    SetGrado(orig.GetGrado());
}

Profesor::~Profesor() {
    if (categoria) delete[] categoria;
    if (dedicacion) delete[] dedicacion;
    if (seccion) delete[] seccion;
    if (grado) delete[] grado;
}

void Profesor::SetGrado(char* grado) {
    this->grado = new char [strlen(grado)+1];
    strcpy(this->grado,grado); 
}

char* Profesor::GetGrado() const {
    char* salida = new char [strlen(this->grado)+1];
    strcpy(salida,this->grado);
    return salida;
}

void Profesor::SetSeccion(char* seccion) {
       this->seccion = new char [strlen(seccion)+1];
    strcpy(this->seccion,seccion);
 
}

char* Profesor::GetSeccion() const {
    char* salida = new char [strlen(this->seccion)+1];
    strcpy(salida,this->seccion);
    return salida;
}

void Profesor::SetDedicacion(char* dedicacion) {
       this->dedicacion = new char [strlen(dedicacion)+1];
    strcpy(this->dedicacion,dedicacion);
 
}

char* Profesor::GetDedicacion() const {
    char* salida = new char [strlen(this->dedicacion)+1];
    strcpy(salida,this->dedicacion);
    return salida;
}

void Profesor::SetCategoria(char* categoria) {
   this->categoria = new char [strlen(categoria)+1];
    strcpy(this->categoria,categoria);
 
}

char* Profesor::GetCategoria() const {
    char* salida = new char [strlen(this->categoria)+1];
    strcpy(salida,this->categoria);
    return salida;
}

void Profesor::operator=(Profesor &orig){
    if (orig.GetCodigo()==-1) {
        this->SetCodigo(-1);
        return;
    }
    SetNombre(orig.GetNombre());
    SetCodigo(orig.GetCodigo());
    SetDistrito(orig.GetDistrito());
    SetCategoria(orig.GetCategoria());
    SetDedicacion(orig.GetDedicacion());
    SetSeccion(orig.GetSeccion());
    SetGrado(orig.GetGrado());
    
}
void Profesor::leer(ifstream &in){
    char buff[200];
    this->Persona::leer(in);
    in.getline(buff,200,','); //Categoria
    this->SetCategoria(buff);
    in.getline(buff,200,','); //Dedicacion
    this->SetDedicacion(buff);
    in.getline(buff,200,',');//Seccion
    this->SetSeccion(buff);
    in.getline(buff,200); //Grado
    this->SetGrado(buff);
    
}

void Profesor::imprimir(ofstream &out){
    out<<"Codigo profesor: "<<GetCodigo()<<endl;
    out<<"Nombre del Alumno: "<<GetNombre()<<endl;
    out<<"Distrito: "<<GetDistrito()<<endl;
    out<<"Categoria: "<<GetCategoria()<<endl;
    out<<"Dedicacion: "<<GetDedicacion()<<endl;
    out<<"Seccion: "<<GetSeccion()<<endl;
    out<<"Grado Academico: "<<GetGrado()<<endl;
    out<<endl;
}

