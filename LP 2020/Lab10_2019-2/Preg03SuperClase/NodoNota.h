
/* 
 * File:   NodoNota.h
 * Author: Rodrigo Agama
 *
 * Created on 5 de julio de 2020, 14:46
 */
#include "Nota.h"

#ifndef NODONOTA_H
#define NODONOTA_H

class NodoNota {
private:
    Nota elem;
    NodoNota* sig;

public:
    NodoNota();
    virtual ~NodoNota();

    friend class ListaNotas;
};

#endif /* NODONOTA_H */

