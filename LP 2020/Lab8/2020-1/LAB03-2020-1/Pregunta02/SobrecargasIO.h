
/* 
 * File:   SobrecargasIO.h
 * Author: Rodrigo Agama
 *
 * Created on 3 de julio de 2020, 09:30
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Alumno.h"
#include "Persona.h"
#include "Profesor.h"
#include "Miembro.h"

using namespace std;

#ifndef SOBRECARGASIO_H
#define SOBRECARGASIO_H

ifstream & operator>>(ifstream &in, Profesor &entrada);
ifstream & operator>>(ifstream &in, Alumno &entrada);
ifstream & operator>>(ifstream &in, Miembro &entrada);

ofstream & operator<<(ofstream &out, Profesor &entrada);
ofstream & operator<<(ofstream &out, Alumno &entrada);




#endif /* SOBRECARGASIO_H */

