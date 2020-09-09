
/* 
 * File:   Persona.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 3 de julio de 2020, 08:05
 */
#include <fstream>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    char* nombre;
    int codigo;
    char* distrito;
public:
    Persona();
    Persona(const Persona &orig);
    virtual ~Persona();
    void SetDistrito(char* distrito);
    char* GetDistrito() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    
    void leer(ifstream &in);


};

#endif /* PERSONA_H */

