/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contenedor.h
 * Author: cueva
 *
 * Created on 1 de julio de 2020, 01:04 PM
 */

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

class contenedor {
public:
    void lee();
    void imprime();
    contenedor();
    contenedor(const contenedor& orig);
    virtual ~contenedor();
private:
    Nacional    *lnaci;
    Intercambio *linte;
};

#endif /* CONTENEDOR_H */

