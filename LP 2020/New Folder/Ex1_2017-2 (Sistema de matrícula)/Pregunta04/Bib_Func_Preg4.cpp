
/* 
 * File:   Bib_Func_Preg4.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 18:52
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"
#include "Bib_Func_Preg3.h"
#include "Bib_Func_Preg4.h"

using namespace std;


void reporteDeMatricula(int *codCur,char **cursos,int **requisitos,int *codAlum,char **alumnos,int ***notas){
    ifstream in("matricula.csv",ios::in); if(!in) {cout<<"Error abriendo el archivo de matricula. "<<endl;exit(1);}
    ofstream out("ReporteDeMatricula.txt",ios::out); if (!out) {cout<<"Error creando reporte de matricula. "<<endl;exit(1);}

    int codigoAlumno,codigoCurso; int n; bool procede;    
    out<<"Reporte de Matricula"<<endl;
    while(1){
        imprimeLinea(out,'=');
        in>>codigoAlumno;   if (in.eof()) break;
        in.get();        
        for(n=0;codAlum[n]!=codigoAlumno;n++); //n=Posición del alumno.
        out<<"Codigo del Alumno: "<<codAlum[n]<<"   Nombre: "<<alumnos[n]<<endl;
        imprimeLinea(out,'-');
        out<<"CURSOS EN LOS QUE QUIERE MATRICULARSE:"<<endl;
        out<<"Codigo  Nombre                                                      Observacion "<<endl;
        while(1){
            in>>codigoCurso; int posCurso;
            out<<setw(10)<<left<<codigoCurso<<"   ";
            for(posCurso=0;codCur[posCurso]!=-1;posCurso++) if (codigoCurso==codCur[posCurso]) break;                    
            out<<setw(55)<<left<<cursos[posCurso];
            procede=verificar(requisitos[posCurso],notas[n]); //n es la posición del alumno, paso SUS notas. posCurso es ESE curso.
            if (procede) out<<"Procede"<<endl;
            else out<<"No procede por no cumplir requisitos"<<endl;            
            if (in.get()=='\n') break;
        }        
    }
    return;
}

bool verificar(int *requisitos, int **notas){  
    int j;
    for(int i=0;requisitos[i]!=-1;i++){
        for(j=0; notas[j];j++){
         if (requisitos[i]==notas[j][0])    //Codigo Requisito == Codigo del Curso Nota
         {if (notas[j][1]<10) return false;   break;}      
        }
        if (!notas[j]) return false; //Si no lo encontró.
    }  
    //Si ningún curso fue jalado
    return true;
}