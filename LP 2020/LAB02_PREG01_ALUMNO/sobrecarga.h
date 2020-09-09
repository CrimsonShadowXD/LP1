/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 26 de junio de 2020, 09:28 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Curso.h"
#include "Acurso.h"
#include "Alumno.h"

using namespace std;

ifstream &operator >> (ifstream &, Alumno &);
ifstream &operator >> (ifstream &, Acurso &);
ofstream &operator << (ofstream &, Alumno &);



#endif /* SOBRECARGA_H */

