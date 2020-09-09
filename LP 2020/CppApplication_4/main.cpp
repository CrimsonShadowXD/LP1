/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 2, 2020, 7:33 PM
 */

#include "sobrecarga.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ACurso prueba;
    Curso p1,p2;
    ifstream arch("Cursos.txt",ios::in);
    if(!arch){
        cerr<<"error"<<endl;
        exit(1);
    }
    arch>>prueba;
    char cod[10],cod2[10];
    prueba.ObtenerCurso(cod);
    cout<<prueba.GetCodigo()<<endl;
    cout<<cod<<endl;
    cout<<prueba.GetOperacion()<<endl;
    cout<<prueba.ObtenerCiclo()<<endl;
    cout<<prueba.ObtenerCredito()<<endl;
    cout<<prueba.ObtenerNota()<<endl;
    cout<<"-------------"<<endl;
    arch>>prueba;
    prueba.ObtenerCurso(cod);
    p1.SetCcurso(cod);
    p1.SetCiclo(prueba.ObtenerCiclo());
    p1.SetCredito(prueba.ObtenerCredito());
    p1.SetNota(prueba.ObtenerNota());
    p1.GetCcurso(cod2);
    cout<<cod2<<endl;
    cout<<p1.GetCiclo()<<endl;
    cout<<p1.GetCredito()<<endl;
    cout<<p1.GetNota()<<endl;
    cout<<"-------------"<<endl;  
    p2=p1;
    p2.GetCcurso(cod2);
    cout<<cod2<<endl;
    cout<<p2.GetCiclo()<<endl;
    cout<<p2.GetCredito()<<endl;
    cout<<p2.GetNota()<<endl;
    cout<<"-------------"<<endl;
    if(p1==p2){
        cout<<"v"<<endl;
    }
    else{
        cout<<"f"<<endl;
    }
    cout<<"-------------"<<endl;
    ifstream arch2("Alumnos.txt",ios::in);
    if(!arch2){
        cerr<<"error2"<<endl;
        exit(1);
    }
    Alumnos PruebaX;
    arch2>>PruebaX;
    arch2>>PruebaX;
    return 0;
}

