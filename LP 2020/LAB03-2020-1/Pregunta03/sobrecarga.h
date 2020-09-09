/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 3 de julio de 2020, 09:41 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Miembro.h"
#include "Alumno.h"
#include "Persona.h"
using namespace std;


ofstream &operator << (ofstream &arch, const Alumno &alum);
ofstream &operator << (ofstream &arch, const Profesor &prof);

ifstream &operator >> (ifstream &arch,Miembro &M);
ifstream &operator >> (ifstream &arch,Profesor &prof);
ifstream &operator >> (ifstream &arch,Alumno &alum);

#endif /* SOBRECARGA_H */

