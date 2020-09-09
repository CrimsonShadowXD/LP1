/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:29 PM
 */
#include "NodoC.h"
#include "ListaDoble.h"
#include "Infraccion.h"

#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H

class ListaConductores {
public:
    ListaConductores();
    virtual ~ListaConductores();
    
    void insertar(NodoC *nuevo);
    void multar(int dni,char *placa, int codigo);
    
    void crear(ifstream &in);
    void imprimir(ofstream &out);
    void lecturaMultas(ifstream &in);
       
    void imprimirMultas(ofstream& out, ListaDoble<Infraccion> infs);
private:
    NodoC *lista;
};

#endif /* LISTACONDUCTORES_H */

