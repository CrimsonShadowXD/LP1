/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faltante.h
 * Author: Author: Alexis Johan Andres Avelino Campos 20155470
 *
 * Created on 10 de diciembre de 2019, 10:30 AM
 */
#include <fstream>

using namespace std;
#ifndef FALTANTE_H
#define FALTANTE_H

class Faltante {
public:
    void SetCantidadFaltante(double cantidadFaltante);
    double GetCantidadFaltante() const;
    void SetCodigoPedido(int codigoPedido);
    int GetCodigoPedido() const;
    
    void operator =(Faltante&fal);
    
private:
    int codigoPedido;
    double cantidadFaltante;
};

#endif /* FALTANTE_H */

