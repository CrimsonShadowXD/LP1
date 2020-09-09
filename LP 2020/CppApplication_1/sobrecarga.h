/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: crimson
 *
 * Created on July 2, 2020, 7:34 PM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "ACurso.h"
#include "Alumnos.h"
#include "Curso.h"
using namespace std;

ifstream &operator >> (ifstream &, Alumnos &);
ifstream &operator >> (ifstream &, ACurso &);
ofstream &operator << (ofstream &, Alumnos &);

#endif /* SOBRECARGA_H */

