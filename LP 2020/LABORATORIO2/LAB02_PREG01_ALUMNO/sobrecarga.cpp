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
//    alumno.SetNombre(buffNombre);
    
    return arch;
}

ifstream &operator >> (ifstream &in, Acurso &nuevo){
//    int codigo;
//    class Curso clcurso;
//    char operacion;
    Curso nuevoCurso;
    
    int codigoA;    char codigoC[50];    int nota;    int aaC,nC,ciclo;
    float creditos; char op;
    in>>codigoA>>codigoC>>nota;
    in>>aaC; in.get(); in>>nC;
    in>>creditos;
    in>>ws; in>>op; 
    
    cout<<strlen(codigoC)<<endl;
    
    cout<<typeid(codigoC).name()<<endl;
    if (in.peek()=='\n') in.get();
    
    nuevoCurso.SetCodigo(codigoC);
    nuevoCurso.SetCiclo(aaC*10+nC);
    nuevoCurso.SetCredito(creditos);
    nuevoCurso.SetNota(nota);
    
    nuevo.SetClcurso(nuevoCurso);
    nuevo.SetCodigo(codigoA);
    nuevo.SetOperacion(op);
    return in;
}

ofstream &operator << (ofstream &arch, Alumno &alumno){
    char nom_Alum[200], cod_cur[10];
    
//    alumno.GetNombre(nom_Alum);
//    
    arch<<left <<setw(9) <<"Nombre:"<<nom_Alum<<endl;
    arch<<setw(9) <<"Codigo:"<<alumno.GetCodigo()<<endl;
    for(int i=0;i<500;i++){
        arch<<'=';
    }
    arch<<endl;
    arch<<setw(9)<<' '<<setw(12)<<"CICLO"<<"PROMEDIO"<<endl;
        
}