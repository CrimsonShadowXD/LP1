
/* 
 * File:   Profesor.h
 * Author: Rodrigo Agama    Codigo:20151460
 *
 * Created on 3 de julio de 2020, 08:06
 */
#include "Persona.h"
#include <fstream>

using namespace std;

#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor: public Persona {
private:
    char* categoria;
    char* dedicacion;
    char* seccion;
    char *grado;    

public:
    Profesor();
    Profesor(const Profesor &orig);
    virtual ~Profesor();
    void SetGrado(char* grado);
    char* GetGrado() const;
    void SetSeccion(char* seccion);
    char* GetSeccion() const;
    void SetDedicacion(char* dedicacion);
    char* GetDedicacion() const;
    void SetCategoria(char* categoria);
    char* GetCategoria() const;
    
    void operator=(Profesor &in);
    void leer(ifstream &in);
    void imprimir(ofstream &out);

};

#endif /* PROFESOR_H */

