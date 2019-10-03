
/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 1 de octubre de 2019, 07:59 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#define INC 5

using namespace std;

char* leecursos(ifstream &arch)
{   char* curso;
    curso = new char[7];
    arch.getline(curso,7,',');
    if(arch.eof()) return NULL;
    return curso;
}


char* leenombres(ifstream &arch)
{   char* nombre,buffer[100];
    
    arch.getline(buffer,100,',');
    nombre = new char[strlen(buffer)+1];
    strcpy(nombre,buffer);
    return nombre;
}

//Exacta
char** leerequi(ifstream &arch)
{   char *buffer[100];
    char * requi,**lrequi;
    int j,i=0;
    
    while(1)
    {
        requi=new char[7];
        arch.get(requi,7);
        buffer[i]=requi;
        i++;    
        if(arch.get()=='\n') break;
    }
    buffer[i]=NULL;
    lrequi= new char*[i+1];
    
    for(j=0;j<i+1;j++)
        lrequi[j]=buffer[j];
    return lrequi;
        
}

void incrementarEspacios(char **&req,int &numReq, int&tamReq)
{
    char **aux;
    tamReq += INC;
    if(req == NULL){
        req = new char*[tamReq];
    req[0] = NULL;
    numReq = 1;
    }
    else {
        aux = new char*[tamReq];
        for(int i=0; i<numReq; i++)
            aux[i] = req[i];
    delete[]req;
    req = aux;
    }
}


//Incremental
char **leereq(ifstream & archIn)
{
    int tamReq=0, numReq=0;
    char **req=NULL, *codReq;
    
    while(1)
    {
        codReq = new char[7];
        archIn.get(codReq,7);
        if(tamReq == numReq) incrementarEspacios(req,numReq, tamReq);
        req[numReq] = NULL;
        req[numReq-1] = codReq;
        numReq++;
        if(archIn.get()=='\n')break;
    }
    return req;
}



void leearchivo(char** &lcursos,char** &lnombres, char*** &requi)
{   char *bufcur[200],*bufnom[200],**bufreq[200];
    int n,i;

    ifstream arch("PlanDeEstudios1.csv",ios::in);
    if(!arch)
    {   cout << "No se puede abrir el archivo";
        exit(1);
    }    
    
    n=0;
    while(1)
    {   
        bufcur[n]=leecursos(arch);
        if(bufcur[n]==NULL) break;
        bufnom[n]=leenombres(arch);
        bufreq[n]=leereq(arch);   //Aqui setear según se solicite exacta o incremental
        //cout << n <<" "<<bufcur[n]<<" "<<bufnom[n] <<" "<<bufreq[n][0]<< endl;
        n++;
    }    
    bufcur[n]=NULL;
    bufnom[n]=NULL;
    bufreq[n]=NULL;
    lcursos=new char*[n+1];
    lnombres= new char*[n+1];
    requi=new char**[n+1];
    
    for(i=0;i<=n;i++)
    {
        lcursos[i]=bufcur[i];
        lnombres[i]=bufnom[i];
        requi[i]=bufreq[i];
    }    
}

void intercambia(char** &lcursos,char** &lnombres, char*** &requi,int i, int j)
{   char *aux1,**aux2;
    
    aux1 = lcursos[i];
    lcursos[i]=lcursos[j];
    lcursos[j]=aux1;
    
    aux1 = lnombres[i];
    lnombres[i]=lnombres[j];
    lnombres[j]=aux1;

    aux2 = requi[i];
    requi[i]=requi[j];
    requi[j]=aux2;
}

void bubblesort(char** &lcursos,char** &lnombres, char*** &requi,int ini, int fin)
{   int i;
    if(ini>=fin)
        return;

    for(i=0;i<fin;i++)
        if(strcmp(lnombres[i],lnombres[i+1])>0)
            intercambia(lcursos,lnombres,requi,i,i+1);
    bubblesort(lcursos,lnombres,requi,ini,fin-1);
}

void ordenacursos(char** &lcursos,char** &lnombres, char*** &requi)
{
    int n=0;
    for(n=0;lcursos[n];n++);
    bubblesort(lcursos,lnombres,requi,0,n-1);

}

void imprimecursos(char** lcursos,char** lnombres)
{   int i=0;
    ofstream arch("cursos.txt",ios::out);
    if(!arch)
    {   cout << "no se puede acceder";
        exit(1);
    }
    while(lcursos[i])
    {
        arch << left<< setw(20) << lcursos[i] << setw(60) << left << lnombres[i] << endl;
        i++;
    }    

}

void imprimetodo(char** lcursos,char** lnombres,char ***requi)
{   int i=0,j;
    char **lrequi;
    ofstream arch("todo.txt",ios::out);
    if(!arch)
    {   cout << "no se puede acceder";
        exit(1);
    }
    while(lcursos[i])
    {
        arch << left<< setw(20) << lcursos[i] << setw(60) << left << lnombres[i] << endl;
        lrequi=requi[i];
        j=0;
        arch << "Requisitos:";
        while(lrequi[j])
        {   arch <<  setw(10) <<lrequi[j] ;
            j++;
        }
        arch << endl << endl;    
        i++;
    }    

}

int main(int argc, char** argv) {
    char **cursos,**nombres,***requisitos;
    
    leearchivo(cursos,nombres,requisitos);
    ordenacursos(cursos,nombres,requisitos);
    imprimecursos(cursos,nombres);
    imprimetodo(cursos,nombres,requisitos);
    return 0;
}

