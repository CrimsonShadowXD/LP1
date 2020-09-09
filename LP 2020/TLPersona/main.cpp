/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 14 de julio de 2020, 10:08 AM
 */
#include <fstream>
#include <cstdlib>
#include "PlLista.h"
#include "Alumno.h"
#include "Profesor.h"


using namespace std;

/*
 *  Es que creen su super clase, aqui coloquen sus Listas colas pilas
 *  y además esta super clase que maneje STL
 *  Banco del lab 1 tiene 2 colas (1 cola para vip 1 cola normales)
 *  por cada 3 de la copa vip pasa uno de la cola normal 
 *  y los que se van atendiendo se almacenan en la STL
 *  En el STL se deben cargar cajeros de 1.. 100
 *  Cada cajero tiene un numero, tipo o clase (vip o normal),
 *  caja01: normal 1 vip ... caja04: vip  desencola un vip
 *  caja05: normal 1 normal.  
 *  el nombre y dni de la persona que atendio.  
 *  lo pasen al STL de su agrado
 */
int main(int argc, char** argv) {
    class PlLista<Alumno>   lAlumno;
    class PlLista<Profesor> lProfesor;

    
    ifstream archp("persona.csv",ios::in);
    if(!archp)
    {   cout << "Archivo no encontrado" << endl;         
        exit(1);
    }
    Alumno ca;
    Profesor cp;
    char tipo;
    
    while(1){
        archp >> tipo;
        if(archp.eof()) break;
        archp.get();
        if(tipo=='A'){
            archp >> ca;
            lAlumno.inserta(ca);
        }
        else{
            archp >> cp;
            lProfesor.inserta(cp);
        }
    
    ofstream archa("alumnos.txt",ios::out);
    if(!archa)
    {   cout << "Archivo no encontrado" << endl;         
        exit(1);
    }    
    lAlumno.mostrar(archa);
   
    ofstream archd("docentes.txt",ios::out);
    if(!archd)
    {   cout << "Archivo no encontrado" << endl;         
        exit(1);
    }    
    lProfesor.mostrar(archd);
    
    }
 
    return 0;
}

