/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArbolBinario.cpp
 * Author: Hans Matos Rios (20151475)
 * 
 * Created on 22 de junio de 2018, 08:02 AM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <valarray>
#include "ArbolBinario.h"

#define N 256

using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = NULL;
}

void ArbolBinario::insertar(libro& lib) {
    insertar(raiz, lib);//Llama al auxiliar para no romper el encapsulamiento
}

void ArbolBinario::insertar(Nodo*& nodo, libro& dato) {
    if(nodo==NULL){//Llego al hijo vacio, se crea el nodo correspondiente
        nodo = new Nodo;//Se pudo hacer nodo = new Nodo(dato);
        nodo->dato = dato;
    }else{
        if (dato < nodo->dato) insertar(nodo->izq, dato);//Si es menor, inserta en el izquierdo
        else insertar(nodo->der, dato); //Si es mayor, inserta en el derecho
    }
}

void ArbolBinario::modificar(const char* codLib) {
    /*Esta funcion buscara un libro por su codigo y modificara la cantidad de
     libros vendidos y el monto recaudado*/
    class Nodo *encontrado;
    encontrado = buscar(raiz, codLib);
    if(encontrado!=NULL)//Se modifica solo si se encontro el libro
        //Se actualiza los montos y cantidad vendidos a traves de ++
        encontrado->dato++; 
}

Nodo* ArbolBinario::buscar(Nodo* nodo, const char*codLib) {
    char cod[N];
    if(nodo == NULL)// no se encontro
        return NULL;
    else{//Se sigue buscando
        //Se pudo haber comparado mediante sobrecarga de operadores tambien
        nodo->dato.GetCodigo(cod);//Compararemos por codigos
        if(strcmp(codLib, cod)==0) return nodo;//Son iguales, retorna el nodo actual
        else if(strcmp(codLib, cod)<0) return buscar(nodo->izq, codLib);//Es menor, busca en el hijo izquierdo
        else return buscar(nodo->der, codLib);//Es mayor, busca en el nodo derecho       
    }
}

void ArbolBinario::imprimir(ofstream& arch) {
    inorden(raiz,arch); //Imprimimos el arbolito usando recorrido inorden (auxiliar)
}

void ArbolBinario::inorden(Nodo* nodo, ofstream& arch) {
    if(nodo==NULL) return;//recordando algoritmia y funda
    inorden(nodo->izq, arch);
    arch << nodo->dato; //Imprimimos mediante la sobrecarga del operador <<
    inorden(nodo->der, arch);
}
