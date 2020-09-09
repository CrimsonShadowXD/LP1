/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.cpp
 * Author: cueva
 * 
 * Created on 25 de junio de 2020, 11:41 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Conductor.h"
#include "Faltas.h"
#include "sobrecarga.h"

using namespace std;


ifstream &operator >> (ifstream &arch, Faltas &f){
    int dni,codigo;
    float monto;
    
    arch >> dni;
    if(arch.eof()) return arch; 
    arch.get();
    arch >> codigo;
    arch.get();
    arch >> monto;
    arch.get();
    
    f.SetCodigo(codigo);
    f.SetDni(dni);
    f.SetMulta(monto);
    
    return arch;
}

ifstream &operator >> (ifstream &arch, Conductor &c){
    int dni, brevete;
    char cad[200],*nom;
    
    arch >> dni;
    if(!arch.eof()){
        arch.get();
        arch.getline(cad,200,';');
        arch >> brevete;
        
        c.SetDni(dni);
        c.SetBrevete(brevete);
        c.SetNombre(cad);
        
    }
    return arch;
}

ofstream &operator << (ofstream &arch, Conductor &c){
    char cad[200];
    
    c.GetNombre(cad);
    
    arch<<left <<setw(20) <<c.GetDni() << setw(50) << cad << setw(20)  
            << c.GetBrevete() <<endl;
    
    arch <<"Tiene " << c.GetCantfaltas() <<" multas. Por un monto de:" << setw(10) << c++  << endl ;
    arch << endl;
    
}
