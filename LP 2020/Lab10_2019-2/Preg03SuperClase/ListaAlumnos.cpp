
/* 
 * File:   ListaAlumnos.cpp
 * Author: Rodrigo Agama
 * 
 * Created on 6 de julio de 2020, 19:26
 */

#include "ListaAlumnos.h"
#include "NodoAlumno.h"
#include "Nota.h"
#include "Alumno.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaAlumnos::ListaAlumnos() {
    lista=nullptr;
}


ListaAlumnos::~ListaAlumnos() {
    NodoAlumno *p, *sale;
    p=lista;
    while (p){
        sale=p;
        p=p->sig;
        delete sale;
    }
}

void ListaAlumnos::agregarAlumno(NodoAlumno *&nuevo){
    NodoAlumno *p=lista, *ant=nullptr;    
    
    while(p){
    
    if (nuevo->elem.getCodigo() < p->elem.getCodigo() ) //Se actualiza el curso 
        break;
    
    ant=p;
    p=p->sig;
}
      nuevo->sig=p;    //IMPORTANTE: ISOLAR
      
if (ant==nullptr)   lista=nuevo;
else     ant->sig=nuevo;       
}

 void ListaAlumnos::leerLista(ifstream &in){
     
     while(1){
         NodoAlumno *entrada = new NodoAlumno;
         entrada->elem.leer(in);
         if (in.eof()) break;     
         this->agregarAlumno(entrada);
             
     }
     
 }
 
 
 void ListaAlumnos::leerNotas(ifstream &in){
     int codigo; char buff[500]; int nota; NodoAlumno *p;
     while(1){
         Nota nuevo;
         in>>codigo; if (in.eof()) break; 
         in.get();
         in.getline(buff,500,',');
         nuevo.SetCodigo(buff);
         in>>nota; in.get();
         nuevo.SetNota(nota);
         in.getline(buff,500);
         nuevo.SetSemestre(buff); //Insertamos ahora.
         p=lista;
         while(p){
             if ( p->elem.getCodigo() == codigo){
                 p->elem.agregarNota(nuevo); 
                 break;}
             p=p->sig;
         }
         
     }
        
    }
 void ListaAlumnos::imprimirLista(ofstream &out){
     NodoAlumno *p;
     p=lista;
     
     while(p){
         p->elem.imprimir(out);
         p=p->sig;
     }
     
 }
       

