/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matricula.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 10:36 PM
 */

#include "Matricula.h"
#include <fstream>
#include <cstring>
#include "Alumno.h"
#include "CursoNota.h"
#include "ListaCursos.h"
#include "Curso.h"

using namespace std;


Matricula::Matricula() {
}


Matricula::~Matricula() {
}

void Matricula::leer(){
        ifstream in("Alumnos.csv",ios::in); ifstream notas("Notas.csv",ios::in); ifstream cursos("Cursos.csv",ios::in);
    
    
    ListaAlumnos prueba;
    ListaCursos pruebaCursos;
    
    alumnos.leerAlumnos(in); 
    alumnos.leerNotas(notas);
    this->cursos.leer(cursos); 


}
void Matricula::imprimir(){
    ofstream out("ReporteInstitucion.txt",ios::out);
        cursos.imprimir(out); 
        alumnos.imprimir(out);
    
}

void Matricula::matricular(){
    ofstream out("ReporteMatricula.txt",ios::out);
    ifstream in("IntencionDeMatricula.csv",ios::in);
    
    out<<"Reporte de Matricula "<<endl<<endl;
    
    NodoAlumno* a;  CursoNota *c;
    Curso *f;
    
    char buff[100]; int codigo; bool matriculado;
    while(1){
    in>>codigo; if (in.eof()) break;
    in.get();
    alumnos.imprimirAlumno(out,codigo);
    out<<endl;
    out<<"CURSOS EN LOS QUE QUIERE MATRICULARSE: "<<endl;
    out<<"Codigo     Nombre                                       Creditos  Observacion"<<endl;
                while(1){ 
                    char curso[7]; char **req;
                 in.get(curso,7);
                 if(in.peek()=='\n') {in.get(); break;} in.get();
                 req=cursos.buscarCursoYReq(out,curso);
                 
                  matriculado=alumnos.verificarAprobado(codigo,req);    
                 if (matriculado==true) out<<"Inscrito"<<endl;
                 else out<<"No procede por no cumplir requisitos"<<endl;    
                 }
    out<<endl<<endl;
    
    }
    
    
}
    
    void Matricula::procesar(){
        leer();
        imprimir();
        matricular();
    }
