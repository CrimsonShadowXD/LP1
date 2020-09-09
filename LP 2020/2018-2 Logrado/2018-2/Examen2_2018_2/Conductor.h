

/* 
 * File:   Conductor.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:28 PM
 */

#include "ListaVehiculos.h"



#ifndef CONDUCTOR_H
#define CONDUCTOR_H

class Conductor {
public:
    Conductor();
    virtual ~Conductor();
    
    void setNombre(char* entrada);    
    char* getNombre();
    void setDni(int entrada);
    int getDni();
    void setTelefono(int entrada);
    int getTelefono();
    
    void multar(char* placa, int codigo);
    
    bool operator>(Conductor b);
    
    void leer(ifstream &in);
    void imprimir(ofstream &out);
    
    int* obtenerMultas();
    
private:
    char *nombre;
    int dni;
    int telefono;
    
    ListaVehiculos vehiculos;
};

#endif /* CONDUCTOR_H */

