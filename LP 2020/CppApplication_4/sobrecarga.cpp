/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sobrecarga.h"

ifstream &operator >> (ifstream &arch, Alumnos &clase){
    int codigo;
    char tipo, nombre[150], CambiarLinea[500];
    arch>>ws;
    arch>>tipo;
    arch>>codigo;
    arch>>nombre;
    arch.getline(CambiarLinea,500);
//    cout<<tipo<<' '<<codigo<<' '<<nombre<<endl;
    clase.SetCodigo(codigo);
    clase.SetNombre(nombre);
    clase.SetTipo(tipo);
    return arch;
}

ifstream &operator >> (ifstream &arch, ACurso &clase){
    int codigo,cicloA,cicloP,nota;
    char separador,operacion, ccurso[10];
    float credito;
    
    arch>>codigo;
    arch>>ccurso;
    arch>>nota;
    arch>>cicloA>>separador>>cicloP;
    arch>>ws;
    arch>>credito;
    arch>>ws;
    arch>>operacion;
//    cout<<codigo<<' '<<ccurso<<' '<<nota<<' '<<cicloA<<'-'<<cicloP<<' '<<credito<<' '<<operacion<<endl;
    clase.SetCodigo(codigo);
    clase.SetOperacion(operacion);
    clase.AsignarDatosCurso(ccurso,cicloA*10+cicloP,nota,credito);
    return arch;
}

ofstream &operator << (ofstream &arch, Alumnos &clase){
    char cadNom[150];
    int numcur;
    clase.GetNombre(cadNom);
    arch<<left<<setw(10)<<"Nombre:"<<cadNom;
    arch<<left<<setw(10)<<"Codigo:"<<clase.GetCodigo();
    for(int i=0;i<150;i++){
        arch<<'=';
    }
    arch<<endl;
    arch<<setw(10)<<' '<<setw(15)<<"CICLO"<<setw(15)<<"PROMEDIO"<<endl;

    
    int cicloIni=20000,nperiodo=1;
    float Prom=0;
    while(cicloIni!=20201){
        Prom=clase/cicloIni;
        if(Prom){
            arch<<right<<setw(6)<<nperiodo<<')'<<setw(6)<<cicloIni/10<<'-'<<cicloIni%10;
            arch<<setw(20)<<Prom<<endl;
        }
        cicloIni++;
        if(cicloIni%10>2){
            cicloIni=cicloIni-2+10;
        }

    }
    arch<<setw(20)<<"Creditos Cursados:"<<clase--<<endl;
    arch<<setw(20)<<"Creditos Aprobados:"<<clase++<<endl;
    return arch;
}
