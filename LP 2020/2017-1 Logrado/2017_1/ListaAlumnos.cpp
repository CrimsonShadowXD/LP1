
/* 
 * File:   ListaAlumnos.cpp
 * Author: Rodrigo
 * 
 * Created on 8 de diciembre de 2019, 10:36 PM
 */

#include "ListaAlumnos.h"
#include "Alumno.h"
#include "NodoAlumno.h"
#include "Regular.h"
#include "Intercambio.h"
#include <fstream>
#include <iterator>
#include <list>
#include <cstring>
#include <iostream>
#include "CursoNota.h"
#include "Curso.h"

using namespace std;

ListaAlumnos::ListaAlumnos() {
    lista = NULL;
}

ListaAlumnos::~ListaAlumnos() {
}

    
    NodoAlumno* ListaAlumnos::buscarAlumno(int prueba){
        NodoAlumno* p;
        p=lista;
        
        while(p){
            if (p->elem->getCodigo()==prueba) return p;
            p=p->sig;
        }
        return NULL;
    }
    
    void ListaAlumnos::insertar(NodoAlumno *nuevo){
        NodoAlumno *p,*ant=NULL;
        
        p=lista;
        while(p){            
            ant=p;
            p=p->sig;
        }
                
        if(ant==NULL) lista=nuevo;
        else {
            ant->sig=nuevo;
        }
   
    }
    
    void ListaAlumnos::leerAlumnos(ifstream &in){
        char c; NodoAlumno *p; Alumno *a;
        while(1){
            p = new NodoAlumno;
            c=in.get(); 
            if (in.eof()) break; 
            in.get();
            if (c=='R') a = new Regular;
            else if (c=='I') a = new Intercambio;
            a->leer(in); 
            p->elem=a;
            insertar(p);
        }     
       
        
    }
    
     void ListaAlumnos::leerNotas(ifstream &in){
         NodoAlumno *p;
                 CursoNota *nota;
                 p=lista;
        while(1){
            int codigo;
            in>>codigo; if (in.eof()) break;
            in.get();
            nota = new CursoNota;
            nota->leer(in);
            p=this->buscarAlumno(codigo);
            if(p)p->notas.push_back(*nota);
        }
               
     }
     
    void ListaAlumnos::imprimir(ofstream &out){
        NodoAlumno *p;
        out<<"               Alumnos de la Institucion: "<<endl;
          for(int i=0;i<100;i++) out<<"-";out<<endl;
        
        p=lista;
        while(p){
            p->elem->imprimir(out);
            for(list<CursoNota>::iterator it=p->notas.begin(); it!=p->notas.end();it++) out<<*it;         out<<endl;       
            p=p->sig;
        }
     
    }

    void ListaAlumnos::imprimirAlumno(ofstream &out, int codigo){
        NodoAlumno *p;
        p=this->buscarAlumno(codigo);
        p->elem->imprimir(out);
        
    }
    
       bool ListaAlumnos::verificarAprobado(int codigoAlumno,char **&requisitos){
  
           NodoAlumno *p;
           p = this->buscarAlumno(codigoAlumno);   
           

                 for(int j=0; requisitos[j]!=NULL ; j++){ 
                   for(list<CursoNota>::iterator it=p->notas.begin();     it != p->notas.end();             it++){
                       char *aux;
                       aux=it->getCodigo(); 
                       if ((strcmp(requisitos[j],aux)==0) & (it->getNota()<11)) return false;
               }
           }
           return true;
           
       }
       
