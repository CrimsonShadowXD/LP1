/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Func-Ex-Preg01.h"
#include "Func-Ex-Preg02.h"
#define INC 5
using namespace std;

void saltarLineas(ifstream& arch,int &n){
    char c,*cad;
    cad=new char[500];
    c=arch.peek();
    while(!isdigit(c)){
        arch.getline(cad,500,'\n');
        c=arch.peek();
        n++;
    }
        
}

void leerPasajeros(ifstream& arch,char ****&pasajeros,char ***&sinAsignar){
    int n=0,cap=0;
    while(1){
        if(arch.eof())break;
    }
}

char **leerPasajeros(ifstream& arch){
    char **aux,*Nomb,*Dest,*DNI;
    aux=new char*[3];
    
    DNI=new char[15];
    arch.getline(DNI,15,',');
    //cout<<DNI<<endl;
    if(arch.eof())return NULL;
    
    Nomb=new char[100];
    arch.getline(Nomb,100,',');
    //cout<<Nomb<<endl;
    
    Dest=new char[75];
    arch.getline(Dest,75,'\n');
    
    aux[0]=DNI;
    aux[1]=Nomb;
    aux[2]=Dest;
    return aux;
}

void buscarDest(char **ruta,char **aux,int &encontrado){
    int c=2;
    while(!encontrado && ruta[c]!=NULL){
        //cout<<ruta[c]<<' '<<aux[2]<<endl;
        if(strcmp(ruta[c],aux[2])==0)
            encontrado=1;
        c++;
    }
}

void BuscarCarro(char ***rutas,int *asientos,char **aux,int &posActual){
    int encontrado=0;
    while(rutas[posActual]!=NULL && !encontrado){
        //cout<<posActual<<endl;
        buscarDest(rutas[posActual],aux,encontrado);
        if(encontrado)break;
        posActual++;
    }
}

int contarPasajeros(char ***pasajeros){
    int c=0;
    if (pasajeros==NULL)
        return 0;
    else
        for(int i=0;pasajeros[i]!=NULL;i++)c++;
    return c;
}

void colocarPasajero(char ***&pasajeros,char **aux){
    char ***nuevoArr;
    if(pasajeros==NULL){
        pasajeros=new char**[2];
        pasajeros[0]=aux;
        pasajeros[1]=NULL;
    }
    else{
        int n=contarPasajeros(pasajeros);
        nuevoArr=new char**[n+2];
        for(int i=0;pasajeros[i]!=NULL;i++)
            nuevoArr[i]=pasajeros[i];
        nuevoArr[n]=aux;
        nuevoArr[n+1]=NULL;
    }
}

void incrementarSA(char ***&sinAsignar,int &n,int &cap){
    char ***aux;
    cap+=INC;
    if(sinAsignar==NULL){
        sinAsignar=new char**[cap];
        sinAsignar[0]=NULL;
        n=1;
    }
    else{
        aux=new char**[cap];
        for(int i=0;i<n;i++)aux[i]=sinAsignar[i];
        aux[n]=NULL;
        sinAsignar=aux;
    }
}

void colocarSinAsignar(char **aux,char ***&sinAsignar,int &n,int &cap){
    if(n==cap)incrementarSA(sinAsignar,n,cap);
    sinAsignar[n-1]=aux;
    sinAsignar[n]=NULL;
    n++;
}

void ubicarPasajeros(char ***rutas,int *asientos,char ****&pasajeros,char ***&sinAsignar){
    char **aux;
    int n=0,asignado,posActual,SA_n=0,SA_cap=0;
    ifstream arch("a.csv",ios::in);
    if(!arch){
        cerr<<"Error"<<endl;
        exit(1);
    }
    saltarLineas(arch,n);
    pasajeros=new char***[n];
    for(int i=0;i<n;i++)pasajeros[i]=NULL;
    aux=new char*[3];
    sinAsignar=NULL;
    while(1){
        asignado=0;
        posActual=0;
        aux=leerPasajeros(arch);
        if(aux==NULL)break;
        while(!asignado && posActual <n){
            BuscarCarro(rutas,asientos,aux,posActual);
            if(contarPasajeros(pasajeros[posActual])==asientos[posActual])
                posActual++;
            else {
                asignado=1;
                if(pasajeros[posActual]==NULL)colocarPasajero(pasajeros[posActual],aux);
            }
        }
        if(posActual==n-1)colocarSinAsignar(aux,sinAsignar,SA_n,SA_cap);
    }
    arch.close();
}

void imprRuta(ofstream& arch,char **ruta,int &n){
    arch<<"Placa: "<<ruta[0]<<endl;
    arch<<"Chofer: "<<ruta[1]<<endl;
    arch<<"Ruta: "<<ruta[2];
    for(int i=3;ruta[i]!=NULL;i++){
        arch<<" - "<<ruta[i];
        n++;
    }
    arch<<endl;
    arch<<"Pasajeros: "<<endl;
}

void impPasDestino(ofstream& arch,char *Destino,char **pasajeros,int &n){
    //cout<<pasajeros[2]<<':'<<Destino<<endl;
    if(strcmp(pasajeros[2],Destino)==0){
        arch<<setw(3)<<n<<setw(6)<<' '<<pasajeros[0]<<setw(28)<<' '<<pasajeros[1]<<endl;
        n++;
    }
}

void imprPasaj(ofstream& arch,char **ruta,char ***pasajeros,int auxPos){
    int nPas;
    arch<<ruta[auxPos]<<':'<<endl;
    //cout<<ruta[auxPos]<<':'<<endl;
    if(pasajeros==NULL)arch<<"  No hay pasajeros"<<endl;
    else{
        arch<<"No."<<setw(9)<<"DNI"<<setw(30)<<' '<<"Nombre"<<endl;
        nPas=1;
        for(int i=0;pasajeros[i]!=NULL;i++){
            impPasDestino(arch,ruta[auxPos],pasajeros[i],nPas);
        }
        if(nPas==1)arch<<"  No hay pasajeros"<<endl;
    }
    arch<<endl;
}

void imprimrSA(ofstream& arch,char **sinAsignar){
    arch<<setw(6)<<' '<<sinAsignar[0]<<setw(28)<<' '<<sinAsignar[1]<<setw(20)<<' '<<sinAsignar[2]<<endl;
}

void reporteDeViajes(char ***rutas,int *asientos,char ****pasajeros,char ***sinAsignar){
    int n;
    ofstream arch("2.txt",ios::out);
    arch<<setw(45)<<' '<<"Lista de Pasajeros"<<endl;
    for(int i=0;i<240;i++)arch<<'=';arch<<endl;
    for(int i=0;rutas[i]!=NULL;i++){
        n=1;
        arch<<"Vehiculo No. "<<i+1<<endl;
        imprRuta(arch,rutas[i],n);
        for(int j=0;j<n;j++){
            int auxPos=j+2;
            imprPasaj(arch,rutas[i],pasajeros[i],auxPos);
        }
    }
    for(int i=0;i<240;i++)arch<<'=';arch<<endl;
    arch<<"PASAJEROS SIN ASIGNAR"<<endl;
    if(sinAsignar!=NULL){
        arch<<"No."<<setw(9)<<"DNI"<<setw(30)<<' '<<"Nombre"<<setw(28)<<' '<<"Destino"<<endl;
        for(int i=0;sinAsignar[i]!=NULL;i++){
            arch<<setw(3)<<i+1<<' ';
            imprimrSA(arch,sinAsignar[i]);
        }
    }
}
