

/* 
 * File:   ListaCursos.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 10:36 PM
 */

#include "NodoCurso.h"
#include "Curso.h"

#ifndef LISTACURSOS_H
#define LISTACURSOS_H

class ListaCursos {
public:
    ListaCursos();
    virtual ~ListaCursos();
    
    char** buscarCursoYReq(ofstream &out, char *codigo);
     NodoCurso* buscarCurso(char *codigo);
     
    char** requisitosDeCurso(char* curso);
    
    void leer(ifstream &in);
    void imprimir(ofstream &out);
    
    void insertar(NodoCurso *nuevo);
       
private:
    class NodoCurso *lista;
};

#endif /* LISTACURSOS_H */

