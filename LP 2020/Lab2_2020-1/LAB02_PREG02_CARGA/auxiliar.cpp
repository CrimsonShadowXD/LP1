
/* 
 * File:   auxiliar.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 09:35
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ACurso.h"
#include "Curso.h"
#include "Alumno.h"

using namespace std;

    void leerAlumnos(Alumno *&alumnos, int &n){
        ifstream in("Alumnos.txt",ios::in); if(!in) {cout<<"Error abriendo el archivo de alumnos. "<<endl;exit(1);}
        
        while(1){
            in>>alumnos[n];
            if (in.eof()) break;
            n++;
        }
    }
    void leerCursos(Alumno *&alumnos){
         ifstream in("Cursos.txt",ios::in); if(!in) {cout<<"Error abriendo el archivo de cursos. "<<endl;exit(1);}
                while(1){
                    ACurso nuevo;
                    in>>nuevo;
                    if (in.eof()) break;
                    for(int i=0; i<30 ; i++) //Si el codigo de alumno coincide.
                        if (alumnos[i].GetCodigo()==nuevo.GetCodigo()) alumnos[i]+nuevo; //Añadimos el nuevo alumno.                 
    }
        
    }
    void corregirCursos(Alumno *&alumnos){
              ifstream in("Correcciones.txt",ios::in); if(!in) {cout<<"Error abriendo el archivo de Correcciones. "<<endl;exit(1);}
                while(1){
                    ACurso nuevo;
                    in>>nuevo;
                    if (in.eof()) break;
                    for(int i=0;i<30;i++)
                        if (alumnos[i].GetCodigo()==nuevo.GetCodigo()){
                             if (nuevo.GetOperacion()=='N') alumnos[i]+nuevo;
                             else if (nuevo.GetOperacion()=='A')alumnos[i]*nuevo;
                             else if (nuevo.GetOperacion()=='E')alumnos[i]-nuevo;
                        }                    
    }
              
              return;
    }
    
       void imprimirAlumnos(Alumno *alumnos, int n){
           ofstream out("Reporte.txt",ios::out); if (!out) {cout<<"Error creando reporte. "<<endl;exit(1);}
           for( int i=0; i<n; i++){
               out<<alumnos[i]<<endl;               
           }
         }
