
/* 
 * File:   main.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 08:01
 */

#include "ACurso.h"
#include "Curso.h"
#include "Alumno.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Cursos.txt",ios::in); if(!in) {cout<<"Error abriendo el archivo cursos. "<<endl;exit(1);}
  
    ACurso prueba;
    in>>prueba;
    
    cout<<"Codigo de Alumno: "<<prueba.GetCodigo()<<endl;
    cout<<"Codigo de Curso: "<<prueba.GetCurso().GetCcurso()<<endl;
    cout<<"Ciclo: "<<(prueba.GetCurso().GetCiclo())/10<<'-'<<prueba.GetCurso().GetCiclo()%10<<endl;
    cout<<prueba.GetOperacion()<<endl;
    return 0;
}

