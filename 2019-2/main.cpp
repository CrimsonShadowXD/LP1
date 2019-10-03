/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 3 de octubre de 2019, 11:37 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
 * 
 */

char *leerCadena(char delim){
    char Buff[200],*cad;
    cin.getline(Buff,200,delim);
    cad=new char[strlen(Buff)+1];
    strcpy(cad,Buff);
    return cad;
}

char **leerReq(){
    char *buffer[100];
    char *requi,**lrequi;
    int i,j;
    i=0;
    
    while(i){
        requi=new char[7];
        cin.get(requi,7);
        buffer[i]=requi;
        i++;
        if(cin.get()=='\n')break;
    }
    buffer[i]=NULL;
    lrequi=new char*[i+1];
    
    for(j=0;j<i+1;j++)
        lrequi[j]=buffer[j];
    return lrequi;
    
}

void leearchivo(char **&cursos,char **&nombres,char ***&requisitos){
    char *buffCod[200],*buffNom[200],**buffReq[200],c;
    int n;
    n=0;
    while(1){
        buffCod[n]=leerCadena(',');
        buffNom[n]=leerCadena(',');
        buffReq[n]=leerReq();
        c=cin.peek();
        if(c=='\n')break;
        
    }
   
}
void ordenacursos(char **&cursos,char **&nombres,char ***&requisitos){
    ;
   
}
void imprimecursos(char **cursos,char **nombres){
    ;
   
}
void imprimetodo(char **cursos,char **nombres,char ***requisitos){
    ;
   
}

int main(int argc, char** argv) {
    char **cursos,**nombres,***requisitos;
    
    leearchivo(cursos,nombres,requisitos);
    ordenacursos(cursos,nombres,requisitos);
    imprimecursos(cursos,nombres);
    imprimetodo(cursos,nombres,requisitos);
    return 0;
}

