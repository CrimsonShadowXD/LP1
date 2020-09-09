
/* 
 * File:   AlRegular.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 6 de julio de 2020, 18:24
 */
#include "BaseAlum.h"
#include <fstream>

using namespace std;

#ifndef ALREGULAR_H
#define ALREGULAR_H

class AlRegular: public BaseAlum {
private:
    char *especialidad;
    char *facultad;

public:
    AlRegular();
    virtual ~AlRegular();
    void SetFacultad(char* facultad);
    char* GetFacultad() const;
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad() const;
    
    void imprimir(ofstream &out);
    void leer(ifstream &in);
    char getTipo();


};

#endif /* ALREGULAR_H */

