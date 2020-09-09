

/* 
 * File:   ListaVehiculos.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include "NodoV.h"
#include <fstream>

using namespace std;


#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H

class ListaVehiculos {
public:
    ListaVehiculos();   
    virtual ~ListaVehiculos();
    
    void insertar(NodoV *nuevo);
    void multar(char *placa, int codigo);
    
    void crear(ifstream &in);
    void imprimir(ofstream &out);
    
    int* obtenerMultas();
private:
    NodoV *lista;
};

#endif /* LISTAVEHICULOS_H */

