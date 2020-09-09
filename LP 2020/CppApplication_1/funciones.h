/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: crimson
 *
 * Created on July 2, 2020, 10:59 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "sobrecarga.h"

using namespace std;
void leerAlumnos(Alumnos *&ArrAlumnos, int &cantAl);
void leerCursos(Alumnos *&alumnos, int n);
void corregirCursos(Alumnos *&alumnos, int n);
void imprimirAlumnos(Alumnos *alumnos, int n);
void procesarArch();

#endif /* FUNCIONES_H */

