
/* 
 * File:   Nota.h
 * Author: Rodrigo Agama
 *
 * Created on 5 de julio de 2020, 14:46
 */
#include <fstream>

using namespace std;

#ifndef NOTA_H
#define NOTA_H

class Nota {
private:
    char* codigo;
    int nota;
    char* semestre;
public:
    Nota();    
    virtual ~Nota();
    void SetSemestre(char* semestre);
    char* GetSemestre() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
    
    void imprimir(ofstream &out);

};

#endif /* NOTA_H */

