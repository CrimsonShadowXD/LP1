
/* 
 * File:   Bib_Func_Preg1.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 17:43
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#include "Bib_Func_Preg1.h"

using namespace std;

void imprimeLinea(ofstream &out,char car){
    for (int i = 0; i < 80; i++)      out<<car;
    out<<endl;
}

char* sacaPalabra(ifstream &in, char c){
    char *salida, buff[200];
    in.getline(buff,200,c);
    salida = new char [strlen(buff)+1];
    strcpy(salida,buff);
    return salida;
}


void leerCursos(int *&codCur,char **&cursos,int **&requisitos){
    ifstream in("cursos.csv",ios::in); if(!in) {cout<<"Error abriendo el archivo de cursos. "<<endl;exit(1);}
    int n=0,buffCod[50],*buffReq[100];
    char *buffCursos[50]; //Nombres.
    
    while(1){
        in>>buffCod[n]; if (in.eof()) break;
        in.get();
        buffCursos[n]=sacaPalabra(in,',');
        buffReq[n]=leeRequisitos(in);
        n++;
    }
    codCur=new int [n+1];
    cursos=new char*[n+1];
    requisitos=new int*[n+1];
    for(int i=0;i<n;i++){
        codCur[i]=buffCod[i];
        cursos[i]=buffCursos[i];
        requisitos[i]=buffReq[i];
    }
      codCur[n]=-1;
      cursos[n]=nullptr;
      requisitos[n]=nullptr;
      
      return;    
}

int* leeRequisitos(ifstream &in){
    int *salida; int n=0; int buff[15];
    if (in.peek()=='\n' || in.eof() ) return nullptr;
    while(1){
        in>>buff[n];
        n++;
        if (in.get()=='\n') break;
    }
    salida = new int[n];
    for(int i=0;i<n;i++)
        salida[i]=buff[i];
    salida[n]=-1;
    return salida;    
}
    void imprimirCursos(int *codCur,char **cursos,int **requisitos){
        ofstream out("ReporteCursos.txt",ios::out); if (!out) {cout<<"Error creando ReporteCursos. "<<endl;exit(1);}

        out<<"REPORTE DE CURSOS"<<endl;
        imprimeLinea(out,'=');
        out<<"N.- Codigo     Nombre                                                Requisitos"<<endl;
        imprimeLinea(out,'-');
        for(int i=0;cursos[i];i++){
            out<<setw(2)<<right<<i+1<<')'<<left<<setw(8)<<codCur[i]<<setw(65)<<left<<cursos[i]<<"   ";
            for(int j=0; requisitos[i][j]!=-1; j++) out<<requisitos[i][j]<<' ';
            out<<endl;
        }
    }
