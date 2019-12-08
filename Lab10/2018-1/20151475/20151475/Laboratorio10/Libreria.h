/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libreria.h
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:38 AM
 */

#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <fstream>
#include "ArbolBinario.h"
using namespace std;
class Libreria {
public:
    Libreria();
    /*Los metodos reciben el nombre del archivo donde esta la informacion o donde
     se imprimira*/
    void crearBibliotecaLibros(const char*);
    void leerVentasDeLibros(const char*);
    void imprimir(const char*);
private:
    class ArbolBinario libros;//Agregacion de clase arbol binario
    void impLinea(ofstream &, char, int);//Para el formato
};

#endif /* LIBRERIA_H */

