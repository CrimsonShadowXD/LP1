/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 */

#include "FuncionesActividad05.h"

void incrementar(void **&reg, int &n, int &cap){
    void **aux;
    cap+=5;
    if(reg==NULL){
        reg=new void*[cap];
        reg[0]=NULL;
        n=1;
    }
    else{
        aux=new void*[cap];
        for(int i=0;i<n;i++)
            aux[i]=reg[i];
        reg=aux;
    }
}

void *leeAlum(ifstream &arch){
    char tipo_alum, nom_alum[200], Residuo[1000], coma, *P_nom;
    int cod_alum, *P_cod, *P_nota, nota=0, *P_cant, cant_cur=0;
    float *P_cred, cred=0, *P_aprob, aprob=0;
    void **reg;
    
    arch>>tipo_alum;
    arch>>coma;
    
    arch>>cod_alum;
    if(arch.eof()) {
        return NULL;
    }
    P_cod=new int;
    *P_cod=cod_alum;
    
    arch>>coma;
    
    arch.getline(nom_alum,200,',');
    P_nom=new char[strlen(nom_alum)+1];
    strcpy(P_nom, nom_alum);
    
    arch.getline(Residuo,1000);
    
    P_cant=new int;
    *P_cant=cant_cur;
    
    P_nota=new int;
    *P_nota=nota;
    
    P_cred=new float;
    *P_cred=cred;
    
    P_aprob=new float;
    *P_aprob=aprob;
    
    
    reg=new void*[7];
    reg[0]=P_cod;
    reg[1]=P_nom;
    reg[2]=P_cred;
    reg[3]=P_aprob;
    reg[4]=P_cant;
    reg[5]=P_nota;
    reg[6]=NULL;
    
    return reg;
}

void leerAlumnos(void *&alumnos){
    ifstream arch("Alumnos.csv", ios::in);
    if(!arch){
        cerr<<"No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    
    void **reg=(void**)alumnos, *Al_aux;
    int n=0, cap=0;
    
    while(1){
        Al_aux=leeAlum(arch);
        if(Al_aux==NULL){
            break;
        }
        if(n==cap){
            incrementar(reg, n, cap);
        }
        reg[n-1]=Al_aux;
        reg[n]=NULL;
        n++;
    }
    alumnos=reg;
}

void imp_Al(ofstream &arch, void *Alum){
    void **aux=(void**)Alum;
    int *cod=(int*)(aux[0]);
    char *nom=(char*)(aux[1]);
    
    arch<<left<<setw(20)<<*cod<<right<<nom<<endl;
}

void imprimirAlumnos(void *&alumnos){
    void **aux=(void**)alumnos;
    ofstream arch("ImprimirAlumnos.txt",ios::out);
    int i;
    arch<<left<<setw(20)<<"Codigo"<<right<<"Nombre"<<endl;
    for(i=0; aux[i]!=NULL; i++){
        imp_Al(arch, aux[i]);
    }
}

void insertarCurso(void *&aux,int cant_cur,char *cod_curso){
    //void **aux;
    int n=0, cap=0;
    void *curso;
    void **reg=(void**)aux;

    if(aux==NULL){
        incrementar(reg,n,cap);
    }
    else{
        for(int i=0;reg[i]!=NULL;i++){
            n++;
        }  
        n+=1;
        cap=n;
        if(n%5==0)incrementar(reg,n,cap);
    }
    reg[n-1]=cod_curso;
    reg[n]=NULL;
    aux=reg;
}

void colocarDatos(void *&reg, int CodAl, char *cod_curso, int nota, float cred){
    void **aux=(void**)reg; 
    int *cod=(int*)(aux[0]);
    int nota_aux, cant_cur;
    float cred_aux, aprob_aux;
    if(*cod==CodAl){
        float *Pcred=(float*)(aux[2]);
        float *Paprob=(float*)(aux[3]);
        int *Pcur=(int*)(aux[4]);
        int *Pnota=(int*)(aux[5]);
        
        nota_aux=*Pnota;
        cant_cur=*Pcur;
        
        cred_aux=*Pcred;
        aprob_aux=*Paprob;
//        cout<<cred_aux<<' '<<aprob_aux<<' '<<cant_cur<<' '<<nota_aux<<endl;
        cred_aux+=cred;
        if(nota>10){
            aprob_aux+=cred;
            insertarCurso(aux[6],cant_cur,cod_curso);
        }
        cant_cur+=1;
        nota_aux+=nota;
        
        *Pcred=cred_aux;
        *Paprob=aprob_aux;
        *Pcur=cant_cur;
        *Pnota=nota_aux;
        
        aux[2]=Pcred;
        aux[3]=Paprob;
        aux[4]=Pcur;
        aux[5]=Pnota;
//        cout<<*Pcred<<' '<<*Paprob<<' '<<*Pcur<<' '<<*Pnota<<endl;
        
//        cout<<"==="<<endl;
//        exit(1);
    }
}

void leerCursos(void *&alumnos){
    ifstream arch("Cursos.csv",ios::in);
    if(!arch){
        cerr<<"No se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    
    void **reg=(void**)alumnos, *aux;
    
    while(1){
        int auxCodAl, nota, ciclo, periodo;
        char coma, cod_curso[9], *Pcodcur,tipo_reg;
        float cred;
        
        arch>>auxCodAl;
        if(arch.eof()){
            break;
        }
        arch>>coma;
        
        arch.getline(cod_curso,9,',');
        Pcodcur=new char[strlen(cod_curso)+1];
        strcpy(Pcodcur, cod_curso);
        
        arch>>nota; arch>>coma;
        arch>>ciclo; arch>>coma;
        arch>>periodo; arch>>coma;
        arch>>cred; arch>>coma;
        arch>>tipo_reg;
        for(int i=0; reg[i]!=NULL; i++){
            colocarDatos(reg[i],auxCodAl,Pcodcur,nota,cred);
        }
    }
    
}

void auximpcur(ofstream &arch, void *curso){
    void **aux=(void**)curso;
    char *nomcur=(char*)(aux[0]);
    arch<<setw(8)<<nomcur;
}

void imprCursos(ofstream &arch, void *aux){
    void **reg=(void**)aux;
    for(int i=0; reg[i]!=NULL; i++){
//        auximpcur(arch, reg[i]);
        char *nomcur=(char*)(reg[i]);
        arch<<setw(8)<<nomcur;
    }
}

void imprimirAlConsolidado(ofstream &arch, void *alum){
    void **aux=(void**)alum;
    int *cod=(int*)(aux[0]);
    char *nom=(char*)(aux[1]);
    float *Pcred=(float*)(aux[2]);
    float *Paprob=(float*)(aux[3]);
    int *Pcur=(int*)(aux[4]);
    int *Pnota=(int*)(aux[5]);
    
    int cursos=*Pcur, nota=*Pnota;
    float cred=*Pcred, aprob=*Paprob, prom;
    prom=nota/cursos;
    
    arch<<"Codigo:   "<<left<<setw(12)<<*cod<<"Nombre:   "<<setw(60)
        <<nom<<"Cred.: "<<setw(4)<<cred<<"  Cred.Aprob.: "<<setw(4)<<aprob<<"   Prom.Gen.: "<<setw(4)<<prom<<endl;
    arch<<"Cursos Aprobados:     ";
    if(aux[6]!=NULL){
        imprCursos(arch, aux[6]);
    }
    arch<<endl<<endl;
    
}

void consolidado(void *&alumnos){
    ofstream arch("AlumnosConsolidado.txt", ios::out);
    void **reg=(void**)alumnos;
    arch<<setprecision(2)<<fixed;
    for(int i=0; reg[i]!=NULL; i++){
        imprimirAlConsolidado(arch, reg[i]);
    }
    
}
