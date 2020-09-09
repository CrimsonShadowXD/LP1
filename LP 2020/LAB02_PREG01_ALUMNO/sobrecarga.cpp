/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Curso.h"
#include "Acurso.h"
#include "Alumno.h"
#include "sobrecarga.h"

ifstream &operator >> (ifstream &arch, Alumno &alumno){
//    int codigo;
//    char tipo;
//    char *nombre;
//    class Curso lcurso[100];
//    int numcur;
    int cod;
    char tipo, buffNombre[200], buffCambio[200];
    arch>>ws;
    arch >> tipo;
    if(arch.eof()) return arch; 
    arch>>cod;
    arch.getline(buffNombre,200,';');
    arch.getline(buffCambio,200);
    alumno.SetTipo(tipo);
    alumno.SetCodigo(cod);
    alumno.SetNombre(buffNombre);
    
    return arch;
}

ifstream &operator >> (ifstream &arch, Acurso &a_curso){
    int cod, nota, ciclo, periodo, ciclo_mod;
    float cred;
    char nm[10],Tipo_op,*aux;
    Curso Aux_Cur;
    
    arch>>cod;
    arch>>nm;
        cout<<nm<<'Z';
    cout<<"error"<<endl;
    cout<<strlen(nm)<<endl;
    arch >> nota;
    arch>>ciclo;
    arch.get();
    arch>>periodo;
    arch>>cred;
    arch>>ws;
    arch>>Tipo_op;
    ciclo_mod=ciclo*10+periodo;
    a_curso.SetOperacion(Tipo_op);
    a_curso.SetCodigo(cod);
    cout<<cod<<' '<<nota<<' ';

    
    Aux_Cur.SetCodigo(nm);
    Aux_Cur.SetCredito(cred);
    Aux_Cur.SetNota(nota);
    Aux_Cur.SetCiclo(ciclo_mod);
    
    a_curso.SetClcurso(Aux_Cur);
    return arch;
}

ofstream &operator << (ofstream &arch, Alumno &alumno){
    char nom_Alum[200], cod_cur[10];
    
    alumno.GetNombre(nom_Alum);
//    
    arch<<left <<setw(9) <<"Nombre:"<<nom_Alum<<endl;
    arch<<setw(9) <<"Codigo:"<<alumno.GetCodigo()<<endl;
    for(int i=0;i<500;i++){
        arch<<'=';
    }
    arch<<endl;
    arch<<setw(9)<<' '<<setw(12)<<"CICLO"<<"PROMEDIO"<<endl;
    return arch;    
}