/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "newfile.h"

using namespace std;

void *leerCadena2(ifstream& arch,char d){
    int codint,*codigo;
    char *cad,nom[100];
    void *linea;
    
    arch>>ws;
    arch.getline(nom,100,d);
    if(arch.eof()) return NULL;
    cad = new char[strlen(nom)+1];
    strcpy(cad,nom);
    
    
    linea = cad; 
    
    return linea;
}

void *leerCadena(ifstream& arch){
    int codint,*codigo;
    char *nombre,nom[100],nom2[5],*codigo2;
    void **linea;
    
    arch >> codint;
    if(arch.eof()) return NULL;
    codigo=new int;
    *codigo = codint;
    
    arch>>ws;
    arch.getline(nom,100,' ');
    nombre = new char[strlen(nom)+1];
    strcpy(nombre,nom);
    
    cout<<codint<<' '<<nom<<' ';
    arch>>ws;
    arch.getline(nom2,5,'\n');
    codigo2 = new char[strlen(nom2)+1];
    strcpy(codigo2,nom2);
    cout<<nom2<<endl;
    arch>>ws;
    linea = new void*[3];
    linea[0] = codigo;
    linea[1] = nombre;
    linea[2] = codigo2; 
    
    return linea;
}
void leerPalets(void *&almacenes,int &n){
    void *Buff[500],*p,**paux;
    n=0;
    ifstream arch("Stock .txt",ios::in);
    if(!arch)
    {
        cout << "No abre";
        exit(1);
    }
    while(1){
        p=leerCadena(arch);
        if(p==NULL)break;
        Buff[n]=p;
        n++;
    }
    paux = new void*[n+1];
    
    for(int i=0;i<n;i++)
        paux[i]=Buff[i];
    almacenes=paux;
}

void imprimir(ofstream& arch,void *almacen){
    void **aux=(void**)almacen;
    
    int *cod=(int*)(aux[0]);
    char *nombre=(char*)(aux[1]);
    char *cod2=(char*)(aux[2]);
    
    arch<<*cod<<' '<<nombre<<' '<<cod2<<endl;
    
}

void imprimirPalets(void *almacenes,int n){
    void **aux=(void**)almacenes;
    
    ofstream arch("Almacen.txt",ios::out);
    
    for(int i=0;i<n;i++)
        imprimir(arch,aux[i]);
}
void leerProductos(void *&codigoProd,void *&nombreProd,int &n){
    void *Buff[500],*Buff2[500],*p1,**paux1,**paux2,*p2;
    n=0;
    ifstream arch("Stock .txt",ios::in);
    if(!arch)
    {
        cout << "No abre";
        exit(1);
    }
    while(1){
        p1=leerCadena2(arch,',');
        if(p1==NULL)break;
        p2=leerCadena2(arch,'\n');
        Buff[n]=p1;
        Buff2[n]=p2;
        n++;
    }
    paux1 = new void*[n+1];
    paux2 = new void*[n+1];
    for(int i=0;i<n;i++){
        paux1[i]=Buff[i];
        paux2[i]=Buff2[i];
    }
    codigoProd=paux1;
    nombreProd=paux2;
}
void imprimirProductos(void *codigoProd,void *nombreProd,int n){
    void *aux1=
    ofstream arch("Products .txt",ios::out);
    for(int i=0;i<n;i++)
        imprim(arch,codigoProd[i],nombreProd[i]);
}
void ordenarproductos(void *&codigoProd,void *&nombreProd){

}
void cuentaproductos(void *almacenes,void *codigoProd,void *nombreProd){

}