

/* 
 * File:   EntidadReguladora.h
 * Author: Rodrigo
 *
 * Created on 8 de diciembre de 2019, 05:53 PM
 */

#include "ListaConductores.h"
#include "Infraccion.h"
#include "ListaDoble.h"
#include <fstream>

using namespace std;

#ifndef ENTIDADREGULADORA_H
#define ENTIDADREGULADORA_H

class EntidadReguladora {
public:
    EntidadReguladora();
    virtual ~EntidadReguladora();    
    procesarDatos();
private:
    ListaConductores conductores;
    ListaDoble<Infraccion> infracciones;
};

#endif /* ENTIDADREGULADORA_H */

