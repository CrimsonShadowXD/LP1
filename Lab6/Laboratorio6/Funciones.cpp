/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * 
 */
#include "Funciones.h"

const int INC=5;

using namespace std;

void *leerCadena(ifstream& arch){
    int codint,*codigo;
    char *nombre,nom1[100],nom2[5],*Codigo2;
    void **linea;
    
    arch.getline(nom1,100,' ');
    if(arch.eof())return NULL;
    nombre=new char[strlen(nom1)+1];
    strcpy(nombre,nom1);
    
    arch.getline(nom2,5,' ');
    Codigo2=new char[strlen(nom2)+1];
    strcpy(Codigo2,nom2);
    
    arch>>codint;    
    codigo=new int;
    *codigo=codint;
    arch>>ws;
    
    linea=new void*[3];
    linea[0]=nombre;
    linea[1]=Codigo2;
    linea[2]=codigo;
    
    return linea;
}

void incrementar(void **&reg,int &n,int &cap){
    void **aux;
    cap+=INC;
    if(reg==NULL){
        reg=new void*[cap];
        reg[0]=NULL;
        n=1;
    }
    else{
        aux=new void*[cap];
        for(int i=0;i<n;i++)
            aux[i]=reg[i];
//        if(reg!=NULL)
//            delete[] reg;
        reg=aux;
    }
}

void leerPalets(void *&palets){
    //palets=NULL;
    void **reg=(void**)palets,*p;
    int n=0,cap=0;
    ifstream arch("Stock.txt",ios::in);
    if (!arch){
        cerr<<"No se pudo abrir el archivo Stock.txt"<<endl;
        exit(1);
    }
    while(1){
        p=leerCadena(arch);
        if(p==NULL)break;
        if(n==cap)incrementar(reg,n,cap);
        reg[n-1]=p;
        reg[n]=NULL;
        n++;
        if(arch.eof())break;
        //cout<<"bien"<<n<<endl;
    }
    palets=reg;
}

void imprimirPalet(ofstream& arch,void *palets){
    void **aux=(void**)palets;
    char *cod=(char*)(aux[0]);
    char *nom=(char*)(aux[1]);
    int *cod2=(int*)(aux[2]);
    
    arch<<cod<<' '<<nom<<' '<<*cod2<<endl;
}

void ImprimirPalets(void *palets){
    int i;
    void **aux=(void**)palets;
    ofstream arch("Pregunta1.txt",ios::out);
    for(i=0;aux[i]!=NULL;i++){
        imprimirPalet(arch,aux[i]);
    }
}

void *leerProd(ifstream& arch){
    char *nombre,nom[150],cod[15],*Codigo;
    int stock=0,*Pstock;
    void **linea;
    
    arch.getline(cod,15,',');
    if(arch.eof())return NULL;
    Codigo=new char[strlen(cod)+1];
    strcpy(Codigo,cod);
    
    arch.getline(nom,150,'\n');
    nombre=new char[strlen(nom)+1];
    strcpy(nombre,nom);
    
    Pstock=new int;
    *Pstock=stock;
    
    linea=new void*[3];
    linea[0]=Codigo;
    linea[1]=nombre;
    linea[2]=Pstock;
    
    return linea;
}

void leerProductos(void *&producto){
    void **reg=(void**)producto,*p;
    int n=0,cap=0;
    ifstream arch("Productos.csv",ios::in);
    if (!arch){
        cerr<<"No se pudo abrir el archivo Productos.csv"<<endl;
        exit(1);
    }
    while(1){
        p=leerProd(arch);
        if(p==NULL)break;
        if(n==cap)incrementar(reg,n,cap);
        reg[n-1]=p;
        reg[n]=NULL;
        n++;
        if(arch.eof())break;
        //cout<<"bien"<<n<<endl;
    }
    producto=reg;
}

void imprimirProd(ofstream& arch,void *prod){
    void **aux=(void**)prod;
    char *cod=(char*)(aux[0]);
    char *nom=(char*)(aux[1]);
    int *stock=(int*)(aux[2]);
    
    arch<<cod<<' '<<setw(100)<<left<<nom<<' '<<*stock<<endl;
}

void imprimirProductos(void *producto){
    int i;
    void **aux=(void**)producto;
    ofstream arch("Pregunta2_3.txt",ios::out);
    for(i=0;aux[i]!=NULL;i++){
        imprimirProd(arch,aux[i]);
    }
}

int comparar(void *i,void *j){
    void **pi=(void**)i;
    void **pj=(void**)j;
    
    char *nom1,*nom2;
    
    nom1=(char*)pi[1];
    nom2=(char*)pj[1];
    return strcmp(nom1,nom2);
}

void cambio(void *&i,void *&j){
    void *aux;
    aux=i;
    i=j;
    j=aux;
}
void QuickS(void *&producto,int ini, int fin){
    int pivot, i;
    void **aux=(void**)producto;
    if(ini>=fin)return;
    pivot=ini;
    for(i=ini+1;i<=fin;i++)
        if(comparar(aux[i],aux[ini])<0)
            cambio(aux[++pivot],aux[i]);
    cambio(aux[ini],aux[pivot]);
    QuickS(producto,ini,pivot-1);
    QuickS(producto,pivot+1,fin);
}

void ordenarproductos(void *&producto){
    int cantidadProd=0,i;
    void **aux=(void**)producto;
    for(i=0;aux[i]!=NULL;i++)cantidadProd++;
    QuickS(producto,0,cantidadProd-1);
}

void rayado(ofstream& arch,char d){
    for(int i=0;i<=300;i++)arch<<d;
    arch<<endl;
}

void imprimirCabecera(ofstream& arch){
    arch<<setw(105)<<left<<"Nombre de Producto"<<"Codigo de Producto"<<setw(15)<<' '<<"Cant. de Producto"<<endl;
    rayado(arch,'-');
}

int Verificar(void *Prod,void *Palet){
    void **Auxprod=(void**)Prod;
    void **Auxpalet=(void**)Palet;
    
    char *cod1,*cod2;
    
    cod1=(char*)Auxprod[0];
    cod2=(char*)Auxpalet[0];
    return strcmp(cod1,cod2);
}

void imprimCantProd(ofstream& arch,void *prod,int CantProd){
    void **aux=(void**)prod;
    char *cod=(char*)(aux[0]);
    char *nom=(char*)(aux[1]);
    int *stock=(int*)(aux[2]);
    
    arch<<setw(5)<<' '<<setw(100)<<left<<nom<<setw(7)<<' '<<setw(30)<<left<<cod<<CantProd<<endl;
}

void cargastock(void *&palets,void *&producto){
    void **auxPalet=(void**)palets,**auxProd=(void**)producto;
    
    ofstream arch("Pregunta4.txt",ios::out);
    
    imprimirCabecera(arch);
    
    for(int i=0;auxProd[i]!=NULL;i++){
        int CantProd=0;
        for(int j=0;auxPalet[j]!=NULL;j++){
            if(Verificar(auxProd[i],auxPalet[j])==0)CantProd++;
        }
        imprimCantProd(arch,auxProd[i],CantProd);
    }
}
