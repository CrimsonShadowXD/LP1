
/* 
 * File:   BaseAlum.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 6 de julio de 2020, 18:24
 */
#include <fstream>

using namespace std;

#ifndef BASEALUM_H
#define BASEALUM_H

class BaseAlum {
private:
    int codigo;
    char *nombre;

public:
    BaseAlum();
    virtual ~BaseAlum();
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void imprimir(ofstream &out) = 0;
    virtual void leer(ifstream &in)=0;
    virtual char getTipo()=0;


};

#endif /* BASEALUM_H */

