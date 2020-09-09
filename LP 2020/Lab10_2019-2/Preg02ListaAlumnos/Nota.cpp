
/* 
 * File:   Nota.cpp
 * Author: Rodrigo Agama
 * 
 * Created on 5 de julio de 2020, 14:46
 */

#include "Nota.h"
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

Nota::Nota() {
    codigo=nullptr;
    semestre=nullptr;
}

Nota::~Nota() {
    if (codigo) delete[] codigo;
    if (semestre) delete[] semestre;
}

void Nota::SetSemestre(char* semestre) {
    
    this->semestre = new char [strlen(semestre)+1];
    strcpy(this->semestre,semestre);
}

char* Nota::GetSemestre() const {
    char *salida = new char [strlen(this->semestre)+1];
    strcpy(salida,this->semestre);
    return salida;
}

void Nota::SetNota(int nota) {
    this->nota = nota;
}

int Nota::GetNota() const {
    return nota;
}

void Nota::SetCodigo(char* codigo) {
     this->codigo = new char [strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

char* Nota::GetCodigo() const {
        char *salida = new char [strlen(this->codigo)+1];
    strcpy(salida,this->codigo);
    return salida;
}

  void Nota::imprimir(ofstream &out){
      out<<GetCodigo()<<right<<setw(6)<<GetNota()<<left<<"  "<<GetSemestre()<<endl;
  }
  
  

