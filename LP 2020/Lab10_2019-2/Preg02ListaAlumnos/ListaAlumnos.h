
/* 
 * File:   ListaAlumnos.h
 * Author: Rodrigo Agama
 *
 * Created on 6 de julio de 2020, 19:26
 */
#include "NodoAlumno.h"
#include <fstream>

using namespace std;

#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

class ListaAlumnos {
private:
    NodoAlumno *lista;

public:
    ListaAlumnos();
    virtual ~ListaAlumnos();
    
    void agregarAlumno(NodoAlumno *&nuevo);
    void leerLista(ifstream &in);
    void leerNotas(ifstream &in);
    void imprimirLista(ofstream &out);


};

#endif /* LISTAALUMNOS_H */

