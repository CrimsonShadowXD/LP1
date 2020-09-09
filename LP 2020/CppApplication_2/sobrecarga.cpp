/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "sobrecarga.h"

ofstream &operator << (ofstream &arch, const Nacional &c){
    char cad[50];
    
    c.GetNombre(cad);
    arch << left << setw(10) << c.GetCodigo() << setw(40) << cad << endl;
    c.GetEspecialidad(cad);
    arch << left << setw(20) << cad;
    c.GetFacultad(cad);
    arch << left << setw(20) << cad << endl << endl;
    return arch;
}

ofstream &operator << (ofstream &arch, const Intercambio &c){
    char cad[50];
    
    c.GetNombre(cad);
    arch << left << setw(10) << c.GetCodigo() << setw(40) << cad << endl;
    c.GetPais(cad);
    arch << left << setw(20) << cad << c.GetTiempo() << endl << endl;
    return arch;
}

//I;5258;Gavidia/Mendoza/Ronald-Johnny;Japon;Japones;2
ifstream &operator >> (ifstream &arch,Intercambio &c){
    int codigo,tiempo;
    char cad[100];
    
    arch >> codigo;
    c.SetCodigo(codigo);
    arch.get();
    arch.getline(cad,100,';');
    c.SetNombre(cad);
    arch.getline(cad,100,';');
    c.SetPais(cad);
    arch.getline(cad,100,';');
    c.SetIdioma(cad);
    arch >> tiempo;
    c.SetTiempo(tiempo);
    arch.get();
    return arch;
} 
//R;20160658;Arca/Amezquita/Edric-Ronald;Ingenieria Mecanica;FCI;
ifstream &operator >> (ifstream &arch,Nacional &c){
    int codigo;
    char cad[100];
    
    arch >> codigo;
    c.SetCodigo(codigo);
    arch.get();
    arch.getline(cad,100,';');
    cout<<cad<<endl;
    c.SetNombre(cad);
    arch.getline(cad,100,';');
    c.SetEspecialidad(cad);
    arch.getline(cad,100,';');
    c.SetFacultad(cad);
    return arch;
} 

