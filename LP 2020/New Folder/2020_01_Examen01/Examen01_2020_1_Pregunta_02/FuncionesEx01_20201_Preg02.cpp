/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */

#include "FuncionesEx01_20201_Preg02.h"

int *leerClases(ifstream &arch){
    int *Respuesta=NULL, aux[150]; 
    char c;
    int dia, hi, mi, hf,mf, tam=0,  Clase, a;
    while(1){
        int *P_clase;
        c=arch.get();
        a=c;
        if(a==13){
            break;
        }
        arch>>dia>> hi>>c>> mi>> hf>>c>>mf;
//        cout<<dia<<hi<<mi<<hf<<mf<<endl;
        Clase=100000000*dia+1000000*hi+10000*mi+100*hf+mf;
//        cout<<Clase<<' '<<endl;
        aux[tam]=Clase;
        aux[tam+1]=-1;
        tam++;        
    }
    Respuesta=new int[tam+1];
    for(int i=0;aux[i]!=-1;i++){
        Respuesta[i]=aux[i];
    }
    Respuesta[tam+1]=-1;
    return Respuesta;
}

void *leerSesion(ifstream &arch){
    int N_alum,Cod_Prof,*P_NAlum, *ClasesSemana,*P_CodProf;
    char CodSesion[8],HorSesion[8],*P_Cod,*P_Hor;
    void  **Aux;
    arch.getline(CodSesion,8,' ');
    if(arch.eof()){
        return NULL;
    }
    P_Cod=new char[strlen(CodSesion)+1];
    strcpy(P_Cod,CodSesion);
    arch>>ws;
    arch.getline(HorSesion,8,' ');
    P_Hor=new char[strlen(HorSesion)+1];
    strcpy(P_Hor,HorSesion);
    
    arch>>N_alum;
    arch>>Cod_Prof;
    P_NAlum=new int;
    P_CodProf=new int;
    *P_NAlum=N_alum;
    *P_Cod=Cod_Prof;
    
//    cout<<Cod_Prof<<endl;
    ClasesSemana=leerClases(arch);
    
    Aux= new void*[5];
    Aux[0]=P_Cod;
    Aux[1]=P_Hor;
    Aux[2]=P_NAlum;
    Aux[3]=P_Cod;
    Aux[4]=ClasesSemana;
    arch>>ws;
    return Aux;
}

void leerSesiones(void *&sesiones){
    ifstream ArchSes("Sesiones.txt",ios::in);
    if(!ArchSes){
        cerr<<"No se pudo abrir el archivo Sesiones.txt"<<endl;
        exit(1);
    }
    void *auxSesion, *Sesiones_Aux[10000], **reg=(void**)sesiones;
    int tam=0;
    while(1){
        auxSesion=leerSesion(ArchSes);
        if(auxSesion==NULL){
            break;
        }
        Sesiones_Aux[tam]=auxSesion;
        Sesiones_Aux[tam+1]=NULL;
        tam++;
    }
    reg=new void*[tam+1];
    for(int i=0;Sesiones_Aux[i]!=NULL;i++){
        reg[i]=Sesiones_Aux[i];
    }
    reg[tam]=NULL;
    sesiones=reg;
}

void imprimirClases(ofstream &arch,void *clases){
    void **reg=(void **)clases;
    for(int i=0;reg[i]!=NULL;i++){
        int *P_Sesion=(int*)(reg[i]), clase,dia, residuo;
        clase=*P_Sesion;
        dia=clase/100000000;
        residuo=clase%100000000;
        arch<<"DIA: ";
        if(dia=1){
            arch<<left<<setw(10)<<"LUNES";
        }
        else if(dia=2){
            arch<<left<<setw(10)<<"MARTES";
        }
        else if(dia=3){
            arch<<left<<setw(10)<<"MIERCOLES";
        }
        else if(dia=4){
            arch<<left<<setw(10)<<"JUEVES";
        }
        else if(dia=5){
            arch<<left<<setw(10)<<"VIERNES";
        }
        else if(dia=6){
            arch<<left<<setw(10)<<"SABADO";
        }
        arch<<"INICIO: "<<right<<setw(2)<<setfill('0')<<residuo/1000000<<':';
        residuo=residuo%1000000;
        arch<<setw(2)<<setfill('0')<<residuo/10000<<setfill(' ');
        residuo=residuo%10000;
        arch<<"   FIN: "<<setw(2)<<setfill('0')<<residuo/100<<':'<<setw(2)<<setfill('0')<<residuo%100<<setfill(' ');
        arch<<endl;
    }
}

void imprimirSesion(int i,ofstream &arch, void *sesion){
    void **reg=(void **)sesion;
    arch<<setw(2)<<i+1<<')';
    char *Cod=(char*)(reg[0]);
    char *Hor=(char*)(reg[1]);
    int *P_NAlum=(int*)(reg[2]);
    int *P_cod=(int*)(reg[3]);
    cout<<"CODIGO: "<<left<<setw(10)<<Cod<<"HORARIO: "<<setw(10)<<Hor<<"No.ALUMNOS: "<<setw(10)<<*P_NAlum<<"PROFESOR: "<<setw(10)<<*P_cod<<endl;
    cout<<"SESIONES:"<<endl;
    //imprimirClases(arch,reg[4]);
    cout<<endl;
}

void imprimirSesiones(void *&sesiones){
    ofstream arch("ReporteSesiones.txt",ios::out);
    arch<<setw(50)<<"SESIONES DE CLASE"<<endl;
    void **reg=(void**)sesiones;
    for(int i=0;reg[i]!=NULL;i++){
        imprimirSesion(i, arch, reg[i]);
    }
}