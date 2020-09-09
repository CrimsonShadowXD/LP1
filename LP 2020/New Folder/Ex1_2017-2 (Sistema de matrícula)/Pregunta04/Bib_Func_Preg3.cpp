
/* 
 * File:   Bib_Func_Preg3.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 18:31
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"
#include "Bib_Func_Preg3.h"

using namespace std;

void leeNotas(int *&codAlum,int ***&notas){
    ifstream in("notas.csv",ios::in); if(!in) {cout<<"Error abriendo el archivo de notas. "<<endl;exit(1);}
    int n, nNotas[50]={0}, capNotas[50]={0},pos;
    for(n=0;codAlum[n]!=-1;n++);
    notas = new int**[n+1];
    int codigo, curso, nota; bool encontrado;
    while(1){
        encontrado=false;
        in>>codigo; if (in.eof() ) break;
        in.get();
        in>>curso;
        in.get();
        in>>nota; if (in.peek()=='\n') in.get();
        for(pos=0; codAlum[pos]!=-1;pos++) if (codAlum[pos]==codigo) {encontrado=true; break;}
        if (encontrado){
            if (nNotas[pos]==capNotas[pos]) incrementar<int*>(notas[pos],nNotas[pos],capNotas[pos]);
            notas[pos][nNotas[pos]-1]=new int[2];
            notas[pos][nNotas[pos]-1][0]=curso;
            notas[pos][nNotas[pos]-1][1]=nota;
            notas[pos][nNotas[pos]]=nullptr;
            nNotas[pos]++;            
        }
    }
    

    return;
}
void imprimirNotas(int *codAlum,char **alumnos,int ***notas){
    ofstream out("ReporteNotas.txt",ios::out); if (!out) {cout<<"Error creando ReporteNotas. "<<endl;exit(1);}
    out<<"Reporte de Notas"<<endl;
    imprimeLinea(out,'=');
    for(int n=0; alumnos[n];n++){
     out<<setw(15)<<left<<codAlum[n]<<left<<alumnos[n]<<endl;
     out<<"Cod.Curso  Nota"<<endl;
     imprimeLinea(out,'-');
     if (notas[n]){
         for(int i=0; notas[n][i];i++) out<<left<<setw(10)<<notas[n][i][0]<<"  "<<notas[n][i][1]<<endl;
     }
     imprimeLinea(out,'-');
    }
    return;
}