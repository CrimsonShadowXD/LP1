
/* 
 * File:   Bib_Func_Preg2.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 1 de junio de 2020, 18:09
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"

using namespace std;

    void incrementar(int *&codAlum, char **&alumnos, int &n, int &cap){
        int *auxCod;
        char **auxAlum;
        cap+=5;
        if (n==0){ //OTRA OPCION SI NO HAY INICIALIZACION es (n==0)
            codAlum=new int[cap];
            alumnos= new char*[cap];
            codAlum[0]=-1;
            alumnos[0]=nullptr;
            n++;
        }
        else {
        auxCod=new int[cap];
        auxAlum= new char*[cap];
            
        for(int i=0;i<n;i++) {
        auxCod[i]=codAlum[i]; 
        auxAlum[i]=alumnos[i];
        }
        delete codAlum;
        delete alumnos;
        codAlum=auxCod;
        alumnos=auxAlum;
        }
        return;        
    }

void leerAlumnos(int *&codAlum,char **&alumnos){
    ifstream in("alumnos.csv",ios::in); if(!in) {cout<<"Error abriendo el archivo de alumnos. "<<endl;exit(1);}

    int n=0,cap=0,codigo;
    char *nombre;
    while(1){
        in>>codigo;  if (in.eof()) break;
        in.get();
        nombre=sacaPalabra(in,'\n');
        if (n==cap) incrementar(codAlum,alumnos,n,cap);        
        codAlum[n-1]=codigo;
        alumnos[n-1]=nombre;
        codAlum[n]=-1;
        alumnos[n]=nullptr; 
        n++;
    }
    return;    
}
void imprimirAlumnos(int *codAlum,char **&alumnos){
    ofstream out("ReporteAlumnos.txt",ios::out); if (!out) {cout<<"Error creando ReporteAlumnos. "<<endl;exit(1);}
    
    out<<"Reporte de Alumnos: "<<endl;
    imprimeLinea(out,'-');
    out<<"Codigo         Nombre "<<endl;
    imprimeLinea(out,'=');
    for(int i=0;alumnos[i];i++){
        out<<setw(15)<<left<<codAlum[i]<<left<<alumnos[i]<<endl;
    }
       
    return;
    
}

