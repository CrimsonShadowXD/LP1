/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Intercambio.h
 * Author: cueva
 *
 * Created on 1 de julio de 2020, 12:58 PM
 */

#ifndef INTERCAMBIO_H
#define INTERCAMBIO_H
#include "Alumno.h"

class Intercambio:public Alumno {
public:
    Intercambio();
    Intercambio(const Intercambio& orig);
    virtual ~Intercambio();
    void SetTiempo(int tiempo);
    int GetTiempo() const;
    void SetIdioma(char *);
    void GetIdioma(char *) const;
    void SetPais(char *);
    void GetPais(char *) const;
private:
    char    *pais;
    char    *idioma;
    int     tiempo;
};

#endif /* INTERCAMBIO_H */

