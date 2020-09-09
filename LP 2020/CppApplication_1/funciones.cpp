/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.h"

void leerAlumnos(Alumnos *&ArrAlumnos, int &cantAl){
    ifstream archAl("Alumnos.txt",ios::in);
    if(!archAl){
        cerr<<"error"<<endl;
        exit(1);
    }
    while(1){
        archAl>>ArrAlumnos[cantAl];
        if(archAl.eof())break;
        cantAl++;
    }
}

void leerCursos(Alumnos *&alumnos, int n){
    ifstream in("Cursos.txt",ios::in); 
    if(!in) {
        cout<<"Error abriendo el archivo de cursos. "<<endl;
        exit(1);
    }
    while(1){
        ACurso nuevo;
        in>>nuevo;
        if (in.eof()) break;
        for(int i=0; i<n ; i++) //Si el codigo de alumno coincide.
            if (alumnos[i].GetCodigo()==nuevo.GetCodigo()) 
                alumnos[i]+nuevo; //Añadimos el nuevo alumno.                 
    }
}

void corregirCursos(Alumnos *&alumnos, int n){
    ifstream in("Correcciones.txt",ios::in); 
    if(!in) {
        cout<<"Error abriendo el archivo de Correcciones. "<<endl;
        exit(1);
    }
    while(1){
        ACurso nuevo;
        in>>nuevo;
        if (in.eof()) break;
        for(int i=0;i<n;i++)
            if (alumnos[i].GetCodigo()==nuevo.GetCodigo()){
                if (nuevo.GetOperacion()=='N') alumnos[i]+nuevo;
                else if (nuevo.GetOperacion()=='A')alumnos[i]*nuevo;
                else if (nuevo.GetOperacion()=='E')alumnos[i]-nuevo;
        }                    
    }
    return;
}

void imprimirAlumnos(Alumnos *alumnos, int n){
    ofstream out("Reporte.txt",ios::out); 
    if (!out) {
        cout<<"Error creando reporte. "<<endl;
        exit(1);
    }
    for( int i=0; i<n; i++){
        out<<alumnos[i]<<endl;               
    }
}


void procesarArch(){
    Alumnos *ArrAlumnos=new Alumnos[100];
    int n=0;
    leerAlumnos(ArrAlumnos,n);
    leerCursos(ArrAlumnos,n);
    corregirCursos(ArrAlumnos,n);
    imprimirAlumnos(ArrAlumnos,n);     
}