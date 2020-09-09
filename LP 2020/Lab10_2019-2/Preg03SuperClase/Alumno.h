
/* 
 * File:   Alumno.h
 * Author: Rodrigo Agama
 *
 * Created on 6 de julio de 2020, 19:29
 */
#include <fstream>
#include "ListaNotas.h"
#include "BaseAlum.h"

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    class BaseAlum *elem;
    class ListaNotas notas;

public:
    Alumno();    
    virtual ~Alumno();
    
    void agregarNota(Nota &nuevo);
    int getCodigo();
    void imprimir(ofstream &out);
    void leer(ifstream &in);

};

#endif /* ALUMNO_H */

