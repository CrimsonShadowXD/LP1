/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEx01_20201_Preg01.h
 * Author: Leandro Lazo La Rosa
 * Codigo: 20130263
 * Created on 2 de junio de 2020, 08:14 AM
 */

#ifndef FUNCIONESEX01_20201_PREG01_H
#define FUNCIONESEX01_20201_PREG01_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void incrementarEspProfesores(int *&CodProfesor_aux,char **&Profesores_aux,int &n,int &cap);
void leerProfesores(int *&codProfesores,char **&profesores);
void incrementarEspCursos(char ***&Cursos_aux,int &n,int &cap);
void leerCursos(char ***&cursos);
void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores);
void imprimirDatos(char ***&cursos,int *&codProfesores,char **&profesores);

#endif /* FUNCIONESEX01_20201_PREG01_H */

