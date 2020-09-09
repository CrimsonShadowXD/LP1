/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: cueva
 *
 * Created on 1 de julio de 2020, 12:47 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetNombre(char* );
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char *nombre;
    
};

#endif /* ALUMNO_H */

