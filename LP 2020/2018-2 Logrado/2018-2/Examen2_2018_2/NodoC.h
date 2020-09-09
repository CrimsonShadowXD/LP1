

/* 
 * File:   NodoC.h
 * Author: Rodrigo
 *
 * Created on 7 de diciembre de 2019, 02:29 PM
 */

#include "Conductor.h"


#ifndef NODOC_H
#define NODOC_H

class NodoC {
public:
    NodoC();
    virtual ~NodoC();
private:
    Conductor elem;
    NodoC *sig;
    NodoC *ant;
    friend class ListaConductores;
};

#endif /* NODOC_H */

