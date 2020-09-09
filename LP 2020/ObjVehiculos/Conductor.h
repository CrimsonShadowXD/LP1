/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: cueva
 *
 * Created on 24 de junio de 2020, 12:28 PM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "Faltas.h"

class Conductor {
private:    
    int dni;
    char *nombre;
    int brevete;
    Faltas lfaltas[100];
    int cantfaltas;
    
public:
    Conductor();
    Conductor(const Conductor& orig);
    virtual ~Conductor();
    void SetCantfaltas(int cantfaltas);
    int GetCantfaltas() const;
    void SetBrevete(int brevete);
    int GetBrevete() const;
    void SetNombre(char* nombre);
    void GetNombre(char *nombre) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void insfaltas(const Faltas &f); //Si se pasa por referencia ya no entra
    void operator + (const Faltas &);// al constructor copia, sin & ingresa al copia
    float operator ++ (int); //Obtener las multas
};

#endif /* CONDUCTOR_H */

