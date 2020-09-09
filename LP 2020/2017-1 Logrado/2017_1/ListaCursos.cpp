/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCursos.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 10:36 PM
 */

#include "ListaCursos.h"
#include "NodoAlumno.h"
#include "Curso.h"
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

ListaCursos::ListaCursos() {
    lista = NULL;
}

ListaCursos::~ListaCursos() {
}    
    
    char** ListaCursos::buscarCursoYReq(ofstream &out, char *codigo){
        char **salida;
            NodoCurso *p;
           p=lista;
           
           while(p){
               if(strcmp(p->elem.getCodigo(),codigo)==0) break;
               p=p->sig;
           }
           if (p){
               out<<p->elem.getCodigo()<<"   "<<p->elem.getNombre()<<setw(50-strlen(p->elem.getNombre()))<<' '<<p->elem.getCreditos();              
               out<<"     ";
               salida=this->requisitosDeCurso(codigo);
               
           }
                  
           return salida;
    }
    
        NodoCurso* ListaCursos::buscarCurso(char *codigo){
            NodoCurso *p;
           p=lista;
           
           while(p){
               if(strcmp(p->elem.getCodigo(),codigo)==0) return p;
               p=p->sig;
           }
       
           return NULL;
    }
    
     char** ListaCursos::requisitosDeCurso(char* curso){
         NodoCurso *p;
        p=this->buscarCurso(curso);
        char **salida=p->elem.getRequisitos();
        return salida;
     }
     
    void ListaCursos::leer(ifstream &in){
        NodoCurso *p;
        while(1){
            p = new NodoCurso;
            p->elem.leer(in);
            if (in.eof()) break;
            this->insertar(p);
        }
        
    }
    
    void ListaCursos::imprimir(ofstream& out){
               NodoCurso *p;
               p=lista;
               out<<"              Cursos de la Institucion"<<endl;
               for(int i=0;i<100;i++) out<<"-";out<<endl;
               out<<"Codigo             Nombre                                                 Creditos Requisitos"<<endl;
               for(int i=0;i<100;i++) out<<"=";out<<endl;
               
        while(p){            
            p->elem.imprimir(out);            
            p=p->sig;
        }
               
          for(int i=0;i<100;i++) out<<"-";out<<endl<<endl;
    }
    
       void ListaCursos::insertar(NodoCurso *nuevo){
           NodoCurso *p,*ant=NULL;
           p=lista;
           
           while(p){
               ant=p;
               p=p->sig;
           }
           if(ant==NULL) lista=nuevo;
           else (ant->sig=nuevo);
           
       }

