/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 08:01 AM
 */

#include "sobrecarga.h"
#include "Curso.h"
#include "Acurso.h"
#include "Alumno.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Cursos.txt",ios::in); 
    if(!in) {
        cout<<"Error abriendo el archivo cursos. "<<endl;
        exit(1);
    }
  
    Acurso prueba;
    in>>prueba;
//    
//    cout<<"Codigo de Alumno: "<<prueba.GetCodigo()<<endl;
//    cout<<"Codigo de Curso: "<<prueba.GetCurso().GetCcurso()<<endl;
//    cout<<"Ciclo: "<<(prueba.GetCurso().GetCiclo())/10<<'-'<<prueba.GetCurso().GetCiclo()%10<<endl;
//    cout<<prueba.GetOperacion()<<endl;

    return 0;
}

