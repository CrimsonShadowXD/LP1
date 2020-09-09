
/* 
 * File:   Curso.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 08:02
 */
#include <fstream>

using namespace std;

#ifndef CURSO_H
#define CURSO_H

class Curso {
private:
    char *ccurso; //Codigo.
    int ciclo;
    int nota;
    float credito;
public:
    Curso();    
    Curso(const Curso &orig);
    virtual ~Curso();
    
    void SetCredito(float credito);
    float GetCredito() const;
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCcurso(char* ccurso);
    char* GetCcurso() const;
    
    void operator=(const Curso entrada);
    void asignar(Curso entrada);        
    
    bool compare(const Curso &entrada);
    bool operator==(const Curso &entrada);

};


#endif /* CURSO_H */

