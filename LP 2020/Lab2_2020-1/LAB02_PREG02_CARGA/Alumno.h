
/* 
 * File:   Alumno.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 08:03
 */
#include "Curso.h"
#include "ACurso.h"
#include <fstream>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char tipo;
    char *nombre;
    Curso lcurso[50];
    int numcur; 
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNumcur(int numcur);
    int GetNumcur() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(int codigo);
    int GetCodigo() const; 
    void SetTipo(char tipo);
    char GetTipo();
    
    
    void operator+(ACurso &entrada); //Agregamos curso.    
    void operator*(ACurso &entrada); //Actualizamos curso.
    void operator-(ACurso &entrada); // Eliminamos el curso.
    float operator/(int ciclo); //Promedio de cursos en un ciclo.
    float operator--(); //Suma de Creditos.
    float operator++(); //Suma de Creditos aprobados.
};

ifstream& operator>>(ifstream &in, Alumno& nuevo);
ofstream& operator<<(ofstream &out, Alumno salida);

#endif /* ALUMNO_H */

