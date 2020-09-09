/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltas.h
 * Author: cueva
 *
 * Created on 24 de junio de 2020, 12:22 PM
 */

#ifndef FALTAS_H
#define FALTAS_H

class Faltas {
private:
    int dni;
    int codigo;  // crear otra clase para estos 2 atributos
    float   multa; // crear otra clase para estos 2 atributos
    
public:
    Faltas();
    Faltas(const Faltas& orig);
    virtual ~Faltas();
    void SetMulta(float multa);
    float GetMulta() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetDni(int dni);
    int GetDni() const;
    
    Faltas operator = (const Faltas &);
    
};

#endif /* FALTAS_H */

