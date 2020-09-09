
/* 
 * File:   InstitucionEducativa.h
 * Author: Rodrigo Agama
 *
 * Created on 6 de julio de 2020, 20:17
 */
#include "ListaAlumnos.h"

#ifndef INSTITUCIONEDUCATIVA_H
#define INSTITUCIONEDUCATIVA_H

class InstitucionEducativa {
private:
    class ListaAlumnos lista;

public:
    InstitucionEducativa();
    virtual ~InstitucionEducativa();
    
    void leerAlumnos();
    void leerCursos();
    void imprimirReporte();


};

#endif /* INSTITUCIONEDUCATIVA_H */

