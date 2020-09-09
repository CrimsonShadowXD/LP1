/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */
#include "FuncionesEx01_20201_Preg01.h"

void incrementarEspProfesores(int *&CodProfesor_aux,char **&Profesores_aux,int &n,int &cap){
    char **AuxProf;
    int *AuxCod;
    cap+=5;
    if(Profesores_aux==NULL){
        Profesores_aux=new char*[cap];
        Profesores_aux[0]=NULL;
        CodProfesor_aux=new int[cap];
        CodProfesor_aux[0]=-1;
        n=1;
    }
    else{
        AuxProf=new char*[cap];
        AuxCod=new int[cap];
        for(int i=0;Profesores_aux[i]!=NULL;i++){
            AuxProf[i]=Profesores_aux[i];
            AuxCod[i]=CodProfesor_aux[i];
        }
        Profesores_aux=AuxProf;
        CodProfesor_aux=AuxCod;
    }
}

void leerProfesores(int *&codProfesores,char **&profesores){
    ifstream ArchProf("Profesores.csv",ios::in);
    if (!ArchProf){
        cerr<<"No se pudo abrir el archivo Profesores.csv"<<endl;
        exit(1);
    }
    char BuffNom[150],**Profesores_aux=NULL, *P_nom, c;
    int n=0, cap=0, Codigo, *CodProfesor_aux;
    while(1){
        ArchProf>>Codigo>>c;
        if(ArchProf.eof()){
            break;
        }
        ArchProf.getline(BuffNom,150);
        if(n==cap){
            incrementarEspProfesores(CodProfesor_aux,Profesores_aux,n,cap);
        }
        P_nom=new char[strlen(BuffNom)+1];
        strcpy(P_nom,BuffNom);
        Profesores_aux[n-1]=P_nom;
        Profesores_aux[n]=NULL;
        CodProfesor_aux[n-1]=Codigo;
        CodProfesor_aux[n]=-1;
        n++;
    }
    profesores=new char*[n+1];
    codProfesores=new int[n+1];
    for(int i=0;i<n;i++){
        profesores[i]=Profesores_aux[i];
        codProfesores[i]=CodProfesor_aux[i];
    }
    profesores[n]=NULL;
    codProfesores[n]=-1;
}

void incrementarEspCursos(char ***&Cursos_aux,int &n,int &cap){
    char ***Aux;
    cap+=5;
    if(Cursos_aux==NULL){
        Cursos_aux=new char**[cap];
        Cursos_aux[0]=NULL;
        n=1;
    }
    else{
        Aux=new char**[cap];
        for(int i=0;Cursos_aux[i]!=NULL;i++){
            Aux[i]=Cursos_aux[i];
        }
        Cursos_aux=Aux;
    }
}

void leerCursos(char ***&cursos){
    ifstream ArchCur("Cursos.csv",ios::in);
    if (!ArchCur){
        cerr<<"No se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    char BuffCod[9],BuffNom[150],BuffEsp[100],***ArrCursos_aux=NULL, **DatosCurso, *P_cod,*P_nom,*P_esp;
    int n=0, cap=0;
    while(1){
        ArchCur.getline(BuffCod,9,',');
        if(ArchCur.eof()){
            break;
        }
        ArchCur.getline(BuffNom,150,',');
        ArchCur.getline(BuffEsp,100);
        if(n==cap){
            incrementarEspCursos(ArrCursos_aux,n,cap);
        }
        DatosCurso=new char*[3];
        P_cod=new char[strlen(BuffCod)+1];
        strcpy(P_cod,BuffCod);
        P_nom=new char[strlen(BuffNom)+1];
        strcpy(P_nom,BuffNom);
        P_esp=new char[strlen(BuffEsp)+1];
        strcpy(P_esp,BuffEsp);
        DatosCurso[0]=P_cod;
        DatosCurso[1]=P_nom;
        DatosCurso[2]=P_esp;
        ArrCursos_aux[n-1]=DatosCurso;
        ArrCursos_aux[n]=NULL;
        n++;
    }
    cursos=new char**[n+1];
    for(int i=0;i<n;i++){
        cursos[i]=ArrCursos_aux[i];
    }
    cursos[n]=NULL;
}

void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores){
    leerCursos(cursos);
    leerProfesores(codProfesores,profesores);
}

void imprimirDatos(char ***&cursos,int *&codProfesores,char **&profesores){
    ofstream Archrep("CursosInstitucion.txt", ios::out);
    Archrep<<setw(40)<<"CURSOS DE LA INSTITUCION"<<endl;
    Archrep<<left<<setw(3)<<' '<<setw(11)<<"CODIGO"<<setw(50)<<"CURSO"<<setw(100)<<"ESPECIALIDAD"<<endl;
    for(int i=0;cursos[i]!=NULL;i++){
        Archrep<<right<<setw(3)<<i+1<<") "<<left<<setw(9)<<cursos[i][0]<<setw(50)<<cursos[i][1]<<setw(100)<<cursos[i][2]<<endl;
    }
    Archrep<<endl;
    Archrep<<right<<setw(40)<<"PROFESORES DE LA INSTITUCION"<<endl;
    Archrep<<left<<setw(3)<<' '<<setw(11)<<"CODIGO"<<setw(150)<<"NOMBRE"<<endl;
    for(int i=0;profesores[i]!=NULL;i++){
        Archrep<<right<<setw(3)<<i+1<<") "<<left<<setw(9)<<codProfesores[i]<<setw(150)<<profesores[i]<<endl;
    }
    
}