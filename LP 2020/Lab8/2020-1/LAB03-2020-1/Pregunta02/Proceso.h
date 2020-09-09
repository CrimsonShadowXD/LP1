
/* 
 * File:   Proceso.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 3 de julio de 2020, 09:49
 */
#include "Miembro.h"

#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
private:
    Miembro mi;

public:
    Proceso();  
    virtual ~Proceso();
    
    void leemiembro(char *entrada);
    void imprimemiembro(char *entradaA, char *entradaP);


};

#endif /* PROCESO_H */

