
/* 
 * File:   ACurso.h
 * Author: Rodrigo Agama    Codigo: 20151460
 *
 * Created on 26 de junio de 2020, 08:03
 */
#include "Curso.h"
#include <fstream>

using namespace std;

#ifndef ACURSO_H
#define ACURSO_H

class ACurso {
private:
    int codigo;
    Curso clcurso;
    char operacion;
public:
    ACurso();
    ACurso(const ACurso& orig);
    virtual ~ACurso();
    void SetOperacion(char operacion);
    char GetOperacion() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    Curso GetCurso();
    void SetCurso(Curso &entrada);


};

ifstream& operator>>(ifstream &in, ACurso& nuevo);

#endif /* ACURSO_H */

