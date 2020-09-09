/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nacional.h
 * Author: cueva
 *
 * Created on 1 de julio de 2020, 12:55 PM
 */

#ifndef NACIONAL_H
#define NACIONAL_H
#include "Alumno.h"

class Nacional:public Alumno {
public:
    Nacional();
    Nacional(const Nacional& orig);
    virtual ~Nacional();
    void SetFacultad(char* );
    void GetFacultad(char *) const;
    void SetEspecialidad(char* );
    void GetEspecialidad(char *) const;
private:
    char    *especialidad;
    char    *facultad;
};

#endif /* NACIONAL_H */

