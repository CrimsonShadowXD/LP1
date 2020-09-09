
/* 
 * File:   auxiliar.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 09:35
 */
#include <fstream>

#include "ACurso.h"
#include "Curso.h"
#include "Alumno.h"

using namespace std;

#ifndef AUXILIAR_H
#define AUXILIAR_H

    void leerAlumnos(Alumno *&alumnos, int &n);
    void leerCursos(Alumno *&alumnos);
    void corregirCursos(Alumno *&alumnos);
    void imprimirAlumnos(Alumno *alumnos, int n);

#endif /* AUXILIAR_H */

