
/* 
 * File:   main.cpp
* Author: Rodrigo Agama    Codigo: 20151460  
 *
 * Created on 3 de julio de 2020, 08:05
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Alumno.h"
#include "Persona.h"
#include "Profesor.h"
#include "Miembro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Alumno pruebaA;
    Profesor pruebaP;
    Miembro mi;
    
    ifstream in("Miembros.csv",ios::in);
    if (!in){
        cout<<"Error abriendo miembros.csv."; exit(1);}
    
    pruebaA.SetCodigo(20151460);
    pruebaA.SetNombre("Rodrigo Agama");
    pruebaA.SetDistrito("Los Olivos");
    pruebaA.SetEscala(3);
    pruebaA.SetEspecialidad("Ingenieria Informatica");
    pruebaA.SetFacultad("FACI");
    
    ofstream out("PruebaSimple.txt",ios::out);
    if (!out) {cout<<"Error creando la prueba simple."<<endl;exit(1);}
    
    out<<pruebaA.GetCodigo()<<endl;
    out<<pruebaA.GetNombre()<<endl;
    out<<pruebaA.GetDistrito()<<endl;
    out<<pruebaA.GetEscala()<<endl;
    out<<pruebaA.GetEspecialidad()<<endl;
    out<<pruebaA.GetFacultad()<<endl;
        
    mi.leerMiembro(in);
    mi.leerMiembro(in);
    mi.imprimir("PruebaAlumno.txt","PruebaProfesor.txt");
    
    
    

    return 0;
}

