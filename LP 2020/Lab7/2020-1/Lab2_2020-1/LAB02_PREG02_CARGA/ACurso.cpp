
/* 
 * File:   ACurso.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 26 de junio de 2020, 08:03
 */
#include <cstring>
#include "Curso.h"
#include "ACurso.h"
#include <iomanip>

ACurso::ACurso() {
    this->operacion='N';
}

ACurso::ACurso(const ACurso& orig) {
}

ACurso::~ACurso() {
}

void ACurso::SetOperacion(char operacion) {
    this->operacion = operacion;
}

char ACurso::GetOperacion() const {
    return operacion;
}

void ACurso::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int ACurso::GetCodigo() const {
    return codigo;
}

Curso ACurso::GetCurso(){
    Curso salida(this->clcurso);
    return salida;    
}
void ACurso::SetCurso(Curso &entrada){
    this->clcurso=entrada;
}

ifstream& operator>>(ifstream &in, ACurso& nuevo){
    Curso nuevoCurso;
    
    int codigoA;    char codigoC[50];    int nota;    int aaC,nC,ciclo;
    float creditos; char op;
    in>>codigoA>>codigoC>>nota;
    in>>aaC; in.get(); in>>nC;
    in>>creditos;
    in>>ws; in>>op; 
    if (in.peek()=='\n') in.get();
    
    nuevoCurso.SetCcurso(codigoC);
    nuevoCurso.SetCiclo(aaC*10+nC);
    nuevoCurso.SetCredito(creditos);
    nuevoCurso.SetNota(nota);
    
    nuevo.SetCurso(nuevoCurso);
    nuevo.SetCodigo(codigoA);
    nuevo.SetOperacion(op);
    return in;
}