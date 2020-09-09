/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */

#include "sobrecarga.h"
#include "Miembro.h"

ofstream &operator << (ofstream &arch, const Alumno &alum){
    char cad[50];
    
    alum.GetNombre(cad);
    arch << left << setw(10) << alum.GetCodigo() << setw(40) << cad << endl;
    arch << left << setw(20) << alum.GetEscala();
    alum.GetEspecialidad(cad);
    arch << left << setw(20) << cad;
    alum.GetFacultad(cad);
    arch << left << setw(20) << cad << endl << endl;
    return arch;
}

ofstream &operator << (ofstream &arch, const Profesor &prof){
    char cad[50];
    prof.GetNombre(cad);
    arch << left << setw(10) << prof.GetCodigo() << setw(40) << cad << endl;
    prof.GetCategoria(cad);
    arch << left << setw(20) << cad;
    prof.GetDedicacion(cad);
    arch << left << setw(20) << cad;
    prof.GetGrado(cad);
    arch << left << setw(20) << cad;
    prof.GetSeccion(cad);
    arch << left << setw(20) << cad << endl << endl;
    return arch;
    return arch;
}
//
ifstream &operator >> (ifstream &arch,Miembro &M){
    int n_alum,cap_alum,n_prof,cap_prof;
    char tipo;
//    ifstream arch("Miembros.csv",ios::in);    
//    if(!arch){        
//            cout << "No se puede abrir el archivo Miembros.csv";        
//            exit(1);    
//    }
    n_alum=0;
    cap_alum=0;
    n_prof=0;
    cap_prof=0;
    while(1){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        cout<<"TIPO"<<tipo<<endl;
        if(tipo=='A'){
            Alumno A;
            if(n_alum==cap_alum-1||M.VacioA())M.incrementarAlum(n_alum,cap_alum);
            cout<<n_alum<<' '<<cap_alum<<endl;
            arch>>A;
            M+A;
            n_alum++;
        }
        else if(tipo=='P'){
            Profesor P;
            if(n_prof==cap_prof-1||M.VacioP())M.incrementarProf(n_prof,cap_prof);
            cout<<n_prof<<' '<<cap_prof<<endl;
            arch>>P;
            M+P;
            n_prof++;
        }
    } 
    return arch;
}

ifstream &operator >> (ifstream &arch,Profesor &prof){
//    char *categoria;
//    char *dedicacion;
//    char *seccion;
//    char *grado;
    char cad[100];
    int codigo;
    arch.getline(cad,100,',');
    prof.SetNombre(cad);
    cout<<cad<<endl;
    arch>>codigo;
    prof.SetCodigo(codigo);
    arch.get();
    
    arch.getline(cad,100,',');
    prof.SetDistrito(cad);
    
    arch.getline(cad,100,',');
    prof.SetCategoria(cad);
    
    arch.getline(cad,100,',');
    prof.SetDedicacion(cad);
    
    arch.getline(cad,100,',');
    prof.SetSeccion(cad);
    
    arch.getline(cad,100);
    prof.SetGrado(cad);
    
    return arch;
}

ifstream &operator >> (ifstream &arch,Alumno &alum){
//    int escala;
//    char *especialidad;
//    char *facultad;
    char cad[100];
    int codigo,escala;
    
    arch.getline(cad,100,',');
    cout<<cad<<endl;
    
    alum.SetNombre(cad);
    arch>>codigo;
  
    alum.SetCodigo(codigo);
    arch.get();
    arch.getline(cad,100,',');
    alum.SetDistrito(cad);
    
    arch>>escala; 
    alum.SetEscala(escala);
    arch.get();
    
    arch.getline(cad,100,',');    
    alum.SetEspecialidad(cad);
    
    arch.getline(cad,100);    
    alum.SetFacultad(cad);
    
    return arch;
}
