/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: crimson
 *
 * Created on July 17, 2020, 12:30 PM
 */

#include "PlArbol.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Aula.h"
#include <map>
#include <iterator>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream in("Miembros.csv",ios::in);
    if(!in){
        exit(1);
    }
    ofstream out("reporte.txt",ios::out);
    if(!out){
        exit(1);
    }
//    PlArbol <int> p;
    PlArbol <Alumno> a;
    PlArbol <Profesor> p;
    char t;
    while(1){
        in>>t;
        if(in.eof())break;
        in.get();
        if(t=='A')a.crear(in);
        else p.crear(in);
    }
    a.imprimir(out);
    out<<endl;
    p.imprimir(out);
    out<<endl;
    Alumno auxA;
    Profesor auxP;
    auxA.SetCodigo(49619);
    auxA=a.buscar(auxA);
    if(auxA.GetCodigo()!=-1)out<<auxA<<endl;
    out<<endl;
    auxA.SetEscala(-100000);
    a.modificar(auxA);
    a.imprimir(out);
    
    
    
    ifstream in2("Aulas.csv",ios::in);
    if(!in2){
        exit(1);
    }
    ofstream out2("aulas.txt",ios::out);
    if(!out2){
        exit(1);
    }
    Aula auxAula;
    map <int,Aula> mAula;
    char cad[15];
    int n=0;
    while(1){
        n++;
        if(in2.eof())break;
        in2>>auxAula;
        auxAula.GetClave(cad);
        auxAula.SetNumero(n);
        mAula[n]=auxAula;
    }
    map<int,Aula>::iterator it;
    for(it=mAula.begin();it!=mAula.end();it++){
        out2<<it->first<<endl;
        out2<<it->second<<endl;
        
    }
    return 0;
}

