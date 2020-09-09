
/* 
 * File:   Alumno.cpp
 * Author: Rodrigo Agama    Codigo: 20151460
 * 
 * Created on 26 de junio de 2020, 08:03
 */

#include "Alumno.h"
#include "ACurso.h"
#include "Curso.h"
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

Alumno::Alumno() {
    nombre=nullptr;
    this->numcur=0;
    this->codigo=-1;
}

Alumno::Alumno(const Alumno& orig) {
    this->SetCodigo(orig.GetCodigo());
    this->SetNombre(orig.GetNombre());
    this->SetNumcur(orig.GetNumcur());
    
    for (int i=0; i<this->GetNumcur() ; i++)
        this->lcurso[i]=orig.lcurso[i];
}

Alumno::~Alumno() {
    //delete[] nombre;
}

void Alumno::SetNumcur(int numcur) {
    this->numcur = numcur;
}

int Alumno::GetNumcur() const {
    return numcur;
}

void Alumno::SetNombre(char* nombre) {
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

char* Alumno::GetNombre() const {
    char *aux=new char [strlen(this->nombre)+1];
    strcpy(aux,this->nombre);
    return aux;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::SetTipo(char tipo){
    this->tipo=tipo;
}
    char Alumno::GetTipo(){
        return this->tipo;
    }

    void Alumno::operator+(ACurso &entrada){ //Agregamos.
        this->lcurso[this->numcur]=entrada.GetCurso();
        this->numcur++;
        return;        
    }
    void Alumno::operator*(ACurso &entrada){ //actualizamos.
        Curso aux(entrada.GetCurso());
        
        for (int i=0; i<this->numcur; i++){
            
            if ((this->lcurso[i].GetCiclo()==aux.GetCiclo()) && (strcmp(this->lcurso[i].GetCcurso(),aux.GetCcurso())==0) )
            {
                this->lcurso[i].SetNota(aux.GetNota());
                break;
            }
        }
        return;
    }
    void Alumno::operator-(ACurso &entrada){ // Eliminamos el curso.
        
         Curso aux(entrada.GetCurso());
        
        for (int i=0; i<this->numcur; i++){
            
            if ((this->lcurso[i].GetCiclo()==aux.GetCiclo()) && (strcmp(this->lcurso[i].GetCcurso(),aux.GetCcurso())==0) )
            { //i es la posicion que tenemos que borrar.
                for( int j=i ; j<(this->numcur -1) ; j++)
                    this->lcurso[i] = this->lcurso[i+1];
                
                (this->numcur)--;
                break;
            }
        }
        return;
        
    }
    float Alumno::operator/(int ciclo){ //Promedio
        int n=0;
        float total=0;
        
        for(int i=0; i<this->numcur ; i++){
            if (this->lcurso[i].GetCiclo() == ciclo){
                total+=this->lcurso[i].GetNota();
                n++;
            }            
        }
        return (total/n);
        
    }
    float Alumno::operator--(){ //Suma de Creditos.
  
        float total=0;
        
        for(int i=0; i<this->numcur ; i++)          
                total+=this->lcurso[i].GetCredito();
        
        return total;
    }
    
    float Alumno::operator++(){ //Suma de Creditos aprobados.
         
        float total=0;
        
        for(int i=0; i<this->numcur ; i++)          
            if (this->lcurso[i].GetNota() > 10)
                total+=this->lcurso[i].GetCredito();
        
        return total;
    }

    ifstream& operator>>(ifstream &in, Alumno& nuevo){
        char tipo;
        int codigo;
        char nombre[100];
        
        in>>tipo; 
        if (in.eof()) return in; //Salgo si ya acabé el archivo.
        in>>codigo; 
        in>>nombre; 
        in.ignore(500,'\n'); //Consume el cambio de linea.
        
        nuevo.SetCodigo(codigo);
        nuevo.SetNombre(nombre);
        nuevo.SetTipo(tipo);   
        
        return in;
    }
ofstream& operator<<(ofstream &out, Alumno salida){
    out<<"Nombre: "<<salida.GetNombre()<<endl; float promedio; int n=1;
    out<<"Codigo: "<<salida.GetCodigo()<<endl;
    for(int i=0; i<100; i++) out<<'='; out<<endl;
    out<<"     Ciclo     Promedio"<<endl;
    
    for(int aa=2012; aa<2020; aa++)
        for(int nn=0;nn<3;nn++){
            promedio=salida/(aa*10+nn);
            if (promedio>0){
                out<<left<<n<<")   "<<aa<<'-'<<nn<<"     "<<promedio<<endl;
                n++;
            }
        }
 
    out<<"Creditos Cursados: "<<--salida<<endl;
    out<<"Creditos Aprobados: "<<++salida<<endl;
    
    
    return out;
}
